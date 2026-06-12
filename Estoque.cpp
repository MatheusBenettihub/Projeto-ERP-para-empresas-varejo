#include "Estoque.h"
#include <iostream>

// Construtor do Estoque: cadastra os produtos iniciais da loja.
//
// [FACTORY METHOD] Cada linha abaixo cria um Produto direto. Quando o
// padrao Factory for aplicado, estas criacoes passariam por uma
// ProdutoFactory::criar("Eletronico", ...), que devolveria a subclasse
// certa ja pronta. Mantemos os dados aqui para ficar facil de trocar.
Estoque::Estoque() {
    //                 id, nome,                tipo,         custo,  venda,  qtd, minimo
    produtos.push_back(Produto(1, "Celular Samsung",   "Eletronico",  800.0, 1200.0, 10, 2));
    produtos.push_back(Produto(2, "Perfume Importado", "Perecivel",   120.0,  280.0,  5, 3));
    produtos.push_back(Produto(3, "Caderno",           "Comum",         8.0,   18.0, 30, 5));
    produtos.push_back(Produto(4, "Fone Bluetooth",    "Eletronico",   90.0,  200.0,  4, 2));
    produtos.push_back(Produto(5, "Chocolate",         "Perecivel",     5.0,   12.0,  8, 4));
}

// Percorre a lista procurando o produto com o ID pedido.
Produto* Estoque::buscar(int id) {
    for (Produto& p : produtos) {
        if (p.id == id) {
            return &p;  // devolve o endereco para quem chamou poder alterar
        }
    }
    return nullptr;     // nao encontrou
}

// Verifica se ha unidades suficientes para vender.
bool Estoque::temDisponibilidade(int id, int qtd) {
    Produto* p = buscar(id);
    if (p == nullptr) return false;     // produto nem existe
    return p->quantidade >= qtd;        // tem o suficiente?
}

// Diminui o estoque (venda).
void Estoque::baixar(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->quantidade -= qtd;
    }
}

// Aumenta o estoque (chegada de reposicao).
void Estoque::repor(int id, int qtd) {
    Produto* p = buscar(id);
    if (p != nullptr) {
        p->quantidade += qtd;
    }
}

// Mostra a tabela de estoque com o status de cada produto.
void Estoque::listar() {
    std::cout << "\n  ================ ESTOQUE =================\n";
    std::cout << "  ID  | Produto             | Qtd | Min | Status\n";
    std::cout << "  ----|---------------------|-----|-----|--------\n";
    for (Produto& p : produtos) {
        // Decide o status a partir da quantidade atual.
        std::string status;
        if (p.quantidade == 0)               status = "ZERADO";
        else if (p.quantidade <= p.estoqueMinimo) status = "BAIXO";
        else                                 status = "OK";

        // printf deixa as colunas alinhadas de forma simples.
        printf("  %-3d | %-19s | %3d | %3d | %s\n",
               p.id, p.nome.c_str(), p.quantidade, p.estoqueMinimo, status.c_str());
    }
    std::cout << "  ==========================================\n";
}
