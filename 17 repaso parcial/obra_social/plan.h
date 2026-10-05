#ifndef PLAN_H
#define PLAN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class Plan {
    string nombreArchivo;
    vector<string> prestaciones;
    void cargarPrestaciones();
public:
    Plan(const string& archivo);
    const vector<string>& getPrestaciones() const;
    bool tienePrestacion(const string& p) const;
};

#endif
