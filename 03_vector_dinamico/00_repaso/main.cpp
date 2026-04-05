#include <iostream>

using namespace std;
void addElemento(int *& vec, int &cant, int valor)
{
    int * aux = new int[cant + 1];  // Creo un nuevo vector con una posición más
    for (int i = 0; i < cant; i++)
        aux[i] = vec[i];            //Copio elementos del vector original
    aux[cant] = valor;              //Agrego el nuevo elemento al final
    cant++;
    delete[] vec;                   //Libero memoria del vector original
    vec = aux;                      //Apunto el vector original al nuevo vector con el elemento agregado
}


int*  addElemento2(int * vec, int &cant, int valor)
{
    int * aux = new int[cant + 1];  // Creo un nuevo vector con una posición más
    for (int i = 0; i < cant; i++)
        aux[i] = vec[i];    //Copio elementos del vector original
    aux[cant] = valor;      //Agrego el nuevo elemento al final
    cant++;
    delete[] vec;           //Libero memoria del vector original
    vec = aux;              //Apunto el vector original al nuevo vector con el elemento agregado
    return aux;             // Retorno el nuevo vector con el elemento agregado
}

int* delElementoPorIndice(int * vec, int &cant, int indice)
{
    int * aux = new int[cant - 1];  // Creo un nuevo vector con una posición menos
    int j = 0;
    for (int i = 0; i < cant; i++) {
        if (i != indice) { // Copio solo los elementos que no están en el índice a eliminar
            aux[j] = vec[i];
            j++;
        }
    }
    cant--;
    delete[] vec;           // Libero memoria del vector original
    return aux;             // Retorno el nuevo vector con el elemento eliminado
}

int* delElementoPorValor(int * vec, int &cant, int valor)
{
    int * aux = new int[cant - 1];
    int j = 0;
    for (int i = 0; i < cant; i++) {
        if (vec[i] != valor) { // Copio solo los elementos que no son el valor a eliminar
            aux[j] = vec[i];
            j++;
        }
    }
    cant--;
    delete[] vec;           // Libero memoria del vector original
    return aux;             // Retorno el nuevo vector con el elemento eliminado
}
void mostrar(int * vec, int n)
{
    cout << "Vector: ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl << "n " << n << endl;

}

int main()
{
    cout << "Arreglo normal -> fijo" << endl;
    int arr2[] = {5, 3, 5, 6};
    for (int i=0; i<4; i++)
        cout << arr2[i] << " ";
    cout << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Vector dinamico -> decidido en runtime" << endl;
    int n;
    cout << "Ingrese n de elementos: ";
    cin >> n;
    // Crear vector dinámico
    int* vec = new int[n];
    // Cargar datos
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> vec[i];
    }
    // Mostrar datos
    mostrar(vec,n);
    // Agregar elemento
    addElemento(vec,n,8);
    mostrar(vec,n);

    // Agregar elemento
    vec = addElemento2(vec,n,9);
    mostrar(vec,n);


    //Borrar elemento x indice
    vec = delElementoPorIndice(vec,n,2);
    mostrar(vec,n);

    //Borrar elemento x valor
    vec = delElementoPorValor(vec,n,8);
    mostrar(vec,n);

    // Liberar memoria
    delete[] vec;

    return 0;
}
