#ifndef OBSERVADORVENDA_H
#define OBSERVADORVENDA_H

#include "Venda.h"

// =====================================================================
//  ObservadorVenda  (interface do padrao OBSERVER)
//  E' a "regra" que todo setor interessado em vendas precisa seguir:
//  ter um metodo atualizar() que sera chamado quando uma venda
//  acontecer. Estoque e Financeiro implementam essa interface.
//
//  E' uma classe abstrata pura (so tem metodo virtual puro), por isso
//  nao pode ser instanciada sozinha - serve apenas como contrato.
// =====================================================================
class ObservadorVenda {
public:
    virtual ~ObservadorVenda() = default;

    // Chamado pela CentralDeVendas para cada observador quando ha venda.
    virtual void atualizar(const Venda& venda) = 0;
};

#endif
