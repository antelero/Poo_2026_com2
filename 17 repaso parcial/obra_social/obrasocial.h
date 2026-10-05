#ifndef OBRASOCIAL_H
#define OBRASOCIAL_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include "cliente.h"

using namespace std;

struct strUsuario {
    int id;
    char nombre[200];
    char tipo;
    int cantidad;
};

class ObraSocial {
    vector<Cliente> clientes;
    map<char, Plan*> planes;
public:
    ObraSocial();
    void inicializarPlanes();
    void crearClientesBin();
    void cargarClientes(const string& nombreArchivo);

    const vector<Cliente>& getClientes() const { return clientes; }

    // Los 5 usuarios que más usaron el servicio
    vector<Cliente> top5Usuarios() const;

    // Todas las prestaciones de todos los planes
    vector<string> todasLasPrestaciones() const;

    // Cantidad total por tipo de plan
    map<char, int> cantidadPorPlan() const {
        map<char, int> total;
        for (auto& c : clientes)
            total[c.getTipo()] += c.getCantidad();
        return total;
    }

    // (10) Prestaciones que se repiten en todos los planes
    vector<string> prestacionesComunes() const;


    void crearArchivosPlanes();
};

#endif
