#include "Reposicao.h"
#include <iostream>

// Cria um pedido de reposicao, guarda no historico e o retorna.
Reposicao GerenciadorReposicao::gerar(int idProduto, const std::string& nomeProduto,
                                      int quantidade, double custoUnitario) {
    Reposicao r;
    r.id = proximoId++;
    r.idProduto = idProduto;
    r.nomeProduto = nomeProduto;
    r.quantidade = quantidade;
    r.custoTotal = quantidade * custoUnitario;

    pedidos.push_back(r);
    return r;
}

// Lista os pedidos de reposicao ja gerados.
void GerenciadorReposicao::listar() {
    std::cout << "\n  ============ PEDIDOS DE REPOSICAO ============\n";
    if (pedidos.empty()) {
        std::cout << "  (nenhum pedido de reposicao gerado ate agora)\n";
    } else {
        for (const Reposicao& r : pedidos) {
            std::cout << "  Pedido #" << r.id
                      << " | " << r.nomeProduto
                      << " | " << r.quantidade << " un"
                      << " | custo: R$ " << r.custoTotal << "\n";
        }
    }
    std::cout << "  ==============================================\n";
}
