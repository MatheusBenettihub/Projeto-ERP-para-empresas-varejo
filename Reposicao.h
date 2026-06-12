#ifndef REPOSICAO_H
#define REPOSICAO_H

#include <vector>
#include <string>

// Dados de um pedido de reposicao gerado automaticamente quando o
// estoque de um produto fica no minimo ou abaixo.
struct Reposicao {
    int id;                 // numero do pedido de reposicao
    int idProduto;          // produto que foi reposto
    std::string nomeProduto;
    int quantidade;         // quantas unidades foram compradas
    double custoTotal;      // quanto custou (quantidade * custo unitario)
};

// =====================================================================
//  GerenciadorReposicao (parte do setor de compras)
//  Cria e guarda os pedidos de reposicao.
// =====================================================================
class GerenciadorReposicao {
private:
    std::vector<Reposicao> pedidos;  // historico de reposicoes
    int proximoId = 1;               // contador para numerar os pedidos

public:
    // Cria um novo pedido de reposicao, guarda no historico e o devolve
    // para quem chamou (para imprimir / registrar a despesa).
    Reposicao gerar(int idProduto, const std::string& nomeProduto,
                    int quantidade, double custoUnitario);

    // Lista todos os pedidos de reposicao ja gerados (opcao do menu).
    void listar();
};

#endif
