#ifndef ALUMNOPROMOVIDO_H
#define ALUMNOPROMOVIDO_H

#include "alumno.h"

class AlumnoPromovido : public Alumno
{
public:
    AlumnoPromovido(long dni, char nomApe[]);

    char getCondicion();
};

#endif // ALUMNOPROMOVIDO_H
