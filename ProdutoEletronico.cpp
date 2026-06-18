#include "ProdutoEletronico.h"

ProdutoEletronico::ProdutoEletronico(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, int garantiaMeses)
            : Produto(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo),
            garantiaMeses(garantiaMeses)
            {}

int ProdutoEletronico::getGarantiaMeses() const{
    return garantiaMeses;
}

// Identifica o tipo do produto.
std::string ProdutoEletronico::getTipo() const{
    return "eletronico";
}
