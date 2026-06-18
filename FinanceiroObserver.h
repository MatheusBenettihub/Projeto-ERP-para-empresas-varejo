#ifndef FINANCEIROOBSERVER_H
#define FINANCEIROOBSERVER_H

#include "ObservadorVenda.h"

class Financeiro;  // forward declaration

// =====================================================================
//  FinanceiroObserver  (observador concreto do padrao OBSERVER)
//  E' o setor financeiro "ouvindo" as vendas. Quando uma venda
//  acontece, ele registra a receita no caixa. Guarda apenas um ponteiro
//  para o Financeiro (nao e' dono dele).
// =====================================================================
class FinanceiroObserver : public ObservadorVenda {
private:
    Financeiro* financeiro;  // setor que sera atualizado

public:
    FinanceiroObserver(Financeiro* financeiro);

    // Reacao do financeiro quando uma venda e' notificada.
    void atualizar(const Venda& venda) override;
};

#endif
