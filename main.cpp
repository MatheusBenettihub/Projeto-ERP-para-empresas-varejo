#include <iostream>
#include <iomanip>
#include <vector>
#include "ERP.h"

// Exibe o menu principal do sistema.
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
    // Valores monetarios sempre com duas casas decimais.
    std::cout << std::fixed << std::setprecision(2);

    ERP erp;
    int opcao = -1;

    // Loop principal do menu, encerra na opcao 0.
    while (opcao != 0) {
        mostrarMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                // Le os itens do pedido (ID e quantidade de cada um).
                int n;
                std::cout << "\n  Quantos itens no pedido? ";
                std::cin >> n;

                std::vector<ItemPedido> itens;
                for (int i = 0; i < n; i++) {
                    ItemPedido item;
                    std::cout << "  Item " << (i + 1) << " - Produto (ID): ";
                    std::cin >> item.idProduto;
                    std::cout << "  Item " << (i + 1) << " - Quantidade : ";
                    std::cin >> item.quantidade;
                    itens.push_back(item);
                }

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
