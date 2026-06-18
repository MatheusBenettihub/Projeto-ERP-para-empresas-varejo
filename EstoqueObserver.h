#ifndef ESTOQUEOBSERVER_H
#define ESTOQUEOBSERVER_H

#include "ObservadorVenda.h"

class Estoque;

// Observador que da baixa no estoque a cada venda.
class EstoqueObserver : public ObservadorVenda {
private:
    Estoque* estoque;

public:
    EstoqueObserver(Estoque* estoque);
    void atualizar(const Venda& venda) override;
};

#endif
