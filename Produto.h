#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

// Classe base de produto. Cada tipo concreto (eletronico, perecivel,
// comum) e criado pela ProdutoFactory.
class Produto {
protected:
    int id;
    std::string nome;
    double precoCusto;
    double precoVenda;
    int quantidade;
    int estoqueMinimo;

public:
    Produto(int id, const std::string& nome,
            double precoCusto, double precoVenda,
            int quantidade, int estoqueMinimo);
    virtual ~Produto() = default;

    void setQuantidade(int qtd);
    int getId() const;
    std::string getNome() const;
    double getPrecoCusto() const;
    double getPrecoVenda() const;
    int getQuantidade() const;
    int getEstoqueMinimo() const;

    std::string descricao() const;

    virtual std::string getTipo() const = 0;
};

#endif
