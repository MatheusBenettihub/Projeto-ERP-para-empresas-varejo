#include "CentralDeVendas.h"
#include "ObservadorVenda.h"

// Adiciona o observador na lista de quem sera avisado.
void CentralDeVendas::inscrever(ObservadorVenda* obs) {
    observadores.push_back(obs);
}

// Percorre todos os observadores inscritos e chama atualizar() em cada
// um. Cada observador reage do seu jeito (estoque baixa, financeiro
// registra receita), sem a central precisar saber os detalhes.
void CentralDeVendas::notificar(const Venda& venda) {
    for (ObservadorVenda* obs : observadores) {
        obs->atualizar(venda);
    }
}
