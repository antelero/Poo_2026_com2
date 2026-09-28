#ifndef SERVICIO_H
#define SERVICIO_H

#include <iostream>
#include <string>
using namespace std;

class Servicio{
protected:
    int numero;
    string descripcion;

public:
    Servicio(int numero,string descripcion);

    virtual float calcularPrecio() const = 0;
    int getNumero();
    string getDescripcion() const;
    virtual ~Servicio(){}

    friend ostream& operator<<(ostream& os, const Servicio& s);
};

#endif
