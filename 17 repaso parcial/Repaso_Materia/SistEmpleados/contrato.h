#ifndef CONTRATO_H
#define CONTRATO_H
class Contrato {
public:
    virtual double calcularIndemnizacion()
        const = 0;
    virtual ~Contrato() {}
};
// Contrato c;    // ERROR: es abstracta

class ContratoIndefinido : public Contrato {
public:
    double calcularIndemnizacion() const override {
        return 50000; // simplificado
    }
};

class ContratoTemporal : public Contrato {
public:
    double calcularIndemnizacion() const override {
        return 0; // sin indemnización
    }
};
#endif // CONTRATO_H
