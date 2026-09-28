#ifndef TURISMO_H
#define TURISMO_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>

#include "vuelo.h"
#include "hotel.h"
#include "excursion.h"
#include "paquete.h"

struct RegistroServicio {

    int numero;
    int tipo; //Hotel, Vuelo,

    char descripcion[100];

    int dato1;
    int dato2;

    char texto1[50];
    char texto2[50];

};
struct RegistroComponente {

    int numeroPaquete;
    int numeroComponente;

};

class Turismo{

private:
    vector<Servicio*> servicios;
    map<int, Servicio*> indice;
    void guardarComponentes(string nombre);
    void guardarServicios(string nombre);      
    void cargarServicios(string nombre);
    void cargarComponentes(string nombre);
public:
    void agregarServicio(Servicio *s);
    vector<Servicio*> getServicios();
    vector<Paquete*> getPaquetes();
    void imprimirPrecios();
    void guardarBinario();
    void cargarBinario();
    //3.1 Obtener los 5 paquetes más caros
    vector<Paquete *> cincoMasCaros();
    //3.2 Cantidad de vuelos por ciudad de origen
    map<string, int> vuelosPorOrigen();
    //4. Guardar todos los precios en archivo de texto (10 puntos)
    void guardarTexto(string nombre);
};

#endif // TURISMO_H
