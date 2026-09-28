#include "contacto.h"

Contacto::Contacto() {
    id_persona = 0;
}

Contacto::Contacto(const string &tipo, const string &valor) {
    id_persona = 0;
    this->tipo = tipo;
    this->valor = valor;
}

int Contacto::getId_persona() const {
    return id_persona;
}

void Contacto::setId_persona(int id) {
    id_persona = id;
}

string Contacto::getTipo() const {
    return tipo;
}

string Contacto::getValor() const {
    return valor;
}

void Contacto::setTipo(const string &tipo) {
    this->tipo = tipo;
}

void Contacto::setValor(const string &valor) {
    this->valor = valor;
}
