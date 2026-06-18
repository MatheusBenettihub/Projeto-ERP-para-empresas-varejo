#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

// =====================================================================
//  Produto
//  Representa um item vendido pela loja.
//  Por enquanto e' uma classe simples com os dados do produto.
//
//  [FACTORY METHOD] (padrao de CRIACAO - a ser adicionado depois)
//  Hoje o tipo do produto e' apenas um texto ("Eletronico",
//  "Perecivel", "Comum"). Quando o padrao Factory for aplicado,
//  Produto vira uma classe-base e cada tipo vira uma subclasse
//  (ProdutoEletronico com garantia, ProdutoPerecivel com validade,
//  etc.). Uma classe ProdutoFactory ficaria responsavel por criar o
//  objeto certo a partir do tipo, sem que o resto do codigo precise
//  conhecer a subclasse concreta. Isso favorece o principio
//  Open/Closed do SOLID: para adicionar um novo tipo de produto,
//  bastaria criar uma nova subclasse, sem alterar o codigo existente.
// =====================================================================
class Produto {
protected:
    int id;                 // codigo unico do produto
    std::string nome;       // nome exibido
    double precoCusto;      // quanto a loja paga ao fornecedor (reposicao)
    double precoVenda;      // quanto o cliente paga
    int quantidade;         // unidades atualmente em estoque
    int estoqueMinimo;      // quando chega nesse valor, dispara reposicao

    public:
    // Construtor: recebe todos os dados do produto de uma vez.
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

    // Texto curto "Nome (Tipo)" usado nas impressoes.
    std::string descricao() const;

    virtual std::string getTipo() const = 0;
};



#endif
