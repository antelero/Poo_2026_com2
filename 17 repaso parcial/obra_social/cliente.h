#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include "plan.h"
#include <cstring>

using namespace std;

class Cliente {
    int id;
    char nombre[200];
    char tipo;   // 'b'plan básico:, 'm'plan medio:, 'p'plan premium:
    int cantidad;
    Plan* plan;
public:
    Cliente();
    Cliente(int _id, const char* _nombre, char _tipo, int _cant, Plan* _plan);
    int getCantidad() const;
    char getTipo() const;
    const char* getNombre() const;
    bool tienePrestacion(const string& p) const;
    friend ostream& operator<<(ostream& os, const Cliente& c);
};

#endif
