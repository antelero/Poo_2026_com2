/*
 * Ejercicio 4
Escriba 3 funciones sobrecargando el nombreintercambio(..)demodoquecadauna
deellaspuedaser invocada yproduzcael intercambiode2datosquesepasancomo
parámetros: 2 datos de tipo char, 2 datos enteros, dos arreglos de flotantes.
 */

#include <iostream>

using namespace std;
void intercambio(char &a, char &b);
void intercambio(int &a, int &b);
void intercambio(float a[], float b[]);


int main()
{
    cout << "PARTE A" << endl;
    char uno = 'a';
    char dos = 'b';
    cout << "ANTES intercambio de chars "<< uno <<" "<< dos << endl;
    intercambio(uno, dos);
    cout << "intercambio de chars "<< uno <<" "<< dos << endl;
    cout << "PARTE B" << endl;
    int numa = 5;
    int numb = 3;
    cout << "ANTES intercambio de int "<< numa <<" "<< numb << endl;
    intercambio(numa, numb);
    cout << "intercambio de int "<< numa <<" "<< numb << endl;


    float aa[5] = {1,2,3,4,5};
    float ba[5] = {5,4,3,2,1};

    cout << "PARTE C" << endl;
    cout << "ANTES intercambio " << endl;
    for (int i=0; i<5;i++)
        cout << "A " << aa[i]<< endl;
    for (int i=0; i<5;i++)
        cout << "B " << ba[i] << endl;

    intercambio(aa,ba);
    cout << "intercambio " << endl;
    for (int i=0; i<5;i++)
         cout << "A "<< aa[i]<< endl;
    for (int i=0; i<5;i++)
         cout << "B " << ba[i] << endl;
    return 0;
}
void intercambio(char &a, char &b){
    char c = a;
    a=b;
    b=c;
}

void intercambio(int &a, int &b){
    int c = a;
    a=b;
    b=c;
}
void intercambio(float a[], float b[]){
    for (int i=0;i<5;i++)
        {
            float aux = 0;
            aux = a[i];
            a[i] = b[i];
            b[i] = aux;
        }
}
