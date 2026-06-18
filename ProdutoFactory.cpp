#include "ProdutoFactory.h"

//cria produtos comuns
Produto* ProdutoFactory::criarComum(int id, const std::string& nome,
        double precoCusto, double precoVenda, int quantidade, int estoqueMinimo)
        {
            return new ProdutoComum(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo);
}

//cria produtos eletronicos
Produto* ProdutoFactory::criarEletronico(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, int garantiaMeses){
                return new ProdutoEletronico(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo, garantiaMeses);
}

//cria produtos pereciveis
Produto* ProdutoFactory::criarPerecivel(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, const std::string& validade){
                return new ProdutoPerecivel(id, nome, precoCusto, precoVenda, quantidade, estoqueMinimo, validade);
            }
