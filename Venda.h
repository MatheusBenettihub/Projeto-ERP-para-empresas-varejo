#ifndef VENDA_H
#define VENDA_H

class Produto;  // so' precisamos do ponteiro, nao dos detalhes do Produto

// =====================================================================
//  Venda
//  Representa o EVENTO "uma venda aconteceu". E' so um pacote de dados
//  que a CentralDeVendas envia para os observadores (Estoque e
//  Financeiro) quando notifica a venda.
// =====================================================================
struct Venda {
    Produto* produto;     // qual produto foi vendido
    int quantidade;       // quantas unidades
    double total;         // valor total da venda (quantidade * preco)
    int numeroPedido;     // numero do pedido (usado nas descricoes)
};

#endif
