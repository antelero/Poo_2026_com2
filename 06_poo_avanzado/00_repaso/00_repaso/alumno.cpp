#include "alumno.h"

long Alumno::getDni() const
{
    return dni;
}

char *Alumno::getNom_ape() const
{
    return nom_ape;
}

float Alumno::getNota() {
    return ex.getNota();
}


Alumno::Alumno(long dni, char *nom_ape, Examen ex)
{
    this->ex = ex;
    this->dni = dni;
    this->nom_ape = new char[strlen(nom_ape)+1];
    strcpy(this->nom_ape,nom_ape);
}
