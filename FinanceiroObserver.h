#ifndef FINANCEIROOBSERVER_H
#define FINANCEIROOBSERVER_H

#include "ObservadorVenda.h"

class Financeiro;

// Observador que registra a receita da venda no caixa.
class FinanceiroObserver : public ObservadorVenda {
private:
    Financeiro* financeiro;

public:
    FinanceiroObserver(Financeiro* financeiro);
    void atualizar(const Venda& venda) override;
};

#endif
