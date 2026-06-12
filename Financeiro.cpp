#include "Financeiro.h"
#include <iostream>

// Guarda a receita como valor positivo.
void Financeiro::registrarReceita(const std::string& descricao, double valor) {
    movimentacoes.push_back({descricao, valor});
}

// Guarda a despesa como valor negativo (por isso o -valor).
void Financeiro::registrarDespesa(const std::string& descricao, double valor) {
    movimentacoes.push_back({descricao, -valor});
}

// Saldo = soma de todas as movimentacoes (positivas e negativas).
double Financeiro::saldo() {
    double total = 0.0;
    for (const Movimentacao& m : movimentacoes) {
        total += m.valor;
    }
    return total;
}

// Relatorio do caixa: separa receitas de despesas e mostra o lucro.
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
            // m.valor e' negativo; mostro o modulo com sinal de menos.
            std::cout << "    " << m.descricao << " ... -R$ " << (-m.valor) << "\n";
            totalDespesas += (-m.valor);
        }
    }
    std::cout << "    Total despesas .......... -R$ " << totalDespesas << "\n\n";

    std::cout << "  LUCRO LIQUIDO: .......... R$ " << saldo() << "\n";
    std::cout << "  =============================================\n";
}
