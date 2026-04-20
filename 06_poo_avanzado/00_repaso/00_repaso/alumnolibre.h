#ifndef ALUMNOLIBRE_H
#define ALUMNOLIBRE_H
#include <cstdio>
#include "alumno.h"

class AlumnoLibre : public Alumno
{
public:
    AlumnoLibre( int d, char *nom, Examen ex);
    bool estaAprobado();
    float calcularNotaFinal();
    char *mostrar();
};

#endif // ALUMNOLIBRE_H
