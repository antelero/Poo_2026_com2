#ifndef PERSONADAOFILETXT_H
#define PERSONADAOFILETXT_H
#include "personadao.h"
#include <vector>
#include "persona.h"
#include "contacto.h"

class PersonaDaoFileTxt : public PersonaDao {
public:
    PersonaDaoFileTxt();
    virtual ~PersonaDaoFileTxt() {}

    std::vector<Persona> leerTodo() override;
    bool guardar(Persona persona) override;
    bool guardarContacto(int idPersona, const Contacto &c) override;
    void generarDatosDeEjemplo() override;
};

#endif // PERSONADAOFILETXT_H
