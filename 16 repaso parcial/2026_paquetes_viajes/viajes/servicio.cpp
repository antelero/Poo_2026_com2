#include "servicio.h"
#include "vuelo.h"
#include "hotel.h"
#include "excursion.h"
#include "paquete.h"

Servicio::Servicio(int numero, string descripcion){
    this->numero=numero;
    this->descripcion=descripcion;
}


int Servicio::getNumero(){
    return numero;
}

string Servicio::getDescripcion()const{
    return descripcion;
}

ostream& operator<<(ostream& os, const Servicio& s)
{
    if(auto v = dynamic_cast<const Vuelo*>(&s))
        return os << *v;

    if(auto h = dynamic_cast<const Hotel*>(&s))
        return os << *h;

    if(auto e = dynamic_cast<const Excursion*>(&s))
        return os << *e;

    if(auto p = dynamic_cast<const Paquete*>(&s))
        return os << *p;

    return os;
}
