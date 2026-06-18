#include "ERP.h"
#include <iostream>


#include "Estoque.h"
#include "Financeiro.h"
#include "Reposicao.h"

// =====================================================================
//  ERP.cpp  -  implementacao da Facade
//
//  Cada metodo publico desta classe coordena chamadas aos subsistemas
//  internos (Estoque, Financeiro, GerenciadorReposicao). O cliente
//  (main.cpp) chama um unico metodo do ERP e a Facade se encarrega
//  de acionar os subsistemas na ordem e com os parametros corretos.
// =====================================================================


ERP::ERP()
    : estoque(std::make_unique<Estoque>()),
      financeiro(std::make_unique<Financeiro>()),
      reposicoes(std::make_unique<GerenciadorReposicao>()) {}


ERP::~ERP() = default;

// ---------------------------------------------------------------------
//  registrarPedido  [Facade]
//  Orquestra os tres subsistemas para processar um pedido do site:
//    1. Estoque     - verifica disponibilidade e da baixa nas unidades;
//    2. Financeiro  - registra a receita da venda (e despesa de reposi-
//                    cao, se necessario);
//    3. GerenciadorReposicao - gera pedido de compra quando o estoque
//                    fica no minimo.
//  O main.cpp entrega os itens e recebe o resultado impresso na tela,
//  sem precisar conhecer nenhum dos tres subsistemas.
// ---------------------------------------------------------------------
void ERP::registrarPedido(const std::vector<ItemPedido>& itens) {
    int numeroPedido = proximoPedido++;

    std::cout << "\n  ==========================================\n";
    std::cout << "  [VENDAS] Pedido #" << numeroPedido << " recebido do site\n";
    std::cout << "  ==========================================\n";

    double totalDoPedido = 0.0;  // soma das vendas aceitas neste pedido

    // Processa item por item do pedido.
    for (size_t i = 0; i < itens.size(); i++) {
        int id  = itens[i].idProduto;
        int qtd = itens[i].quantidade;

        Produto* p = estoque->buscar(id);

        // 1) Produto nao existe no catalogo.
        if (p == nullptr) {
            std::cout << "\n  Item " << (i + 1)
                      << ": produto ID " << id << " nao existe. Ignorado.\n";
            continue;
        }

        // 2) Nao ha estoque suficiente -> recusa o item.
        if (!estoque->temDisponibilidade(id, qtd)) {
            std::cout << "\n  Item " << (i + 1) << ": " << p->nome << "\n";
            std::cout << "    [VENDA RECUSADA] solicitado " << qtd
                      << ", disponivel " << p->quantidade << "\n";
            continue;
        }

        // 3) Venda aceita.
        int antes = p->quantidade;
        double totalItem = qtd * p->precoVenda;
        totalDoPedido += totalItem;

        std::cout << "\n  Item " << (i + 1) << ": " << p->descricao()
                  << " x" << qtd << " = R$ " << totalItem << "\n";

        // -------------------------------------------------------------
        // [OBSERVER] (padrao COMPORTAMENTAL - a ser adicionado depois)
        // Aqui o ERP avisa "na mao" cada setor sobre a venda: primeiro o
        // estoque, depois o financeiro. Com o padrao Observer, a venda
        // seria um EVENTO e os setores (Estoque, Financeiro) seriam
        // OBSERVADORES inscritos que reagem sozinhos quando o evento
        // acontece - o ERP nao precisaria chamar cada um manualmente.
        // Isso desacopla os setores (eles nao dependem uns dos outros).
        // -------------------------------------------------------------

        // ---- avisa o ESTOQUE (da baixa) ----
        estoque->baixar(id, qtd);
        std::cout << "    [Estoque]    " << p->nome << ": "
                  << antes << " -> " << p->quantidade << " un";
        if (p->quantidade <= p->estoqueMinimo)
            std::cout << "  (ATENCAO: no minimo!)";
        std::cout << "\n";

        // ---- avisa o FINANCEIRO (registra receita) ----
        financeiro->registrarReceita("Venda #" + std::to_string(numeroPedido)
                                    + " - " + p->nome, totalItem);
        std::cout << "    [Financeiro] receita: +R$ " << totalItem << "\n";

        // 4) Se o estoque ficou no minimo (ou abaixo), o setor de
        //    compras gera uma reposicao automatica e ela ja' chega.
        if (p->quantidade <= p->estoqueMinimo) {
            Reposicao r = reposicoes->gerar(id, p->nome, QTD_REPOSICAO, p->precoCusto);
            estoque->repor(id, QTD_REPOSICAO);  // a mercadoria chega e repoe o estoque

            std::cout << "\n    [COMPRAS] Reposicao automatica gerada (Pedido #"
                      << r.id << ")\n";
            std::cout << "      Produto    : " << p->nome << "\n";
            std::cout << "      Quantidade : " << r.quantidade << " un\n";
            std::cout << "      Custo      : R$ " << r.custoTotal << "\n";
            std::cout << "      Estoque    : reposto para " << p->quantidade << " un\n";

            // A reposicao e' uma despesa para o financeiro.
            financeiro->registrarDespesa("Reposicao #" + std::to_string(r.id)
                                        + " - " + p->nome, r.custoTotal);
            std::cout << "      [Financeiro] despesa: -R$ " << r.custoTotal << "\n";
        }
    }

    // Mini-relatorio final do pedido.
    std::cout << "\n  ------------- RESUMO DO PEDIDO -------------\n";
    std::cout << "    Total vendido neste pedido . R$ " << totalDoPedido << "\n";
    std::cout << "    Saldo atual do caixa ....... R$ " << financeiro->saldo() << "\n";
    std::cout << "  ==========================================\n";
}

// Opcao 2 [Facade]: delega para o subsistema Estoque imprimir sua tabela.
void ERP::consultarEstoque() {
    estoque->listar();
}

// Opcao 3 [Facade]: delega para o subsistema GerenciadorReposicao listar os pedidos.
void ERP::verReposicoes() {
    reposicoes->listar();
}

// Opcao 4 [Facade]: delega para o subsistema Financeiro imprimir o caixa.
void ERP::verCaixa() {
    financeiro->relatorio();
}
