#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>

class Alumno
{
private:
    long dni;
    char * nom_ape;

    //Notas
    /*int nota_1 = 0;
    int nota_2 = 0;*/

    int notas[2];
public:
    Alumno();
    Alumno( long dni, char * nom_ape);
    long getDni() const;
    char *getNom_ape() const;
    void setNota_1(int newNota_1);
    void setNota_2(int newNota_2);
    double getProm();
};

#endif // ALUMNO_H
