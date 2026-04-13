#include <iostream>
#include "alumno.h"

using namespace std;

int main()
{
    Alumno jose(4444444,"Jose");
    jose.setNota_1(60);
    jose.setNota_2(70);
    Alumno jorge(55555555,"Jorge");
    jorge.setNota_1(80);
    jorge.setNota_2(90);
    Alumno roberto(66666666,"Roberto");
    roberto.setNota_1(40);
    roberto.setNota_2(50);
    cout << jose.getDni() << " " << jose.getNom_ape() << " " << jose.getProm() << endl;
    cout << jorge.getDni() << " " << jorge.getNom_ape() << " " << jorge.getProm() << endl;
    cout << roberto.getDni() << " " << roberto.getNom_ape() << " " << roberto.getProm() << endl;

    cout <<  "  Iterando"<< endl;
    int n=3;
    double acumula = 0;
    Alumno * alumnos = new Alumno[n];
    alumnos[0]=jose;
    alumnos[1]=jorge;
    alumnos[2]=roberto;
    for (int i=0; i<n; i++){
        acumula += alumnos[i].getProm();
        cout << "   " << alumnos[i].getDni() << " " << alumnos[i].getNom_ape() << " " << alumnos[i].getProm() << endl;
    }
    cout << " Promedio general: " << acumula / n << endl;
    return 0;
}
