#include "alumnolibre.h"

AlumnoLibre::AlumnoLibre(int d, char *nom, Examen ex):  Alumno( d, nom, ex) {

}

bool AlumnoLibre::estaAprobado() {
    return getNota() >= 6;
}

float AlumnoLibre::calcularNotaFinal() {
    return getNota();
}

char * AlumnoLibre::mostrar() {
    static char  aux[100];
    sprintf(aux, "Libre->Nombre: %s Nota: %.2f", this->getNom_ape(), getNota());
    return  aux;
    }


