#ifndef ERP_H
#define ERP_H

#include <vector>
#include <memory>

class Estoque;
class Financeiro;
class GerenciadorReposicao;
class CentralDeVendas;
class EstoqueObserver;
class FinanceiroObserver;
class ReposicaoObserver;

struct ItemPedido {
    int idProduto;
    int quantidade;
};

// Fachada do sistema: unifica estoque, financeiro e reposicao
// atras de uma interface unica usada pelo menu.
class ERP {
private:
    std::unique_ptr<Estoque>              estoque;
    std::unique_ptr<Financeiro>           financeiro;
    std::unique_ptr<GerenciadorReposicao> reposicoes;

    std::unique_ptr<CentralDeVendas>    central;
    std::unique_ptr<EstoqueObserver>    estoqueObs;
    std::unique_ptr<FinanceiroObserver> financeiroObs;
    std::unique_ptr<ReposicaoObserver>  reposicaoObs;

    int proximoPedido = 1;
    static const int QTD_REPOSICAO = 10;

public:
    ERP();
    ~ERP();

    void registrarPedido(const std::vector<ItemPedido>& itens);
    void consultarEstoque();
    void verReposicoes();
    void verCaixa();
};

#endif
