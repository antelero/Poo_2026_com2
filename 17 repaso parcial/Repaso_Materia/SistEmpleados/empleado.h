#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "iostream"

using namespace std;
class Persona {
protected:
    string nombre;
public:
    Persona(string n) : nombre(n) {}
    virtual void presentarse() const {
        cout << "Soy " << nombre << endl;
    }
};

class Empleado : public Persona {
public:
    Empleado(string n) : Persona(n) {}
    void presentarse() const  override { // falta el 'const'
        cout << "Empleado: " << nombre << endl;
    }
};
#endif // EMPLEADO_H
