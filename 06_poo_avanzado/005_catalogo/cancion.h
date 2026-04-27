#ifndef CANCION_H
#define CANCION_H
#include "autor.h"


class Cancion
{
private:
    char nombreCancion[20];
    Autor * aut;
    double duracion;
public:
    Cancion(char nombreCancion[],Autor * aut,double duracion);

    double getDuracion() const;
    Autor *getAut() const;
    char * getNombreCancion();
};

#endif // CANCION_H
