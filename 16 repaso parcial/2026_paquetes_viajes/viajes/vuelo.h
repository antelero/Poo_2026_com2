#ifndef VUELO_H
#define VUELO_H

#include "servicio.h"

class Vuelo: public Servicio{

private:
    int kilometros;
    string origen;
    string destino;

public:

    Vuelo(int numero,string descripcion,int km,string orig,string des);

    float calcularPrecio() const override;

    string getOrigen() const;



    int getKilometros() const;
    const string &getDestino() const;

    friend ostream& operator<<(ostream& os, const Vuelo& e);
};

#endif
