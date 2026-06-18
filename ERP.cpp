#include "ERP.h"
#include <iostream>


#include "Estoque.h"
#include "Financeiro.h"
#include "Reposicao.h"
#include "Produto.h"

// [OBSERVER] cabecalhos da central e dos observadores
#include "CentralDeVendas.h"
#include "EstoqueObserver.h"
#include "FinanceiroObserver.h"
#include "Venda.h"

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
      reposicoes(std::make_unique<GerenciadorReposicao>()),
      // [OBSERVER] cria a central e os dois observadores. Cada observador
      // recebe um ponteiro "cru" (.get()) para o setor que vai atualizar.
      central(std::make_unique<CentralDeVendas>()),
      estoqueObs(std::make_unique<EstoqueObserver>(estoque.get())),
      financeiroObs(std::make_unique<FinanceiroObserver>(financeiro.get())) {

    // [OBSERVER] inscreve os dois setores na central de vendas. A partir
    // daqui, toda venda notificada avisa estoque e financeiro sozinhos.
    central->inscrever(estoqueObs.get());
    central->inscrever(financeiroObs.get());
}


ERP::~ERP() = default;

// ---------------------------------------------------------------------
//  registrarPedido  [Facade]
//  Orquestra os tres subsistemas para processar um pedido do site:
//    1. Estoque     - verifica disponibilidade e da baixa nas unidades;
//    2. Financeiro  - registra a receita da venda (e despesa de reposi-
//                    cao, se necessario);
//    3. GerenciadorReposicao - gera pedido de compra quando o estoque
//                    fica no minimo.
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
            std::cout << "\n  Item " << (i + 1) << ": " << p->getNome() << "\n";
            std::cout << "    [VENDA RECUSADA] solicitado " << qtd
                      << ", disponivel " << p->getQuantidade() << "\n";
            continue;
        }

        // 3) Venda aceita.
        double totalItem = qtd * p->getPrecoVenda();
        totalDoPedido += totalItem;

        std::cout << "\n  Item " << (i + 1) << ": " << p->descricao()
                  << " x" << qtd << " = R$ " << totalItem << "\n";

        // -------------------------------------------------------------
        // [OBSERVER] em acao.
        // Em vez de o ERP chamar estoque e financeiro "na mao", ele so
        // monta o EVENTO de venda e manda a CentralDeVendas notificar.
        // A central avisa os observadores inscritos (EstoqueObserver e
        // FinanceiroObserver) e cada um reage sozinho: o estoque da
        // baixa e o financeiro registra a receita. O ERP nao precisa
        // saber quem esta inscrito nem o que cada setor faz.
        // -------------------------------------------------------------
        Venda venda;
        venda.produto      = p;
        venda.quantidade   = qtd;
        venda.total        = totalItem;
        venda.numeroPedido = numeroPedido;

        central->notificar(venda);  // estoque e financeiro reagem aqui

        // 4) Se o estoque ficou no minimo (ou abaixo), o setor de
        //    compras gera uma reposicao automatica e ela ja' chega.
        if (p->getQuantidade() <= p->getEstoqueMinimo()) {
            Reposicao r = reposicoes->gerar(id, p->getNome(), QTD_REPOSICAO, p->getPrecoCusto());
            estoque->repor(id, QTD_REPOSICAO);  // a mercadoria chega e repoe o estoque

            std::cout << "\n    [COMPRAS] Reposicao automatica gerada (Pedido #"
                      << r.id << ")\n";
            std::cout << "      Produto    : " << p->getNome() << "\n";
            std::cout << "      Quantidade : " << r.quantidade << " un\n";
            std::cout << "      Custo      : R$ " << r.custoTotal << "\n";
            std::cout << "      Estoque    : reposto para " << p->getQuantidade() << " un\n";

            // A reposicao e' uma despesa para o financeiro.
            financeiro->registrarDespesa("Reposicao #" + std::to_string(r.id)
                                        + " - " + p->getNome(), r.custoTotal);
            std::cout << "      [Financeiro] despesa: -R$ " << r.custoTotal << "\n";
        }
    }

    // Mini-relatorio final do pedido.
    std::cout << "\n  ------------- RESUMO DO PEDIDO -------------\n";
    std::cout << "    Total vendido neste pedido . R$ " << totalDoPedido << "\n";
    std::cout << "    Saldo atual do caixa ....... R$ " << financeiro->saldo() << "\n";
    std::cout << "  ==========================================\n";
}

// Opcao 2 delega para o subsistema Estoque imprimir sua tabela.
void ERP::consultarEstoque() {
    estoque->listar();
}

// Opcao 3 delega para o subsistema GerenciadorReposicao listar os pedidos.
void ERP::verReposicoes() {
    reposicoes->listar();
}

// Opcao 4 delega para o subsistema Financeiro imprimir o caixa.
void ERP::verCaixa() {
    financeiro->relatorio();
}
