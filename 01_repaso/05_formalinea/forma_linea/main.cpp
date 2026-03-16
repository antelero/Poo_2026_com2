/*
Ejercicio 5
Escriba un programa que utilice una función llamada formalinea() que reciba dos parámetros:
uno de tipo entero y otro de tipo char. El programa debe escribir una línea
con tantos caracteres repetidos como indique el parámetro entero. El segundo parámetro
es opcional; si no se lo especifica en la llamada, debe emplear el carácter '#'
para formar la secuencia.

Ejemplo de llamadas:
    formalinea(7,’-‘); debe mostrar: -------
    formalinea(10); debe escribir: ##########

*/

#include <iostream>

using namespace std;
//void formalinea(int cant, char car = '#');
void formalinea(int cant, char car= '#'){
    for (int i=0;i<cant;i++)
        cout << car;
}
int main()
{
    formalinea(7,'-');
    cout << endl;
    formalinea(10);
    cout << endl;
    return 0;
}


