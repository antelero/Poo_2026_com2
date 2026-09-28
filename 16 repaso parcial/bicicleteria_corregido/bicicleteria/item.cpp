#include "item.h"

Item::Item(int n, const char* d) {
    numero = n;
    if (!d) d = "";
    std::strncpy(descripcion, d, sizeof(descripcion) - 1);
    descripcion[sizeof(descripcion) - 1] = '\0';
}

const char* Item::getDescripcion() const {
    return descripcion;
}

int Item::getNumero() const {
    return numero;
}
