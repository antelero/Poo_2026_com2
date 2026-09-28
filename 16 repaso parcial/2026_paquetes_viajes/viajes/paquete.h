#ifndef PAQUETE_H
#define PAQUETE_H

#include "servicio.h"
#include <vector>

class Paquete: public Servicio{

private:
    vector<Servicio*> componentes;

public:

    Paquete(int numero,string descripcion);

    void agregar(Servicio *s);

    float calcularPrecio() const override;

    vector<Servicio*> getComponentes();

    friend ostream& operator<<(ostream& os, const Paquete& p);

};

#endif
