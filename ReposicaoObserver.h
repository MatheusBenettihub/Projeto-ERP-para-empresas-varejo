#ifndef REPOSICAOOBSERVER_H
#define REPOSICAOOBSERVER_H

#include "ObservadorVenda.h"

class Estoque;
class Financeiro;
class GerenciadorReposicao;

// Observador que gera a reposicao automatica quando o estoque
// atinge o minimo apos uma venda. Depende de o EstoqueObserver
// ter dado baixa antes, por isso e inscrito depois dele.
class ReposicaoObserver : public ObservadorVenda {
private:
    Estoque*              estoque;
    Financeiro*           financeiro;
    GerenciadorReposicao* reposicoes;
    int                   qtdReposicao;

public:
    ReposicaoObserver(Estoque* estoque, Financeiro* financeiro,
                      GerenciadorReposicao* reposicoes, int qtdReposicao);
    void atualizar(const Venda& venda) override;
};

#endif
