#ifndef PARTE_H
#define PARTE_H
#include "item.h"

class Parte : public Item {
private:
    double precio;
public:
    Parte(int n, const char* d, double p);
    double getPrecio() const override;
};

#endif // PARTE_H
