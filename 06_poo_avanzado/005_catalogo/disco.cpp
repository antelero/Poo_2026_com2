#include "disco.h"

Disco::Disco(char nombreDisco[])
{
    strcpy(this->nombreDisco, nombreDisco);
}


//Getters
int Disco::getCant() const
{
    return cant;
}

char *Disco::getNombreDisco()
{
    return this->nombreDisco;
}

void Disco::addCancion(Cancion *can)
{
    Cancion ** aux = new Cancion*[cant + 1];
    for (int i=0; i< this->cant; i++)
        aux[i] = this->canciones[i];
    aux[cant]=can;
    cant++;
    delete [] this->canciones;
    this->canciones = aux;
}

Cancion *Disco::getCancion(int i)
{
    return this->canciones[i];
}

double Disco::getDuracion()
{
    double total=0;
    for(int i=0; i<this->cant; i++)
        total += this->getCancion(i)->getDuracion();
    return total;
}
