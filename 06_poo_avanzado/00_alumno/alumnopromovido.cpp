#include "alumnopromovido.h"

AlumnoPromovido::AlumnoPromovido(long dni, char nomApe[]) : Alumno (dni, nomApe)
{

}

char AlumnoPromovido::getCondicion()
{
    return 'A';
}
