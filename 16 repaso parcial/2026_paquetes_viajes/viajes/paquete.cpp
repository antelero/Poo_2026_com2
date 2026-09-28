#include "paquete.h"

Paquete::Paquete(int numero,string descripcion):Servicio( numero, descripcion){}

void Paquete::agregar(Servicio *s){
    componentes.push_back(s);
}

float Paquete::calcularPrecio() const{

    float total=0;

    for(auto s:componentes)
        total+=s->calcularPrecio();

    return total;
}

vector<Servicio *> Paquete::getComponentes(){
    return componentes;
}

ostream& operator<<(ostream& os, const Paquete& p)
{
    os << "\nPaquete " << p.descripcion << endl;

    for(auto s : p.componentes)
        os << *s;

    os << "TOTAL: $" << p.calcularPrecio() << endl;

    return os;
}
