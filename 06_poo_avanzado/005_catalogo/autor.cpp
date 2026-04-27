#include "autor.h"

Autor::Autor(char nombreAutor[])
{
    strcpy(this->nombreAutor, nombreAutor);
}

char *Autor::getNombreAutor()
{
    return this->nombreAutor;
}
