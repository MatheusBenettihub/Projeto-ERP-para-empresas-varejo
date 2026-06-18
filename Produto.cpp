#include "Produto.h"

// Construtor: apenas guarda os valores recebidos nos atributos.
Produto::Produto(int id, const std::string& nome,
                 double precoCusto, double precoVenda,
                 int quantidade, int estoqueMinimo)
                : id(id), nome(nome), precoCusto(precoCusto), 
                precoVenda(precoVenda), quantidade(quantidade), 
                estoqueMinimo(estoqueMinimo) {}

void Produto::setQuantidade(int qtd){
    quantidade = qtd;
}

int Produto::getId() const{
    return id;
}

std::string Produto::getNome() const{
    return nome;
}

double Produto::getPrecoCusto() const{
    return precoCusto;
}

double Produto::getPrecoVenda() const{
    return precoVenda;
}

int Produto::getQuantidade() const{
    return quantidade;
}

int Produto::getEstoqueMinimo() const{
    return estoqueMinimo;
}

// Monta um texto do tipo "Celular Samsung (Eletronico)".
std::string Produto::descricao() const {
        return nome + "(" + getTipo() + ")";
}
