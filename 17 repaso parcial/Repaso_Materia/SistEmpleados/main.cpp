#include "iostream"

using namespace std;

class Contrato {
public:
    virtual void identificar() {
        cout << "Contrato"; }
    void tipo() { cout << "tipo-Contrato"; }
};

class ContratoIndefinido : public Contrato {
public:
    void identificar() override {
        cout << "Indefinido"; }
    void tipo() { cout << "tipo-Indef"; }
};

int main() {
    Contrato* c = new ContratoIndefinido();
    c->identificar();   // ?
    c->tipo();          // ?
}
