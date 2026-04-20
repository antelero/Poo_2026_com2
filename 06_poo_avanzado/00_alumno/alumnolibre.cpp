#include "alumnolibre.h"

AlumnoLibre::AlumnoLibre(long dni, char nomApe[], int notaExamen, int NotaLibre): Alumno(dni, nomApe)
{
    this->notaExamen = notaExamen;
    this->notaLibre = NotaLibre;
}

char AlumnoLibre::getCondicion()
{
    if (this->notaExamen>=60 && this->notaLibre >= 50)
        return 'A';
    else return 'R';
}
