#include "ReposicaoObserver.h"
#include "Estoque.h"
#include "Financeiro.h"
#include "Reposicao.h"
#include "Produto.h"
#include <iostream>
#include <string>

ReposicaoObserver::ReposicaoObserver(Estoque* estoque, Financeiro* financeiro,
                                     GerenciadorReposicao* reposicoes, int qtdReposicao)
    : estoque(estoque), financeiro(financeiro),
      reposicoes(reposicoes), qtdReposicao(qtdReposicao) {}

// Se a venda deixou o estoque no minimo, gera a reposicao,
// repoe o estoque e lanca a despesa da compra.
void ReposicaoObserver::atualizar(const Venda& venda) {
    Produto* p = venda.produto;

    if (p->getQuantidade() > p->getEstoqueMinimo()) return;

    Reposicao r = reposicoes->gerar(p->getId(), p->getNome(),
                                    qtdReposicao, p->getPrecoCusto());
    estoque->repor(p->getId(), qtdReposicao);

    std::cout << "    [Observer-Reposicao]  reposicao gerada (Pedido #" << r.id
              << "): " << p->getNome() << " +" << r.quantidade
              << " un -> estoque agora com " << p->getQuantidade() << " un\n";

    financeiro->registrarDespesa("Reposicao #" + std::to_string(r.id)
                                 + " - " + p->getNome(), r.custoTotal);
    std::cout << "    [Observer-Reposicao]  despesa: -R$ " << r.custoTotal << "\n";
}
