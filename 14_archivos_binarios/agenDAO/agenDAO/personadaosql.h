#ifndef PERSONADAOSQL_H
#define PERSONADAOSQL_H

#include <vector>
#include <QSqlDatabase>
 // Asegúrate de que el nombre coincida con tu clase Persona
#include "personadao.h"
class PersonaDaoSql : public PersonaDao
{
private:
    QSqlDatabase db;
    void initDatabase(); // Método auxiliar para crear la tabla si no existe

public:
    PersonaDaoSql();
    ~PersonaDaoSql();

    std::vector<Persona> leerTodo();
    bool guardar(Persona persona);
    bool guardarContacto(int idPersona, const Contacto &c);
    void generarDatosDeEjemplo();
};

#endif // PERSONADAOSQL_H
