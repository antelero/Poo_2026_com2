#include "plan.h"

Plan::Plan(const string &archivo) : nombreArchivo(archivo) {
    cargarPrestaciones();
}

void Plan::cargarPrestaciones() {
    ifstream arch(nombreArchivo);
    string prestacion;
    while (getline(arch, prestacion)) {
        if (!prestacion.empty())
            prestaciones.push_back(prestacion);
    }
}

const vector<string> &Plan::getPrestaciones() const {
    return prestaciones;
}

bool Plan::tienePrestacion(const string &p) const {
    auto tPres = find(prestaciones.begin(), prestaciones.end(), p);
    return  tPres != prestaciones.end();
}
