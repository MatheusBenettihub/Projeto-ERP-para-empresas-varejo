#ifndef PRODUTOFACTORY_H
#define PRODUTOFACTORY_H

#include "Produto.h"
#include "ProdutoComum.h"
#include "ProdutoEletronico.h"
#include "ProdutoPerecivel.h"

// Fabrica de produtos: cria a subclasse correta conforme o tipo.
class ProdutoFactory{
    public:
        static Produto* criarComum(int id, const std::string& nome,
        double precoCusto, double precoVenda, int quantidade, int estoqueMinimo);

        static Produto* criarEletronico(int id, const std::string& nome,
        double precoCusto, double precoVenda, int quantidade, int estoqueMinimo, int garantiaMeses);

        static Produto* criarPerecivel(int id, const std::string& nome,
        double precoCusto, double precoVenda, int quantidade, int estoqueMinimo, const std::string& validade);
};

#endif
