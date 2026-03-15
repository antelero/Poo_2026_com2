/*
Se ingresan losnombresyedadesde los457miembrosdeunaasociacióncooperadora.
Determinar el nombre y la edad del mayor de los integrantes.
Validar laentradadelosdatoscorrespondientesalasedades, loscualesdebenestardentro
el rango12..90,conunafunción ​llamada validar_edad() enlacual,alverificarseuna
edad fuera del rango, se debe indicar un mensaje de error y permitir el reingreso del dato.
*/
#include <iostream>
#include <string>
#define N 3
using namespace std;

int edades[20];
int edad;
string nombres[20];
string nombre;
int cant = 0;
bool validar_edad(int edad);

int main()
{
    cout << "Hello World!" << endl;
    for(int i=0;i<=5;i++){
        cout << "Ingrese el nombre: ";
        getline(cin, nombres[i]);

        cout << endl;
        cout << "Ingrese la Edad: ";
        cin >>  edad;
        cin.ignore();
        while(!validar_edad(edad)){
          cout << "NO valida! reingrese por favor: ";
          cin >>  edad;
          cin.ignore();
          if(validar_edad(edad)) break;
        };
        edades[i]=edad;
    }
    int mayor = edades[0];
    int id = 0;
    for(int i=0;i<=5;i++){
        if(edades[i] > mayor){
             mayor = edades[i];
             id = i;
        }
    };

    cout << "id "<< id <<"El nombre " << nombres[id] <<" y la Edad: " <<edades[id];
    return 0;
}


bool validar_edad(int edad){
   if(edad >= 12 && edad <= 90)
        return true;
    else return false;
}
