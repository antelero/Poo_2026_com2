#ifndef ALUMNOLIBRE_H
#define ALUMNOLIBRE_H

#include "alumno.h"

class AlumnoLibre : public Alumno
{
private:
    int notaExamen;
    int notaLibre;
public:
    AlumnoLibre(long dni, char nomApe[], int notaExamen, int NotaLibre);

    char getCondicion();
};

#endif // ALUMNOLIBRE_H
