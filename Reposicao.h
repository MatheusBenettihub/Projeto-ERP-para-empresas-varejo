#ifndef REPOSICAO_H
#define REPOSICAO_H

#include <vector>
#include <string>

// Pedido de reposicao gerado quando o estoque atinge o minimo.
struct Reposicao {
    int id;
    int idProduto;
    std::string nomeProduto;
    int quantidade;
    double custoTotal;
};

// Setor de compras: cria e armazena os pedidos de reposicao.
class GerenciadorReposicao {
private:
    std::vector<Reposicao> pedidos;
    int proximoId = 1;

public:
    Reposicao gerar(int idProduto, const std::string& nomeProduto,
                    int quantidade, double custoUnitario);
    void listar();
};

#endif
