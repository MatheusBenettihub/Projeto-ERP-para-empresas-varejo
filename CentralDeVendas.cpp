#include "CentralDeVendas.h"
#include "ObservadorVenda.h"

// Inscreve um observador para receber as notificacoes de venda.
void CentralDeVendas::inscrever(ObservadorVenda* obs) {
    observadores.push_back(obs);
}

// Avisa todos os observadores inscritos que uma venda ocorreu.
void CentralDeVendas::notificar(const Venda& venda) {
    for (ObservadorVenda* obs : observadores) {
        obs->atualizar(venda);
    }
}
