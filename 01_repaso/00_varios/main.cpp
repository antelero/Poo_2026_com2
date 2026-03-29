#include <iostream>

using namespace std;
/*
 * Ejercicio​ ​13
La función H(x) se define como
    Si x<4 → H(x)=4*x
    Si x≥4 → H(x)=3*H(x−2)+1
Escriba una función C++ recursiva que lac alcule y un programa cliente que permita probarla.
Obtener H(7), H( 5), H(12).
*/
int H(int x){
    if (x<4)
        return x*4;
    else if (x>=4)
        return 3*H(x-2)+1;
}
int HDet(int x){
   cout << "Llamando H(" << x << ")" << endl;
   if (x < 4) {
       cout << "Base: H(" << x << ") = " << 4*x << endl;
       return 4 * x;
   }
   int res = 3 * HDet(x - 2) + 1;
   cout << "Resolviendo H(" << x << ") = " << res << endl;
   return res;
}
/*Ejercicio​ ​14
Escriba una función recursiva para calcular el máximo común divisor (m.c.d.)de dos números
enteros dados aplicando las propiedades recurrentes.
Si a>b,  entonces m.c.d.(a,b)=m.c.d.(a-b,b)
Si a<b,  entonces m.c.d.(a,b)=m.c.d.(a, b-a)
Si a=b,  entonces m.c.d.(a,b)=m.c.d.(b,a)=a=b
*/
int mcdA(int a, int b){
    if (a==b)
        return a;
    else if (a>b)
        return mcdA(a-b,b);
   return mcdA(a,b-a);
}
int mcdB(int a, int b){
    if (b==0)
        return a;
    else
        return mcdA(b,a%b);
}
/*
Ejercicio​ ​16
Determinar si un año es bisisiesto
Recordar: ​Un año es bisiesto si es divisible por 4, excepto losañosdesiglo (aquellos
divisibles por 100), que para ser bisiestos, también deben ser divisibles por 400​. */
bool bisiesto(int anio){
    if (anio%4==0 &&
        (anio%100!=0 || anio%400==0) )
        return true;
    else
        return false;
}
/*Guia 2*/
//2. Realice un método que retorne el promedio de un vector de 10 enteros

int minimo(int vec[], int n){
    if (n==0)
        return 0;
    if (n == 1)
        return vec[0];
    int min = minimo(vec, n - 1);
    if (vec[n - 1] < min)
        return vec[n - 1];
    else
        return min;
}

int maximo(int vec[], int n){
    if (n==0)
        return 0;
    if (n == 1)
        return vec[0];
    int max = maximo(vec, n - 1);
    if (vec[n - 1] > max)
        return vec[n - 1];
    else
        return max;
}

int suma(int vec[], int n){
    if (n==0)
        return 0;
    return vec[n - 1] + suma(vec, n - 1);
}

float promedioA(int vec[], int n){
    if (n==0)
        return 0;
    return (vec[n - 1] + promedioA(vec, n - 1) * (n - 1)) / (float)n;
}
float promedio(int v[], int n) {
    if (n==0)
        return 0;
    return (float)suma(v, n) / n;
}

void invertir(int v[], int low, int high) {
    if (low < high) {
        int aux  = v[low];
        v[low] = v[high];
        v[high]=aux;
        invertir(v, low+1, high-1);
    }
}
int main()
{
    //H(7), H( 5), H(12)
    cout << "Ejemplo H"<<endl;
    cout <<H(7)<< " "<< H( 5)<< " "<< H(12)<< endl;
    //Ejemplo H(7) Detallado
    cout << "Ejemplo H(7) Detallado"<<endl;
    cout <<HDet(7)<<endl;
    cout << "Ejemplo MCD (Máximo Común Divisor)"<<endl;
    cout << mcdA(16,24) << " "<<  mcdB(16,24) << endl;
    cout << mcdA(48,18)<< " "<<  mcdB(48,18) << endl;
    cout << "Ejemplo Bisiesto" << endl;
    cout << "2024 V " << bisiesto(2024) << endl;
    cout << "1900 X " << bisiesto(1900) << endl;
    cout << "2000 V " << bisiesto(2000) << endl;
    int v[10] = {-3, 7, 2, 9, 5, 1, 8, 4, 6, 0};
    int v1[0] = {};
    int v2[1] = {2};
    int N=10;
    cout << "El minimo es: " << minimo(v, 10) << " "<<  minimo(v1, 0) << " "<<  minimo(v2, 1)<< endl;
    cout << "El maximo es: " << maximo(v, 10) << " "<<  maximo(v1, 0) << " "<<  maximo(v2, 1) << endl;
    cout << "Suma: " << suma(v, 10) << " "<<  suma(v1, 0) << " "<<  suma(v2, 1) << endl;
    cout << "Promedio: " << promedio(v, 10) << " "<<  promedio(v1, 0) << " "<<  promedio(v2, 1) << endl;
    cout << "Invertir: " <<  endl;
    for(int i = 0; i < N; i++){
        cout << v[i] << " ";
    }
    invertir( v, 0, N-1);
    cout<< endl << "Inverso "<< endl;
    for(int i = 0; i < N; i++){
        cout << v[i] << " ";
    }
    cout<< endl;
    return 0;
}
