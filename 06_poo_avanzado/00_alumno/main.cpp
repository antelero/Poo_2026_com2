#include <iostream>
#include "alumno.h"
#include "alumnoregular.h"
#include "alumnolibre.h"
#include "materia.h"
#include "alumnopromovido.h"

using namespace std;

int main()
{
    Materia poo;
    AlumnoRegular * jose = new AlumnoRegular(222222,"Jose",40);
    AlumnoRegular * jorge = new AlumnoRegular(333333,"Jorge",70);

    AlumnoLibre *xavi = new AlumnoLibre(444444, "Xavi", 50,60);
    AlumnoLibre *roberto = new AlumnoLibre(555555, "Roberto", 70,60);

    AlumnoPromovido *manuel = new AlumnoPromovido(66666,"Manuel");

    poo.addAlumno(jose);
    poo.addAlumno(jorge);
    poo.addAlumno(xavi);
    poo.addAlumno(roberto);
    poo.addAlumno(manuel);
    cout << "Elementos del vector " << poo.getCant() << endl;
    for (int i=0; i<poo.getCant(); i++){
        Alumno *al;
        al = poo.getAlumno(i);
        cout << al->getDni() << " "<<al->getNomApe() << " " << al->getCondicion() << endl;
    }





    return 0;
}
