#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include "Produto.h"

// Setor de estoque: cadastro de produtos, baixa, reposicao e consulta.
class Estoque {
private:
    std::vector<Produto*> produtos;

public:
    Estoque();
    ~Estoque();

    Produto* buscar(int id);
    bool temDisponibilidade(int id, int qtd);
    void baixar(int id, int qtd);
    void repor(int id, int qtd);
    void listar();
};

#endif
