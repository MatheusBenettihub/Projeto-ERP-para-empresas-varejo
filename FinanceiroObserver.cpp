#include "FinanceiroObserver.h"
#include "Financeiro.h"
#include "Produto.h"
#include <iostream>
#include <string>

FinanceiroObserver::FinanceiroObserver(Financeiro* financeiro) : financeiro(financeiro) {}

// Registra a receita da venda no caixa.
void FinanceiroObserver::atualizar(const Venda& venda) {
    Produto* p = venda.produto;

    financeiro->registrarReceita("Venda #" + std::to_string(venda.numeroPedido)
                                 + " - " + p->getNome(), venda.total);

    std::cout << "    [Observer-Financeiro] receita: +R$ " << venda.total << "\n";
}
