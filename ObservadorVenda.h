#ifndef OBSERVADORVENDA_H
#define OBSERVADORVENDA_H

#include "Venda.h"

// Interface dos observadores de venda.
class ObservadorVenda {
public:
    virtual ~ObservadorVenda() = default;
    virtual void atualizar(const Venda& venda) = 0;
};

#endif
