#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>
#include "examen.h"

class Alumno
{
private:
    long dni;
    char * nom_ape;

    //Examen
    Examen ex;

public:

    Alumno( long dni, char * nom_ape, Examen ex);
    long getDni() const;
    char *getNom_ape() const;

    //Método abstracto
    virtual bool estaAprobado() = 0;
    virtual float calcularNotaFinal() = 0;
    float getNota();
};

#endif // ALUMNO_H
