#ifndef PRODUTOCOMUM_H
#define PRODUTOCOMUM_H

#include "Produto.h"

class ProdutoComum : public Produto{
    public:
        ProdutoComum(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo);

        std::string getTipo() const override;
};

#endif
