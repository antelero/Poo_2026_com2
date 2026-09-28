#include "hotel.h"

int Hotel::getNoches() const
{
    return noches;
}

Hotel::Hotel(int numero,string descripcion, int noc):
    Servicio(numero, descripcion){
    noches=noc;
}

float Hotel::calcularPrecio() const{
    return noches*5000;
}
ostream& operator<<(ostream& os, const Hotel& h)
{
    os << "Hotel: " << h.descripcion
       << " | Noches: " << h.noches
       << " | $" << h.calcularPrecio()
       << endl;

    return os;
}
