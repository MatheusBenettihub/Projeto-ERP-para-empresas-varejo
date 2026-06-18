#include "Estoque.h"
#include "ProdutoFactory.h"
#include <iostream>

// Construtor do Estoque: cadastra os produtos iniciais da loja.
//
// [FACTORY METHOD] Cada linha abaixo cria um Produto direto. Quando o
// padrao Factory for aplicado, estas criacoes passariam por uma
// ProdutoFactory::criar("Eletronico", ...), que devolveria a subclasse
// certa ja pronta. Mantemos os dados aqui para ficar facil de trocar.
Estoque::Estoque() {
    //                 id, nome,                tipo,         custo,  venda,  qtd, minimo
    produtos.push_back(ProdutoFactory::criarEletronico(1, "Celular Samsung", 800.0, 1200.0, 10, 2, 12));
    produtos.push_back(ProdutoFactory::criarPerecivel(2, "Perfume Importado", 120.0,  280.0,  5, 3, "16/06/2027"));
    produtos.push_back(ProdutoFactory::criarComum(3, "Caderno", 8.0,   18.0, 30, 5));
    produtos.push_back(ProdutoFactory::criarEletronico(4, "Fone Bluetooth", 90.0,  200.0,  4, 2, 12));
    produtos.push_back(ProdutoFactory::criarPerecivel(5, "Chocolate",  5.0,   12.0,  8, 4, "22/06/2026"));
}

Estoque::~Estoque(){
    for(Produto* p : produtos){
        delete p;
    }
}

// Percorre a lista procurando o produto com o ID pedido.
Produto* Estoque::buscar(int id) {
    for (Produto* p : produtos) {
        if (p->getId() == id) {
            return p;  // devolve o endereco para quem chamou poder alterar
        }
    }
    return nullptr;     // nao encontrou
}

// Verifica se ha unidades suficientes para vender.
bool Estoque::temDisponibilidade(int id, int qtd) {
    Produto* p = buscar(id);
    if (p == nullptr) return false;     // produto nem existe
    return p->getQuantidade() >= qtd;        // tem o suficiente?
}

// Diminui o estoque (venda).
void Estoque::baixar(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->setQuantidade(p->getQuantidade() - qtd);
    }
}

// Aumenta o estoque (chegada de reposicao).
void Estoque::repor(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->setQuantidade(p->getQuantidade() + qtd);
    }
}

// Mostra a tabela de estoque com o status de cada produto.
void Estoque::listar() {
    std::cout << "\n  ================ ESTOQUE =================\n";
    std::cout << "  ID  | Produto             | Qtd | Min | Status\n";
    std::cout << "  ----|---------------------|-----|-----|--------\n";
    for (Produto* p : produtos) {
        // Decide o status a partir da quantidade atual.
        std::string status;
        if (p->getQuantidade() == 0)               status = "ZERADO";
        else if (p->getQuantidade() <= p->getEstoqueMinimo()) status = "BAIXO";
        else                                 status = "OK";

        // printf deixa as colunas alinhadas de forma simples.
        printf("  %-3d | %-19s | %3d | %3d | %s\n",
               p->getId(), p->getNome().c_str(), p->getQuantidade(), p->getEstoqueMinimo(), status.c_str());
    }
    std::cout << "  ==========================================\n";
}
