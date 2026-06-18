#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H

#include "Produto.h"

class ProdutoEletronico : public Produto{
        private:
            int garantiaMeses; //garantia do produto em meses
        public:
            ProdutoEletronico(int id, const std::string& nome, double precoCusto,
            double precoVenda, int quantidade, int estoqueMinimo, int garantiaMeses); 

        int getGarantiaMeses() const;
        std::string getTipo() const override;

};

#endif