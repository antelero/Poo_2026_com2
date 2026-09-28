#include "parte.h"

Parte::Parte(int n, const char* d, double p) : Item(n, d)
{
    this->precio = p;
}

double Parte::getPrecio() const {
    return this->precio;
}
