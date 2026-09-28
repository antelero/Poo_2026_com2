#include "excursion.h"

int Excursion::getDias() const
{
    return dias;
}

Excursion::Excursion(int numero,string descripcion, int dia):
    Servicio( numero, descripcion){
    dias=dia;
}

float Excursion::calcularPrecio() const{
    return dias*2000;
}

ostream& operator<<(ostream& os, const Excursion& e)
{
    os << "Excursion: " << e.descripcion
       << " | Dias: " << e.dias
       << " | $" << e.calcularPrecio()
       << endl;

    return os;
}
