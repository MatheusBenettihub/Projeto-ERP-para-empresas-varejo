#ifndef CENTRALDEVENDAS_H
#define CENTRALDEVENDAS_H

#include <vector>

class ObservadorVenda;  // forward declaration (so usamos ponteiro)
struct Venda;

// =====================================================================
//  CentralDeVendas  (o "Sujeito"/Subject do padrao OBSERVER)
//  Guarda a lista de observadores inscritos e, quando uma venda
//  acontece, avisa TODOS eles chamando atualizar(). A central nao sabe
//  o que cada observador faz - so dispara o aviso. Isso desacopla os
//  setores: para adicionar um novo setor que reage a vendas, basta
//  inscreve-lo aqui, sem mexer no resto do codigo.
// =====================================================================
class CentralDeVendas {
private:
    std::vector<ObservadorVenda*> observadores;  // quem quer ser avisado

public:
    // Inscreve um observador para receber os avisos de venda.
    void inscrever(ObservadorVenda* obs);

    // Avisa todos os observadores que uma venda aconteceu.
    void notificar(const Venda& venda);
};

#endif
