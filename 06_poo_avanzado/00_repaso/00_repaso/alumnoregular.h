#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H
#include <cstdio>
#include "alumno.h"

class AlumnoRegular : public Alumno
{
public:

    AlumnoRegular( int d, char *nom, Examen ex);
    bool estaAprobado();
    float calcularNotaFinal();
    char *mostrar();
};

#endif // ALUMNOREGULAR_H
