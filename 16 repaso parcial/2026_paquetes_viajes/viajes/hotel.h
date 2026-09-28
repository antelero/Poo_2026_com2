#ifndef HOTEL_H
#define HOTEL_H

#include "servicio.h"

class Hotel: public Servicio{

private:
    int noches;

public:

    Hotel(int numero,string descripcion,int noc);

    float calcularPrecio() const override;

    int getNoches() const;
    friend ostream& operator<<(ostream& os, const Hotel& e);
};

#endif
