#ifndef ERP_H
#define ERP_H

#include <vector>
#include "Estoque.h"
#include "Financeiro.h"
#include "Reposicao.h"

// Um item dentro de um pedido do site: qual produto e quantas unidades.
// O 'main' monta uma lista desses itens lendo o terminal e entrega ao ERP.
struct ItemPedido {
    int idProduto;
    int quantidade;
};

// =====================================================================
//  ERP  -  classe central do sistema
//
//  [FACADE] (padrao ESTRUTURAL - a ser formalizado depois)
//  Esta classe ja' funciona como uma "fachada": ela junta os tres
//  setores (Estoque, Financeiro e Compras/Reposicao) e oferece poucos
//  metodos simples para o 'main'. O 'main' NUNCA fala direto com
//  Estoque ou Financeiro - so' com o ERP. Quando o padrao Facade for
//  documentado no relatorio, e' exatamente este o papel que ele cumpre:
//  esconder a complexidade dos subsistemas atras de uma interface unica.
// =====================================================================
class ERP {
private:
    Estoque estoque;                    // setor de estoque
    Financeiro financeiro;              // setor financeiro / caixa
    GerenciadorReposicao reposicoes;    // setor de compras (reposicao)
    int proximoPedido = 1;              // numero do proximo pedido do site

    // Quantas unidades sao compradas em cada reposicao automatica.
    static const int QTD_REPOSICAO = 10;

public:
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
