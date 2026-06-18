#include "Estoque.h"
#include "ProdutoFactory.h"
#include <iostream>

// Cadastra os produtos iniciais da loja via fabrica.
Estoque::Estoque() {
    produtos.push_back(ProdutoFactory::criarEletronico(1, "Celular Samsung", 800.0, 1200.0, 10, 2, 12));
    produtos.push_back(ProdutoFactory::criarPerecivel(2, "Perfume Importado", 120.0,  280.0,  5, 3, "16/06/2027"));
    produtos.push_back(ProdutoFactory::criarComum(3, "Caderno", 8.0,   18.0, 30, 5));
    produtos.push_back(ProdutoFactory::criarEletronico(4, "Fone Bluetooth", 90.0,  200.0,  4, 2, 12));
    produtos.push_back(ProdutoFactory::criarPerecivel(5, "Chocolate",  5.0,   12.0,  8, 4, "22/06/2026"));
}

// Libera os produtos alocados dinamicamente.
Estoque::~Estoque(){
    for(Produto* p : produtos){
        delete p;
    }
}

// Retorna o produto com o ID informado, ou nullptr se nao existir.
Produto* Estoque::buscar(int id) {
    for (Produto* p : produtos) {
        if (p->getId() == id) {
            return p;
        }
    }
    return nullptr;
}

// Verifica se ha quantidade suficiente para uma venda.
bool Estoque::temDisponibilidade(int id, int qtd) {
    Produto* p = buscar(id);
    if (p == nullptr) return false;
    return p->getQuantidade() >= qtd;
}

// Baixa o estoque (venda).
void Estoque::baixar(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->setQuantidade(p->getQuantidade() - qtd);
    }
}

// Aumenta o estoque (reposicao).
void Estoque::repor(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->setQuantidade(p->getQuantidade() + qtd);
    }
}

// Imprime a tabela de estoque com o status de cada produto.
void Estoque::listar() {
    std::cout << "\n  ================ ESTOQUE =================\n";
    std::cout << "  ID  | Produto             | Qtd | Min | Status\n";
    std::cout << "  ----|---------------------|-----|-----|--------\n";
    for (Produto* p : produtos) {
        std::string status;
        if (p->getQuantidade() == 0)               status = "ZERADO";
        else if (p->getQuantidade() <= p->getEstoqueMinimo()) status = "BAIXO";
        else                                 status = "OK";

        printf("  %-3d | %-19s | %3d | %3d | %s\n",
               p->getId(), p->getNome().c_str(), p->getQuantidade(), p->getEstoqueMinimo(), status.c_str());
    }
    std::cout << "  ==========================================\n";
}
