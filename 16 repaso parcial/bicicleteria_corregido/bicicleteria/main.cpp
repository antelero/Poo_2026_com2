#include <iostream>

#include "bicicleteria.h"
#include "parte.h"
using namespace std;
int main()
{
    Bicicleteria g;
    // Crear partes
    Parte* p1 = new Parte(1, "Cuadro aluminio", 50000.0);
    Parte* p2 = new Parte(2, "Rueda MTB 29''", 20000);
    Parte* p3 = new Parte(3, "Asiento ergonomico", 8000);
    Parte* p4 = new Parte(4, "Manubrio", 15000);
    Parte* p5 = new Parte(5, "Luces LED", 3000);
    Parte* p6 = new Parte(6, "Casco", 12000);

    // Registrar partes
    g.agregarParte(p1);
    g.agregarParte(p2);
    g.agregarParte(p3);
    g.agregarParte(p4);
    g.agregarParte(p5);
    g.agregarParte(p6);

    //Crear bicicletas
    Bicicleta* b1 = new Bicicleta(101, "Bicicleta Montania");
    b1->agregarParte(p1);
    b1->agregarParte(p2);
    b1->agregarParte(p3);
    b1->agregarParte(p4);

    Bicicleta* b2 = new Bicicleta(102, "Bicicleta Urbana");
    b2->agregarParte(p1);
    b2->agregarParte(p2);
    b2->agregarParte(p3);

    Bicicleta* b3 = new Bicicleta(103, "Bicicleta Infantil");
    b3->agregarParte(p1);
    b3->agregarParte(p3);
    b3->agregarParte(p5);

    // Registrar bicicletas
    g.agregarBicicleta(b1);
    g.agregarBicicleta(b2);
    g.agregarBicicleta(b3);

    // Crear ofertas (20% off)
    Oferta* o1 = new Oferta(201, "Promo Primavera");
    o1->agregarItem(b1);
    o1->agregarItem(p6);
    g.agregarOferta(o1);

    Oferta* o2 = new Oferta(202, "Promo Familiar");
    o2->agregarItem(b2);
    o2->agregarItem(b3);
    o2->agregarItem(p5);
    g.agregarOferta(o2);

    //Guardar en archivos
    // Guardar en archivos binarios
    g.guardarPartesBinario("partes.dat");
    g.guardarBicicletasBinario("bicicletas.dat", "bicicletas_partes.dat");
    g.guardarOfertasBinario("ofertas.dat", "ofertas_items.dat");

    cout << "\n=== Guardar ofertas en txt ===" << endl;
    g.guardarOfertasTxt("ofertas.txt");


    //Mostrar bicicletas más caras
    cout << "\n=== Bicicletas mas caras ===" << endl;
    auto masCaras = g.bicisMasCaras();
    for (auto b : masCaras)
        cout << b->getNumero() << " " << b->getDescripcion() << " $" << b->getPrecio() << endl;

    //Parte más usada
    cout << "\n=== Parte mas usada ===" << endl;
    Parte* masUsada = g.parteMasUsada();
    if (masUsada)
        cout << masUsada->getNumero() << " " << masUsada->getDescripcion() << " $" << masUsada->getPrecio() << endl;

    // Bicicleta más compleja
    cout << "\n=== Bicicleta con mas partes ===" << endl;
    Bicicleta* masCompleja = g.bicicletaMasCompleja();
    if (masCompleja)
    {
        cout << masCompleja->getNumero() << " " << masCompleja->getDescripcion() << " $" << masCompleja->getPrecio() << endl;
        for (auto c : masCompleja->getPartes())
            cout << "   " << c->getNumero() << " " << c->getDescripcion() << " $" << c->getPrecio() << endl;
    };
    return 0;   // ~Bicicleteria libera partes, bicicletas y ofertas
}
