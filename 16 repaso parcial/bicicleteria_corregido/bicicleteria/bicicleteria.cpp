#include "bicicleteria.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>

Bicicleteria::~Bicicleteria() {
    for (Oferta* o : ofertas) delete o;
    for (Bicicleta* b : bicicletas) delete b;
    for (Parte* p : partes) delete p;
}

void Bicicleteria::agregarParte(Parte *p)         { partes.push_back(p); }
void Bicicleteria::agregarBicicleta(Bicicleta *b) { bicicletas.push_back(b); }
void Bicicleteria::agregarOferta(Oferta *o)       { ofertas.push_back(o); }

// Copia segura de la descripcion a un char[200]
static void copiarDesc(char (&dest)[200], const char* origen) {
    std::strncpy(dest, origen, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
}

// ----------------------------------------------------
// Partes -> binario
// ----------------------------------------------------
void Bicicleteria::guardarPartesBinario(const std::string& archivo) const {
    std::ofstream out(archivo, std::ios::binary);
    if (!out) {
        std::cerr << "Error al abrir " << archivo << std::endl;
        return;
    }
    for (const Parte* p : partes) {
        strParte reg{};                       // inicializado en 0 (sin basura)
        reg.numero = p->getNumero();
        copiarDesc(reg.descripcion, p->getDescripcion());
        reg.precio = p->getPrecio();
        out.write((char*)(&reg), sizeof(strParte));
    }
    std::cout << "Partes guardadas en " << archivo << std::endl;
}

// ----------------------------------------------------
// Bicicletas -> binario (+ tabla de relacion bicicleta-parte)
// ----------------------------------------------------
void Bicicleteria::guardarBicicletasBinario(const std::string& archivoBicis,
                                            const std::string& archivoBiciPartes) const {
    std::ofstream outBicis(archivoBicis, std::ios::binary);
    std::ofstream outRel(archivoBiciPartes, std::ios::binary);
    if (!outBicis || !outRel) {
        std::cerr << "Error al abrir archivos de bicicletas\n";
        return;
    }
    for (const Bicicleta* b : bicicletas) {
        strBicicleta reg{};
        reg.numero = b->getNumero();
        copiarDesc(reg.descripcion, b->getDescripcion());
        outBicis.write(reinterpret_cast<const char*>(&reg), sizeof(strBicicleta));

        for (const Parte* p : b->getPartes()) {
            strBicicletaParte rel{};
            rel.idBicicleta = b->getNumero();
            rel.idParte = p->getNumero();
            outRel.write(reinterpret_cast<const char*>(&rel), sizeof(strBicicletaParte));
        }
    }
    std::cout << "Bicicletas guardadas en " << archivoBicis
              << " y " << archivoBiciPartes << std::endl;
}

// ----------------------------------------------------
// Ofertas -> binario (+ tabla de relacion oferta-item con tipo)
// ----------------------------------------------------
void Bicicleteria::guardarOfertasBinario(const std::string& archivoOfertas,
                                         const std::string& archivoOfertaItems) const {
    std::ofstream outOf(archivoOfertas, std::ios::binary);
    std::ofstream outIt(archivoOfertaItems, std::ios::binary);
    if (!outOf || !outIt) {
        std::cerr << "Error al abrir archivos de ofertas\n";
        return;
    }
    for (const Oferta* o : ofertas) {
        strOferta reg{};
        reg.numero = o->getNumero();
        copiarDesc(reg.descripcion, o->getDescripcion());
        outOf.write(reinterpret_cast<const char*>(&reg), sizeof(strOferta));

        for (const Item* it : o->getItems()) {
            strOfertaItem rel{};
            rel.idOferta = o->getNumero();
            rel.idItem = it->getNumero();
            // Downcast para saber de que tipo es el item
            if (dynamic_cast<const Parte*>(it))          rel.tipo = 'P';
            else if (dynamic_cast<const Bicicleta*>(it)) rel.tipo = 'B';
            else                                         rel.tipo = 'O';
            outIt.write(reinterpret_cast<const char*>(&rel), sizeof(strOfertaItem));
        }
    }
    std::cout << "Ofertas guardadas en " << archivoOfertas
              << " y " << archivoOfertaItems << std::endl;
}

// ----------------------------------------------------
// Ofertas -> texto (usa operator<<)
// ----------------------------------------------------
void Bicicleteria::guardarOfertasTxt(const std::string& archivo) const {
    std::ofstream out(archivo);
    if (!out) {
        std::cerr << "Error: no se pudo abrir " << archivo << std::endl;
        return;
    }
    for (const Oferta* o : ofertas)
        out << *o << "\n";
}

// ----------------------------------------------------
// Consultas con STL
// ----------------------------------------------------
std::vector<Bicicleta*> Bicicleteria::bicisMasCaras() const {
    std::vector<Bicicleta*> resultado;
    if (bicicletas.empty())
        return resultado;

    auto it = std::max_element(bicicletas.begin(), bicicletas.end(),
        [](const Bicicleta* a, const Bicicleta* b) {
            return a->getPrecio() < b->getPrecio();
        });
    const double maximo = (*it)->getPrecio();

    std::copy_if(bicicletas.begin(), bicicletas.end(), std::back_inserter(resultado),
        [maximo](const Bicicleta* b) { return b->getPrecio() == maximo; });
    return resultado;
}

Bicicleta* Bicicleteria::bicicletaMasCompleja() const {
    if (bicicletas.empty())
        return nullptr;
    auto it = std::max_element(bicicletas.begin(), bicicletas.end(),
        [](const Bicicleta* a, const Bicicleta* b) {
            return a->getPartes().size() < b->getPartes().size();
        });
    return *it;
}

Parte* Bicicleteria::parteMasUsada() const {
    std::map<int, int> contador;              // numero de parte -> cantidad de usos
    for (const Bicicleta* b : bicicletas)
        for (const Parte* p : b->getPartes())
            contador[p->getNumero()]++;

    if (contador.empty())
        return nullptr;

    auto it = std::max_element(contador.begin(), contador.end(),
        [](const std::pair<const int,int>& a, const std::pair<const int,int>& b) {
            return a.second < b.second;
        });

    auto pit = std::find_if(partes.begin(), partes.end(),
        [&](const Parte* p) { return p->getNumero() == it->first; });
    return pit != partes.end() ? *pit : nullptr;
}
