#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <vector>
#include <string>

// Uma movimentacao de dinheiro no caixa.
// valor positivo  = receita (entrou dinheiro - venda)
// valor negativo  = despesa (saiu dinheiro  - reposicao)
struct Movimentacao {
    std::string descricao;
    double valor;
};

// =====================================================================
//  Financeiro (setor financeiro / caixa)
//  Guarda todas as entradas e saidas de dinheiro e calcula o saldo.
// =====================================================================
class Financeiro {
private:
    std::vector<Movimentacao> movimentacoes;  // historico do caixa

public:
    // Registra uma entrada de dinheiro (venda).
    void registrarReceita(const std::string& descricao, double valor);

    // Registra uma saida de dinheiro (compra/reposicao).
    void registrarDespesa(const std::string& descricao, double valor);

    // Soma de tudo: receitas - despesas.
    double saldo();

    // Imprime o relatorio do caixa (opcao "Caixa" do menu).
    void relatorio();
};

#endif
