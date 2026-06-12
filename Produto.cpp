#include "Produto.h"

// Construtor: apenas guarda os valores recebidos nos atributos.
Produto::Produto(int id, const std::string& nome, const std::string& tipo,
                 double precoCusto, double precoVenda,
                 int quantidade, int estoqueMinimo)
    : id(id), nome(nome), tipo(tipo),
      precoCusto(precoCusto), precoVenda(precoVenda),
      quantidade(quantidade), estoqueMinimo(estoqueMinimo) {}

// Monta um texto do tipo "Celular Samsung (Eletronico)".
std::string Produto::descricao() const {
    return nome + " (" + tipo + ")";
}
