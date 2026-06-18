#ifndef ESTOQUEOBSERVER_H
#define ESTOQUEOBSERVER_H

#include "ObservadorVenda.h"

class Estoque;  // forward declaration

// =====================================================================
//  EstoqueObserver  (observador concreto do padrao OBSERVER)
//  E' o setor de estoque "ouvindo" as vendas. Quando uma venda
//  acontece, ele da baixa nas unidades vendidas. Ele guarda apenas um
//  ponteiro para o Estoque (nao e' dono dele - quem cria e destroi o
//  Estoque e o ERP).
// =====================================================================
class EstoqueObserver : public ObservadorVenda {
private:
    Estoque* estoque;  // setor que sera atualizado

public:
    EstoqueObserver(Estoque* estoque);

    // Reacao do estoque quando uma venda e' notificada.
    void atualizar(const Venda& venda) override;
};

#endif
