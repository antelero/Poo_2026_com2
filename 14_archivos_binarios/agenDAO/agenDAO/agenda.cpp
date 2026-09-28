#include "agenda.h"
#include "personadaofile.h"
#include "personadaofiletxt.h"
#include "personadaomem.h"
#include "personadaosql.h"
#include <string.h>

const std::vector<Persona> &Agenda::getPersonas() const
{
    return personas;
}

Agenda::Agenda()
{
    //this->dao = new PersonaDaoFile();
    //this->dao = new PersonaDaoMem();
    //this->dao = new PersonaDaoSql();
    this->dao = new PersonaDaoFileTxt();
}

void Agenda::leer()
{
    this->personas = this->dao->leerTodo();
}

Agenda::~Agenda()
{
    delete dao;
}

bool Agenda::save(Persona persona)
{
    // Asignamos un id nuevo (el SQL lo genera solo y lo ignora)
    int maxId = 0;
    for (const auto &p : personas)
        if (p.getId() > maxId) maxId = p.getId();
    persona.setId(maxId + 1);

    bool ok = this->dao->guardar(persona);
    if (ok) this->leer();
    return ok;
}

void Agenda::generarDatosDeEjemplo()
{
    this->dao->generarDatosDeEjemplo();
}

std::vector<Persona> Agenda::filtrar(char *nombre)
{
    std::vector<Persona> aux;
    for (int i = 0; i < this->personas.size(); i++) {
        auto p = this->personas[i];
        int len = strlen(nombre);
        if (strncmp(p.getNombre(), nombre, len) == 0) {
            aux.push_back(p);
        }
    }
    return aux;
}



bool Agenda::agregarContactoAPersona(int idPersona, const std::string& tipo, const std::string& valor)
{
    for (auto& persona : personas) {
        if (persona.getId() == idPersona) {
            Contacto c(tipo, valor);
            c.setId_persona(idPersona);

            // Primero persistimos, después actualizamos la lista en memoria
            if (!dao->guardarContacto(idPersona, c))
                return false;
            persona.addContacto(c);
            return true;
        }
    }
    return false; // No se encontró la persona con ese ID
}
