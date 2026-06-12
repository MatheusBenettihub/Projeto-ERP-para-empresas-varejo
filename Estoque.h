#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include "Produto.h"

// =====================================================================
//  Estoque (setor de estoque da empresa)
//  Guarda a lista de produtos e cuida de:
//   - buscar um produto pelo ID;
//   - verificar se ha quantidade disponivel para uma venda;
//   - dar baixa (venda) e repor (reposicao) unidades;
//   - listar o estoque na tela.
// =====================================================================
class Estoque {
private:
    std::vector<Produto> produtos;  // todos os produtos da loja

public:
    // O construtor ja cadastra os produtos iniciais da loja (seed).
    Estoque();

    // Procura um produto pelo ID. Retorna o endereco do produto
    // encontrado ou nullptr se nao existir.
    //
    // [FACTORY METHOD] Os produtos sao criados aqui dentro do
    // construtor (ver Estoque.cpp). E' exatamente nesse ponto que a
    // ProdutoFactory entraria: em vez de "new/emplace" direto, o codigo
    // chamaria ProdutoFactory::criar(tipo, ...) para devolver a
    // subclasse correta.
    Produto* buscar(int id);

    // Retorna true se houver pelo menos 'qtd' unidades do produto.
    bool temDisponibilidade(int id, int qtd);

    // Reduz o estoque do produto (usado quando ha uma venda).
    void baixar(int id, int qtd);

    // Aumenta o estoque do produto (usado quando chega uma reposicao).
    void repor(int id, int qtd);

    // Imprime a tabela de estoque (opcao "Consultar estoque" do menu).
    void listar();
};

#endif
