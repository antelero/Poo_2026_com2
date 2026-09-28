#include "personadaosql.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

PersonaDaoSql::PersonaDaoSql() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("agenda.db");

    if (!db.open()) {
        qDebug() << "Error al abrir la BD:" << db.lastError().text();
    } else {
        initDatabase();
    }
}

PersonaDaoSql::~PersonaDaoSql() {
    if (db.isOpen()) db.close();
}

void PersonaDaoSql::initDatabase() {
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");

    // Creamos ambas tablas de forma directa
    query.exec("CREATE TABLE IF NOT EXISTS personas ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT, direccion TEXT);");

    query.exec("CREATE TABLE IF NOT EXISTS contactos ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, persona_id INTEGER, tipo TEXT, valor TEXT, "
               "FOREIGN KEY(persona_id) REFERENCES personas(id) ON DELETE CASCADE);");
}

std::vector<Persona> PersonaDaoSql::leerTodo() {
    std::vector<Persona> listaPersonas;
    QSqlQuery queryPersona("SELECT id, nombre, direccion FROM personas");

    while (queryPersona.next()) {
        int idPersona = queryPersona.value("id").toInt();

        // Agregamos (char*) al inicio para convertir de const char* a char* de forma directa
        Persona p((char*)queryPersona.value("nombre").toString().toLocal8Bit().constData());
        p.setId(idPersona);
        p.setDir((char*)queryPersona.value("direccion").toString().toLocal8Bit().constData());

        QSqlQuery queryContacto;
        queryContacto.prepare("SELECT tipo, valor FROM contactos WHERE persona_id = ?");
        queryContacto.addBindValue(idPersona);

        if (queryContacto.exec()) {
            while (queryContacto.next()) {
                // Hacemos el mismo molde de tipo (char*) para los campos de Contacto
                Contacto c((char*)queryContacto.value("tipo").toString().toLocal8Bit().constData(),
                           (char*)queryContacto.value("valor").toString().toLocal8Bit().constData());
                c.setId_persona(idPersona);
                p.addContacto(c);
            }
        }
        listaPersonas.push_back(p);
    }
    return listaPersonas;
}


bool PersonaDaoSql::guardar(Persona persona) {
    QSqlQuery query;
    query.prepare("INSERT INTO personas (nombre, direccion) VALUES (?, ?)");
    // Envolvemos el char* en QString para que Qt lo entienda de forma segura
    query.addBindValue(QString(persona.getNombre()));
    query.addBindValue(QString(persona.getDir()));

    if (!query.exec()) return false;

    int idGenerado = query.lastInsertId().toInt();

    // Guardar los contactos
    for (const Contacto& c : persona.getContactos()) {
        QSqlQuery queryContacto;
        queryContacto.prepare("INSERT INTO contactos (persona_id, tipo, valor) VALUES (?, ?, ?)");
        queryContacto.addBindValue(idGenerado);
        // Hacemos lo mismo para los campos de Contacto
        queryContacto.addBindValue(QString::fromStdString(c.getTipo()));
        queryContacto.addBindValue(QString::fromStdString(c.getValor()));
        queryContacto.exec();
    }
    return true;
}


bool PersonaDaoSql::guardarContacto(int idPersona, const Contacto &c) {
    QSqlQuery q;
    q.prepare("INSERT INTO contactos (persona_id, tipo, valor) VALUES (?, ?, ?)");
    q.addBindValue(idPersona);
    q.addBindValue(QString::fromStdString(c.getTipo()));
    q.addBindValue(QString::fromStdString(c.getValor()));
    return q.exec();
}

void PersonaDaoSql::generarDatosDeEjemplo()
{
    //Para hacer....
}
