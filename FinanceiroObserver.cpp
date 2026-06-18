#include "FinanceiroObserver.h"
#include "Financeiro.h"
#include "Produto.h"
#include <iostream>
#include <string>

// Recebe e guarda o ponteiro para o setor financeiro.
FinanceiroObserver::FinanceiroObserver(Financeiro* financeiro) : financeiro(financeiro) {}

// Quando a venda e' notificada, o financeiro registra a receita.
void FinanceiroObserver::atualizar(const Venda& venda) {
    Produto* p = venda.produto;

    financeiro->registrarReceita("Venda #" + std::to_string(venda.numeroPedido)
                                 + " - " + p->getNome(), venda.total);

    std::cout << "    [Observer-Financeiro] receita: +R$ " << venda.total << "\n";
}
