/*
Se ingresan los nombres y edades de los 457 miembros de una asociación cooperadora.
Determinar el nombre y la edad del mayor de los integrantes.
Validar la entrada de los datos correspondientes a las edades, los cuales deben estar dentro
el rango 12..90,con una función ​llamada validar_edad() en la cual,al verificarse una
edad fuera del rango, se debe indicar un mensaje de error y permitir el reingreso del dato.
*/
#include <iostream>
#include <string>
#define N 5 //457
using namespace std;

int edades[20];
int edad;
string nombres[20];
string nombre;
int cant = 0;
bool validar_edad(int edad);

int main()
{
 
    for(int i=0;i<=N;i++){
        cout << "Ingrese el nombre: ";
        getline(cin, nombres[i]);        
        cout << "Ingrese la Edad: ";
        cin >>  edad;
        cin.ignore();
        cout << endl;
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

    cout << "MAYOR: "<< id <<" Nombre " << nombres[id] <<" y la Edad: " <<edades[id] <<endl;
    return 0;
}


bool validar_edad(int edad){
   if(edad >= 12 && edad <= 90)
        return true;
    else return false;
}
