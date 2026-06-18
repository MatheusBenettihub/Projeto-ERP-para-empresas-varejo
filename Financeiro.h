#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <vector>
#include <string>

// Movimentacao de caixa: valor positivo = receita, negativo = despesa.
struct Movimentacao {
    std::string descricao;
    double valor;
};

// Setor financeiro: registra movimentacoes e calcula o saldo.
class Financeiro {
private:
    std::vector<Movimentacao> movimentacoes;

public:
    void registrarReceita(const std::string& descricao, double valor);
    void registrarDespesa(const std::string& descricao, double valor);
    double saldo();
    void relatorio();
};

#endif
