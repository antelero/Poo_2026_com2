#ifndef DISCO_H
#define DISCO_H
#include "cancion.h"

class Disco
{
private:
    char nombreDisco[20];
    int cant=0;
    Cancion ** canciones = new Cancion*[0];
public:
    Disco(char nombreDisco[]);
    int getCant() const;
    char * getNombreDisco();

    void addCancion(Cancion * can);
    Cancion * getCancion(int i);

    double getDuracion();
};

#endif // DISCO_H
