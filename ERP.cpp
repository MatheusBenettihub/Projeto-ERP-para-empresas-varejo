#include "ERP.h"
#include <iostream>

#include "Estoque.h"
#include "Financeiro.h"
#include "Reposicao.h"
#include "Produto.h"
#include "CentralDeVendas.h"
#include "EstoqueObserver.h"
#include "FinanceiroObserver.h"
#include "ReposicaoObserver.h"
#include "Venda.h"

const int ERP::QTD_REPOSICAO;

ERP::ERP()
    : estoque(std::make_unique<Estoque>()),
      financeiro(std::make_unique<Financeiro>()),
      reposicoes(std::make_unique<GerenciadorReposicao>()),
      central(std::make_unique<CentralDeVendas>()),
      estoqueObs(std::make_unique<EstoqueObserver>(estoque.get())),
      financeiroObs(std::make_unique<FinanceiroObserver>(financeiro.get())),
      reposicaoObs(std::make_unique<ReposicaoObserver>(
          estoque.get(), financeiro.get(), reposicoes.get(), QTD_REPOSICAO)) {

    // Ordem importa: o estoque baixa antes de a reposicao checar o minimo.
    central->inscrever(estoqueObs.get());
    central->inscrever(financeiroObs.get());
    central->inscrever(reposicaoObs.get());
}

ERP::~ERP() = default;

void ERP::registrarPedido(const std::vector<ItemPedido>& itens) {
    int numeroPedido = proximoPedido++;

    std::cout << "\n  ==========================================\n";
    std::cout << "  [VENDAS] Pedido #" << numeroPedido << " recebido do site\n";
    std::cout << "  ==========================================\n";

    double totalDoPedido = 0.0;

    for (size_t i = 0; i < itens.size(); i++) {
        int id  = itens[i].idProduto;
        int qtd = itens[i].quantidade;

        Produto* p = estoque->buscar(id);

        if (p == nullptr) {
            std::cout << "\n  Item " << (i + 1)
                      << ": produto ID " << id << " nao existe. Ignorado.\n";
            continue;
        }

        if (!estoque->temDisponibilidade(id, qtd)) {
            std::cout << "\n  Item " << (i + 1) << ": " << p->getNome() << "\n";
            std::cout << "    [VENDA RECUSADA] solicitado " << qtd
                      << ", disponivel " << p->getQuantidade() << "\n";
            continue;
        }

        double totalItem = qtd * p->getPrecoVenda();
        totalDoPedido += totalItem;

        std::cout << "\n  Item " << (i + 1) << ": " << p->descricao()
                  << " x" << qtd << " = R$ " << totalItem << "\n";

        // Notifica a venda; estoque, financeiro e reposicao reagem.
        Venda venda;
        venda.produto      = p;
        venda.quantidade   = qtd;
        venda.total        = totalItem;
        venda.numeroPedido = numeroPedido;

        central->notificar(venda);
    }

    std::cout << "\n  ------------- RESUMO DO PEDIDO -------------\n";
    std::cout << "    Total vendido neste pedido . R$ " << totalDoPedido << "\n";
    std::cout << "    Saldo atual do caixa ....... R$ " << financeiro->saldo() << "\n";
    std::cout << "  ==========================================\n";
}

void ERP::consultarEstoque() {
    estoque->listar();
}

void ERP::verReposicoes() {
    reposicoes->listar();
}

void ERP::verCaixa() {
    financeiro->relatorio();
}
