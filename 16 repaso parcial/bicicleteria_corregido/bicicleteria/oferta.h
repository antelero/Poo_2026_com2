#ifndef OFERTA_H
#define OFERTA_H
#include <vector>
#include <iostream>
#include "bicicleta.h"

// Oferta: conjunto de partes y/o bicicletas. Precio = suma de items - 20%
class Oferta : public Item {
private:
    std::vector<Item*> items;   // no es dueña de los items
public:
    Oferta(int n, const char* d);
    void agregarItem(Item* np);
    double getPrecio() const override;
    const std::vector<Item*>& getItems() const;

    friend std::ostream& operator<<(std::ostream& os, const Oferta& o);
};

#endif // OFERTA_H
