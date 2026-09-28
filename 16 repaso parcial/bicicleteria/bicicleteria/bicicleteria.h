#ifndef BICICLETERIA_H
#define BICICLETERIA_H
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "bicicleta.h"
#include "oferta.h"


using namespace std;

struct strParte{
    int numero;
    char descripcion[200];
    double precio;
};
struct strBicicleta {
    int numero;
    char descripcion[200];
    double precio; // si la bici tiene un precio, podés quitarlo si no lo usa
};

struct strBicicletaParte {
    int idBicicleta;
    int idParte;
};

class Bicicleteria {
private:
    vector<Parte*> partes;
    vector<Bicicleta*> bicicletas;
    vector<Oferta*> ofertas;
public:

    void agregarParte(Parte* p);
    void agregarBicicleta(Bicicleta* b);
    void agregarOferta(Oferta* o);


    void guardarOfertasTxt(const string& nombreArchivo) const;
    void guardarPartesBinario(const string &nombreArchivo) const;
    vector<Bicicleta *> bicisMasCaras();
    Bicicleta *bicicletaMasCompleja() const;
    Parte *parteMasUsada();
    void guardarBicicletasBinario(const std::string &archivoBicis, const std::string &archivoBiciPartes);
};

#endif // BICICLETERIA_H
