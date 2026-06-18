#include "EstoqueObserver.h"
#include "Estoque.h"
#include "Produto.h"
#include <iostream>

// Recebe e guarda o ponteiro para o setor de estoque.
EstoqueObserver::EstoqueObserver(Estoque* estoque) : estoque(estoque) {}

// Quando a venda e' notificada, o estoque da baixa nas unidades.
void EstoqueObserver::atualizar(const Venda& venda) {
    Produto* p = venda.produto;

    int antes = p->getQuantidade();
    estoque->baixar(p->getId(), venda.quantidade);  // tira do estoque

    std::cout << "    [Observer-Estoque]    " << p->getNome() << ": "
              << antes << " -> " << p->getQuantidade() << " un";
    if (p->getQuantidade() <= p->getEstoqueMinimo())
        std::cout << "  (ATENCAO: no minimo!)";
    std::cout << "\n";
}
