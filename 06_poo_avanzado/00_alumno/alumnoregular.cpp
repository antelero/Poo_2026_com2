#include "alumnoregular.h"

AlumnoRegular::AlumnoRegular(long dni, char nomApe[], int notaExamen) : Alumno (dni, nomApe)
{
    this->notaExamen = notaExamen;
}

char AlumnoRegular::getCondicion()
{
    if (this->notaExamen>=60)
        return 'A';
    else return 'R';
}
