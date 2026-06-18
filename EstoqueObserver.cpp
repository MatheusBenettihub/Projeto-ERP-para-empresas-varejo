#include "EstoqueObserver.h"
#include "Estoque.h"
#include "Produto.h"
#include <iostream>

EstoqueObserver::EstoqueObserver(Estoque* estoque) : estoque(estoque) {}

// Da baixa no estoque do produto vendido.
void EstoqueObserver::atualizar(const Venda& venda) {
    Produto* p = venda.produto;

    int antes = p->getQuantidade();
    estoque->baixar(p->getId(), venda.quantidade);

    std::cout << "    [Observer-Estoque]    " << p->getNome() << ": "
              << antes << " -> " << p->getQuantidade() << " un";
    if (p->getQuantidade() <= p->getEstoqueMinimo())
        std::cout << "  (ATENCAO: no minimo!)";
    std::cout << "\n";
}
