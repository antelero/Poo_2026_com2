#ifndef ITEM_H
#define ITEM_H
#include <cstring>

/*
 * DISEÑO
 * ------
 *   Item (abstracta: numero, descripcion[200], getPrecio() virtual puro)
 *    ├── Parte      -> precio propio
 *    ├── Bicicleta  -> precio = suma de sus partes
 *    └── Oferta     -> precio = suma de sus items * 0.8 (Composite)
 *
 *   Bicicleteria (contiene y es dueña de partes, bicicletas y ofertas)
 *
 */
class Item
{
private:
    int numero;
    char descripcion[200];

public:
    Item(int n, const char* d);
    virtual ~Item() = default;

    const char *getDescripcion() const;
    int getNumero() const;

    virtual double getPrecio() const = 0;
};

#endif // ITEM_H
