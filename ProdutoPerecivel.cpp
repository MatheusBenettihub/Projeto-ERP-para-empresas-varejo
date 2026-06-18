#include "ProdutoPerecivel.h"

ProdutoPerecivel::ProdutoPerecivel(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, const std::string& validade)
            : Produto(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo),
            validade(validade){}

std::string ProdutoPerecivel::getValidade() const{
    return validade;
}

// Identifica o tipo do produto.
std::string ProdutoPerecivel::getTipo() const{
    return "perecivel";
}
