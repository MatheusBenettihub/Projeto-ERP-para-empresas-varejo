#ifndef CENTRALDEVENDAS_H
#define CENTRALDEVENDAS_H

#include <vector>

class ObservadorVenda;
struct Venda;

// Subject do padrao Observer: notifica os setores inscritos a cada venda.
class CentralDeVendas {
private:
    std::vector<ObservadorVenda*> observadores;

public:
    void inscrever(ObservadorVenda* obs);
    void notificar(const Venda& venda);
};

#endif
