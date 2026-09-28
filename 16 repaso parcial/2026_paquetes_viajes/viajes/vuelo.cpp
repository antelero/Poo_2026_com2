#include "vuelo.h"

int Vuelo::getKilometros() const
{
    return kilometros;
}

const string &Vuelo::getDestino() const
{
    return destino;
}

Vuelo::Vuelo(int numero,string descripcion, int km, string orig, string des):
    Servicio( numero, descripcion){
    kilometros=km;
    origen=orig;
    destino=des;
}

float Vuelo::calcularPrecio() const{
    return kilometros*1000;
}

string Vuelo::getOrigen() const {
    return origen;
}

ostream& operator<<(ostream& os, const Vuelo& v)
{
    os << "Vuelo: " << v.descripcion
       << " | " << v.origen
       << " -> " << v.destino
       << " | $" << v.calcularPrecio()
       << endl;

    return os;
}
