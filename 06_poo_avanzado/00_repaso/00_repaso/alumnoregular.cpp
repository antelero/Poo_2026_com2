#include "alumnoregular.h"


AlumnoRegular::AlumnoRegular(int d, char* nom, Examen ex)
    : Alumno( d, nom, ex) {}

bool AlumnoRegular::estaAprobado() {
    return getNota() >= 6;
}

float AlumnoRegular::calcularNotaFinal() {
    return getNota();
}

char * AlumnoRegular::mostrar() {
    static char  aux[100];
    sprintf(aux, "Regular->Nombre: %s Nota: %.2f", this->getNom_ape(), getNota());
    return  aux;
    }
