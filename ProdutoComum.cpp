#include "ProdutoComum.h"

ProdutoComum::ProdutoComum(
    int id, const std::string& nome, double precoCusto,
    double precoVenda, int quantidade, int estoqueMinimo
) : Produto(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo){}

std::string ProdutoComum::getTipo() const{
    return "comum";
}