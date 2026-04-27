#include "catalogo.h"



Catalogo::Catalogo(char nombreCata[])
{
    strcpy(this->nombreCata,nombreCata);
}

//Getters
int Catalogo::getCant() const
{
    return cant;
}

char * Catalogo::getNombreCatalogo(){

    return this->nombreCata;
}

void Catalogo::addDisco(Disco *dis)
{
    Disco **aux = new Disco*[cant + 1];
    for (int i = 0; i<this->cant; i++)
        aux[i] = this->discos[i];
    aux[cant] = dis;
    cant++;
    delete [] this->discos;
    this->discos = aux;
}

Disco *Catalogo::getDisco(int i)
{
    return this->discos[i];
}

double Catalogo::getDuracion()
{
    double total;
    for (int i=0; i<this->cant; i++)
        total += this->getDisco(i)->getDuracion();
    return total;
};

