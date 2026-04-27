#ifndef AUTOR_H
#define AUTOR_H
#include <cstring>

class Autor
{
private:
    char nombreAutor[20];
public:
    Autor(char nombreAutor[]);
    char * getNombreAutor();
};

#endif // AUTOR_H
