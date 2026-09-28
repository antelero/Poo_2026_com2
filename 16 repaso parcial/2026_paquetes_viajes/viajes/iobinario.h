#ifndef IOBINARIO_H
#define IOBINARIO_H

#include <iostream>
#include <string>

// Funciones auxiliares para serializar/deserializar en binario.
// Se centralizan aqui para no repetir el manejo de streams en cada clase.

void escribirString(std::ostream& out, const std::string& s);
std::string leerString(std::istream& in);

template <typename T>
void escribirValor(std::ostream& out, const T& valor) {
    out.write(reinterpret_cast<const char*>(&valor), sizeof(T));
}

template <typename T>
T leerValor(std::istream& in) {
    T valor{};
    in.read(reinterpret_cast<char*>(&valor), sizeof(T));
    return valor;
}

#endif // IOBINARIO_H
