#ifndef PERSONADAOFILE_H
#define PERSONADAOFILE_H
#include "personadao.h"

class PersonaDaoFile : public PersonaDao
{
public:
    PersonaDaoFile();
    std::vector<Persona> leerTodo();
    bool guardar(Persona persona);
    bool guardarContacto(int idPersona, const Contacto &c);
    void generarDatosDeEjemplo();
};

#endif // PERSONADAOFILE_H
