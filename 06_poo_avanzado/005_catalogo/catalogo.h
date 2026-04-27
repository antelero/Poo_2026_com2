#ifndef CATALOGO_H
#define CATALOGO_H
#include "disco.h"

class Catalogo
{
private:
    char nombreCata[20];
    int cant = 0;
    Disco ** discos = new Disco*[0];
public:
    Catalogo(char nombreCata[]);
    int getCant() const;
    char * getNombreCatalogo();

    void addDisco(Disco * dis);
    Disco * getDisco(int i);

    double getDuracion();
};

#endif // CATALOGO_H
