#include "personadaofiletxt.h"
#include <fstream>
#include <sstream>
#include <string>

PersonaDaoFileTxt::PersonaDaoFileTxt() {
    // Constructor vacío
}

std::vector<Persona> PersonaDaoFileTxt::leerTodo() {
    std::vector<Contacto> contactos;
    std::vector<Persona> personas;

    // 1. LEER CONTACTOS DESDE EL ARCHIVO DE TEXTO
    std::ifstream archiContacto("contacto.txt");
    if (archiContacto.is_open()) {
        std::string linea;
        while (std::getline(archiContacto, linea)) {
            if (linea.empty()) continue;

            std::stringstream ss(linea);
            std::string id_persona_str, tipo, valor;

            // Leemos los campos separados por ';'
            std::getline(ss, id_persona_str, ';');
            std::getline(ss, tipo, ';');
            std::getline(ss, valor, ';');

            if (id_persona_str.empty()) continue;
            Contacto unContacto(tipo, valor);
            unContacto.setId_persona(std::stoi(id_persona_str));
            contactos.push_back(unContacto);
        }
        archiContacto.close();
    }

    // 2. LEER PERSONAS DESDE EL ARCHIVO DE TEXTO
    std::ifstream archi("persona.txt");
    if (archi.is_open()) {
        std::string linea;
        while (std::getline(archi, linea)) {
            if (linea.empty()) continue;

            std::stringstream ss(linea);
            std::string id_str, nombre, dir;

            // Leemos los campos separados por ';'
            std::getline(ss, id_str, ';');
            std::getline(ss, nombre, ';');
            std::getline(ss, dir, ';');

            Persona unaPersona((char*)nombre.c_str());
            unaPersona.setDir((char*)dir.c_str());
            unaPersona.setId(std::stoi(id_str));

            // Asociamos los contactos que pertenecen a esta persona
            for (size_t i = 0; i < contactos.size(); i++) {
                if (unaPersona.getId() == contactos[i].getId_persona()) {
                    unaPersona.addContacto(contactos[i]);
                }
            }
            personas.push_back(unaPersona);
        }
        archi.close();
    }
    return personas;
}

bool PersonaDaoFileTxt::guardar(Persona persona) {
    // Abrimos en modo normal de texto y app (append para agregar al final)
    std::ofstream archi("persona.txt", std::ios::app);
    if (!archi.is_open()) return false;

    // Guardamos la persona en formato: id;nombre;direccion
    archi << persona.getId() << ";"
          << persona.getNombre() << ";"
          << persona.getDir() << "\n";
    archi.close();

    std::ofstream archiContacto("contacto.txt", std::ios::app);
    if (archiContacto.is_open()) {
        std::vector<Contacto> listaContactos = persona.getContactos();
        for (size_t i = 0; i < listaContactos.size(); i++) {
            // Guardamos el contacto en formato: id_persona;tipo;valor
            archiContacto << persona.getId() << ";"
                          << listaContactos[i].getTipo() << ";"
                          << listaContactos[i].getValor() << "\n";
        }
        archiContacto.close();
        return true;
    }

    return false;
}

bool PersonaDaoFileTxt::guardarContacto(int idPersona, const Contacto &c) {
    std::ofstream archi("contacto.txt", std::ios::app);
    if (!archi.is_open()) return false;
    archi << idPersona << ";" << c.getTipo() << ";" << c.getValor() << "\n";
    return true;
}

void PersonaDaoFileTxt::generarDatosDeEjemplo() {
    // Usamos punteros tradicionales (char*) para tus constructores
    Persona juan((char*)"juan");
    juan.setId(1); // Le asignamos un ID manual ya que el archivo de texto no es autoincremental directo
    juan.setDir((char*)"dir de juan");
    juan.addContacto(Contacto((char*)"email", (char*)"juan@algo"));
    juan.addContacto(Contacto((char*)"tel", (char*)"12321236565465"));
    this->guardar(juan);

    Persona nico((char*)"Nico");
    nico.setId(2);
    nico.setDir((char*)"dir de nico");
    nico.addContacto(Contacto((char*)"email", (char*)"nico@algo"));
    nico.addContacto(Contacto((char*)"tel", (char*)"6565465"));
    this->guardar(nico);
}
