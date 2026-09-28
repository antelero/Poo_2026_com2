#include "oferta.h"

Oferta::Oferta(int n, const char *d) : Item(n, d)
{
}

void Oferta::agregarItem(Item *i)
{
    items.push_back(i);
}

double Oferta::getPrecio() const
{
    double total = 0;
    for (const Item* i : items)
        total += i->getPrecio();
    return total * 0.8;
}

const std::vector<Item*>& Oferta::getItems() const
{
    return items;
}

// Formato: Oferta N (desc): item1, item2, ... | Precio total: $X
std::ostream& operator<<(std::ostream& os, const Oferta& o)
{
    os << "Oferta " << o.getNumero() << " (" << o.getDescripcion() << "): ";
    for (size_t i = 0; i < o.items.size(); ++i) {
        os << o.items[i]->getDescripcion();
        if (i + 1 < o.items.size())
            os << ", ";
    }
    os << " | Precio total: $" << o.getPrecio();
    return os;
}
