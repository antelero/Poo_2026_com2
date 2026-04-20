#include "materia.h"

int Materia::getCant() const
{
    return cant;
}

void Materia::addAlumno(Alumno *alu)
{
    Alumno ** aux = new Alumno*[cant+1];
    for (int i=0; i< this->cant; i++)
        aux[i]=this->alumnos[i];
    aux[cant] = alu;
    this->cant++;
    delete [] this->alumnos;
    this->alumnos = aux;
}

Alumno *Materia::getAlumno(int i)
{
    return this->alumnos[i];
}

Materia::Materia()
{

}
