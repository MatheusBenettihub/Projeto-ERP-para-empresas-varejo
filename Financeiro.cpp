#include "Financeiro.h"
#include <iostream>

// Registra uma entrada de caixa (valor positivo).
void Financeiro::registrarReceita(const std::string& descricao, double valor) {
    movimentacoes.push_back({descricao, valor});
}

// Registra uma saida de caixa (armazenada com sinal negativo).
void Financeiro::registrarDespesa(const std::string& descricao, double valor) {
    movimentacoes.push_back({descricao, -valor});
}

// Soma de todas as movimentacoes (receitas - despesas).
double Financeiro::saldo() {
    double total = 0.0;
    for (const Movimentacao& m : movimentacoes) {
        total += m.valor;
    }
    return total;
}

// Imprime o relatorio do caixa separando receitas e despesas.
void Financeiro::relatorio() {
    std::cout << "\n  =========== RELATORIO FINANCEIRO ============\n";

    double totalReceitas = 0.0;
    double totalDespesas = 0.0;

    std::cout << "  RECEITAS (vendas):\n";
    for (const Movimentacao& m : movimentacoes) {
        if (m.valor > 0) {
            std::cout << "    " << m.descricao << " ... +R$ " << m.valor << "\n";
            totalReceitas += m.valor;
        }
    }
    std::cout << "    Total receitas .......... +R$ " << totalReceitas << "\n\n";

    std::cout << "  DESPESAS (reposicoes):\n";
    for (const Movimentacao& m : movimentacoes) {
        if (m.valor < 0) {
            std::cout << "    " << m.descricao << " ... -R$ " << (-m.valor) << "\n";
            totalDespesas += (-m.valor);
        }
    }
    std::cout << "    Total despesas .......... -R$ " << totalDespesas << "\n\n";

    std::cout << "  LUCRO LIQUIDO: .......... R$ " << saldo() << "\n";
    std::cout << "  =============================================\n";
}
