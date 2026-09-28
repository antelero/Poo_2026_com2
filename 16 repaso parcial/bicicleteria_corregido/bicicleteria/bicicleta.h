#ifndef BICICLETA_H
#define BICICLETA_H
#include <vector>
#include "item.h"
#include "parte.h"

// numero y descripcion se heredan de Item (no se repiten)
class Bicicleta : public Item {
private:
    std::vector<Parte*> partes;   // no es dueña de las partes
public:
    Bicicleta(int n, const char* d);
    void agregarParte(Parte* np);
    double getPrecio() const override;
    const std::vector<Parte*>& getPartes() const;
};

#endif // BICICLETA_H
