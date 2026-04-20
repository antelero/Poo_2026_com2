#ifndef ALUMNO_H
#define ALUMNO_H
#include <cstring>

class Alumno
{
private:
    long dni;
    char nomApe[20];
public:
    Alumno(long dni, char nomApe[20]);
    const char * getNomApe();
    long getDni() const;

    //Metodo abstracto
    virtual char getCondicion()=0;
};

#endif // ALUMNO_H
