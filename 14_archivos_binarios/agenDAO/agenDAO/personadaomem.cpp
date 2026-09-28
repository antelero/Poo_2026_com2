#include "personadaomem.h"

PersonaDaoMem::PersonaDaoMem()
{

}

std::vector<Persona> PersonaDaoMem::leerTodo()
{
    return this->personas;
}

bool PersonaDaoMem::guardar(Persona persona)
{
    this->personas.push_back(persona);
    return true;
}

bool PersonaDaoMem::guardarContacto(int idPersona, const Contacto &c)
{
    for (auto &p : personas) {
        if (p.getId() == idPersona) {
            p.addContacto(c);
            return true;
        }
    }
    return false;
}

void PersonaDaoMem::generarDatosDeEjemplo()
{
    Persona juan("juan");
    juan.setDir("dir de juan");
    Contacto contactoJuanEmail("email", "juan@algo");
    Contacto contactoJuanTel("tel", "12321236565465");
    juan.addContacto(contactoJuanEmail);
    juan.addContacto(contactoJuanTel);
    this->guardar(juan);

    Persona nico("Nico");
    nico.setDir("dir de nico");
    Contacto contactoNicoEmail("email", "nico@algo");
    Contacto contactoNicoTel("tel", "6565465");
    nico.addContacto(contactoNicoEmail);
    nico.addContacto(contactoNicoTel);
    this->guardar(nico);
}
