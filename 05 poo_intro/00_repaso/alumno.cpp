#include "alumno.h"

long Alumno::getDni() const
{
    return dni;
}

char *Alumno::getNom_ape() const
{
    return nom_ape;
}

void Alumno::setNota_1(int newNota_1)
{
    //nota_1 = newNota_1;
    this->notas[0] = newNota_1;
}

void Alumno::setNota_2(int newNota_2)
{
    //nota_2 = newNota_2;
    this->notas[1] = newNota_2;
}

double Alumno::getProm()
{
    //return (this->nota_1 + this->nota_2) / 2.0;
    int acum = 0;
    for(int i=0; i<2;i++)
        acum+=notas[i];
    return acum / 2.0;
}
Alumno::Alumno()
{

}

Alumno::Alumno(long dni, char *nom_ape)
{
    this->dni = dni;
    this->nom_ape = new char[strlen(nom_ape)+1];
    strcpy(this->nom_ape,nom_ape);
}
