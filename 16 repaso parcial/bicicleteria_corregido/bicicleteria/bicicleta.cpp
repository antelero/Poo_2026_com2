#include "bicicleta.h"

Bicicleta::Bicicleta(int n, const char* d) : Item(n, d) {
}

void Bicicleta::agregarParte(Parte *np)
{
    partes.push_back(np);
}

double Bicicleta::getPrecio() const
{
    double total = 0;
    for (const Parte* p : partes)
        total += p->getPrecio();
    return total;
}

const std::vector<Parte*> &Bicicleta::getPartes() const
{
    return partes;
}
