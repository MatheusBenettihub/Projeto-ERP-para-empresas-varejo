#ifndef VENDA_H
#define VENDA_H

class Produto;

// Evento de venda enviado da CentralDeVendas aos observadores.
struct Venda {
    Produto* produto;
    int quantidade;
    double total;
    int numeroPedido;
};

#endif
