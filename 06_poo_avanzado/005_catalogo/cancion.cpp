#include "cancion.h"

Cancion::Cancion(char nombreCancion[],Autor * aut,double duracion)
{
    strcpy(this->nombreCancion, nombreCancion);
    this->aut = aut;
    this->duracion = duracion;
}

double Cancion::getDuracion() const
{
    return duracion;
}

Autor *Cancion::getAut() const
{
    return aut;
}

char *Cancion::getNombreCancion()
{
    return this->nombreCancion;
}



