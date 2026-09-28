#ifndef PERSONA_H
#define PERSONA_H
#include "contacto.h"
#include <vector>
#include <string>
class Persona
{
private:
    int id;
    char * nombre;
    char * dir;
    std::vector<Contacto> contactos;
public:
    Persona(const char * nombre);
    Persona(const Persona &otra);
    Persona &operator=(const Persona &otra);
    ~Persona();

    char *getNombre() const;
    void setNombre(const char *newNombre);
    char *getDir() const;
    void setDir(const char *newDir);
    std::vector<Contacto> getContactos() const;
    void addContacto(Contacto c);
    void setContactos(const std::vector<Contacto> &newContactos);
    int getId() const;
    void setId(int newId);
};

#endif // PERSONA_H
