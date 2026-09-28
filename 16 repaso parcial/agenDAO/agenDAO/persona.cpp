#include "persona.h"
#include <string.h>

static char *copiar(const char *origen)
{
    if (!origen) origen = "";
    char *destino = new char[strlen(origen) + 1];
    strcpy(destino, origen);
    return destino;
}

Persona::Persona(const char *newNombre)
{
    id = 0;
    nombre = copiar(newNombre);
    dir = copiar("");
}

Persona::Persona(const Persona &otra)
{
    id = otra.id;
    nombre = copiar(otra.nombre);
    dir = copiar(otra.dir);
    contactos = otra.contactos;
}

Persona &Persona::operator=(const Persona &otra)
{
    if (this != &otra) {
        char *n = copiar(otra.nombre);
        char *d = copiar(otra.dir);
        delete[] nombre;
        delete[] dir;
        nombre = n;
        dir = d;
        id = otra.id;
        contactos = otra.contactos;
    }
    return *this;
}

Persona::~Persona()
{
    delete[] nombre;
    delete[] dir;
}

char *Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const char *newNombre)
{
    char *n = copiar(newNombre);
    delete[] nombre;
    nombre = n;
}

char *Persona::getDir() const
{
    return dir;
}

void Persona::setDir(const char *newDir)
{
    char *d = copiar(newDir);
    delete[] dir;
    dir = d;
}

std::vector<Contacto> Persona::getContactos() const
{
    return contactos;
}

void Persona::addContacto(Contacto c)
{
    this->contactos.push_back(c);
}

void Persona::setContactos(const std::vector<Contacto> &newContactos)
{
    contactos = newContactos;
}

int Persona::getId() const
{
    return id;
}

void Persona::setId(int newId)
{
    id = newId;
}
