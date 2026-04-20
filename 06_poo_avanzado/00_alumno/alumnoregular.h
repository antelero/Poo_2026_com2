#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H

#include "alumno.h"

class AlumnoRegular : public Alumno
{
private:
    int notaExamen;
public:
    AlumnoRegular(long dni, char nomApe[], int notaExamen);

    char getCondicion();
};

#endif // ALUMNOREGULAR_H
