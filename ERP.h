#ifndef ERP_H
#define ERP_H

#include <vector>
#include <memory>


class Estoque;
class Financeiro;
class GerenciadorReposicao;


struct ItemPedido {
    int idProduto;
    int quantidade;
};

// =====================================================================
//  FACADE aplicado:
//  Esta classe e' a "fachada" do sistema. Ela unifica tres subsistemas
//  independentes (Estoque, Financeiro e GerenciadorReposicao) atras de
//  uma interface simples de quatro metodos. O cliente (main.cpp) NUNCA
//  acessa os subsistemas diretamente - toda interacao passa pelo ERP.
// =====================================================================
class ERP {
private:
    std::unique_ptr<Estoque>              estoque;      // setor de estoque
    std::unique_ptr<Financeiro>           financeiro;   // setor financeiro / caixa
    std::unique_ptr<GerenciadorReposicao> reposicoes;   // setor de compras (reposicao)

    int proximoPedido = 1;              // numero do proximo pedido do site

    // Quantas unidades sao compradas em cada reposicao automatica.
    static const int QTD_REPOSICAO = 10;

public:
    ERP();  
    ~ERP();  

    // Opcao 1 do menu: processa um pedido vindo do site (varios itens).
    void registrarPedido(const std::vector<ItemPedido>& itens);

    // Opcao 2: mostra o estoque.
    void consultarEstoque();

    // Opcao 3: mostra os pedidos de reposicao gerados.
    void verReposicoes();

    // Opcao 4: mostra o caixa (receitas, despesas, lucro).
    void verCaixa();
};

#endif
