#include "examen.h"


Examen::Examen() {
    nota = 0;
    strcpy(fecha, "Sin fecha");
}

Examen::Examen(float n, const char* f) {
    nota = n;
    strcpy(fecha, f);
}

float Examen::getNota() {
    return nota;
}
