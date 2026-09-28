#ifndef EXCURSION_H
#define EXCURSION_H

#include "servicio.h"

class Excursion: public Servicio{

private:
    int dias;

public:

    Excursion(int numero,string descripcion,int dia);

    float calcularPrecio() const override;

    int getDias() const;

    friend ostream& operator<<(ostream& os, const Excursion& e);
};

#endif
