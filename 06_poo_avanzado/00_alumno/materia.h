#ifndef MATERIA_H
#define MATERIA_H
#include "alumno.h"

class Materia
{
private:
    int cant=0;
    Alumno ** alumnos = new Alumno*[0];
public:
    Materia();

    int getCant() const;
    void addAlumno(Alumno * alu);
    Alumno * getAlumno(int i);
};

#endif // MATERIA_H
