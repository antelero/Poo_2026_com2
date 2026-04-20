#include "alumno.h"

Alumno::Alumno(long dni, char nomApe[20])
{
    this->dni = dni;
    strcpy(this->nomApe, nomApe);
}

const char *Alumno::getNomApe()
{
    return this->nomApe;
}

long Alumno::getDni() const
{
    return dni;
}
