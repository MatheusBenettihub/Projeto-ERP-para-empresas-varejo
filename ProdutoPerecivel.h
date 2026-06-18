#ifndef PRODUTOPERECIVEL_H
#define PRODUTOPERECIVEL_H

#include "Produto.h"

class ProdutoPerecivel : public Produto{
    private:
        std::string validade;
    public:
        ProdutoPerecivel(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, const std::string& validade);

        std::string getValidade() const;
        std::string getTipo() const override;
};

#endif
