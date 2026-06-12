#include <iostream>
#include <iomanip>
#include <vector>
#include "ERP.h"


// Imprime o menu principal.
void mostrarMenu() {
    std::cout << "\n========================================\n";
    std::cout << "             ERP VAREJO\n";
    std::cout << "========================================\n";
    std::cout << "  1 - Registrar pedido do site\n";
    std::cout << "  2 - Consultar estoque\n";
    std::cout << "  3 - Pedidos de reposicao\n";
    std::cout << "  4 - Caixa\n";
    std::cout << "  0 - Sair\n";
    std::cout << "========================================\n";
    std::cout << "> ";
}

int main() {
    // Faz todos os valores de dinheiro aparecerem com 2 casas decimais.
    // (a configuracao vale para todas as impressoes seguintes)
    std::cout << std::fixed << std::setprecision(2);

    ERP erp;          // cria o sistema (ja' vem com os produtos no estoque)
    int opcao = -1;

    // Loop principal: repete o menu ate' o usuario escolher 0 (sair).
    while (opcao != 0) {
        mostrarMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                // Le quantos itens o pedido tera'.
                int n;
                std::cout << "\n  Quantos itens no pedido? ";
                std::cin >> n;

                // Para cada item, le o ID do produto e a quantidade.
                std::vector<ItemPedido> itens;
                for (int i = 0; i < n; i++) {
                    ItemPedido item;
                    std::cout << "  Item " << (i + 1) << " - Produto (ID): ";
                    std::cin >> item.idProduto;
                    std::cout << "  Item " << (i + 1) << " - Quantidade : ";
                    std::cin >> item.quantidade;
                    itens.push_back(item);
                }

                // Entrega o pedido pronto para o ERP processar.
                erp.registrarPedido(itens);
                break;
            }
            case 2:
                erp.consultarEstoque();
                break;
            case 3:
                erp.verReposicoes();
                break;
            case 4:
                erp.verCaixa();
                break;
            case 0:
                std::cout << "\nEncerrando o sistema...\n";
                break;
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n";
        }
    }

    return 0;
}
