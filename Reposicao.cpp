#include "Reposicao.h"
#include <iostream>

// Cria o pedido de reposicao, calcula o custo total, guarda e devolve.
Reposicao GerenciadorReposicao::gerar(int idProduto, const std::string& nomeProduto,
                                      int quantidade, double custoUnitario) {
    Reposicao r;
    r.id = proximoId++;                         // numera e ja avanca o contador
    r.idProduto = idProduto;
    r.nomeProduto = nomeProduto;
    r.quantidade = quantidade;
    r.custoTotal = quantidade * custoUnitario;  // custo da compra

    pedidos.push_back(r);                        // guarda no historico
    return r;                                    // devolve para impressao/financeiro
}

// Mostra todos os pedidos de reposicao ja gerados.
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
