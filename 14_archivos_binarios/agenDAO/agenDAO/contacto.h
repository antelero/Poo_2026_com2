#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>
using namespace std;

class Contacto {
private:
    int id_persona;
    string tipo;
    string valor;

public:
    Contacto();
    Contacto(const string &tipo, const string &valor);

    // Getters
    int getId_persona() const;
    string getTipo() const;
    string getValor() const;

    // Setters
    void setId_persona(int id);
    void setTipo(const string &tipo);
    void setValor(const string &valor);
};

#endif // CONTACTO_H
