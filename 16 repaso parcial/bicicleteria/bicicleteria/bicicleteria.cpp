#include "bicicleteria.h"
#include "bicicleta.h"
#include "oferta.h"

void Bicicleteria::agregarParte(Parte *p) {
    partes.push_back(p);
}

void Bicicleteria::agregarBicicleta(Bicicleta *b) {
    bicicletas.push_back(b);
}

void Bicicleteria::agregarOferta(Oferta *o) {
    ofertas.push_back(o);
}

// ----------------------------------------------------
// 1️ Guardar partes en archivo binario
// ----------------------------------------------------
void Bicicleteria::guardarPartesBinario(const string& nombreArchivo) const {
    ofstream out(nombreArchivo, ios::binary);
    if (!out) {
        cerr << "Error al abrir archivo de partes." << endl;
        return;
    }
    for (auto p : partes) {
        strParte reg;
        reg.numero = p->getNumero();
        // Copiamos la descripción de manera segura
        std::strncpy(reg.descripcion, p->getDescripcion(), sizeof(reg.descripcion) - 1);
        reg.descripcion[sizeof(reg.descripcion) - 1] = '\0';
        reg.precio = p->getPrecio();

        // Escribimos toda la estructura de una vez
        out.write((char*)(&reg), sizeof(strParte));
    }

    out.close();
    cout << " Partes guardadas en " << nombreArchivo << endl;
}

// ----------------------------------------------------
// 2️ Guardar bicicletas en archivo binario
// ----------------------------------------------------
void Bicicleteria::guardarBicicletasBinario( const std::string& archivoBicis,
                                             const std::string& archivoBiciPartes
                                             )
{
    std::ofstream outBicis(archivoBicis, std::ios::binary);
    std::ofstream outRelaciones(archivoBiciPartes, std::ios::binary);

    if (!outBicis || !outRelaciones) {
        std::cerr << "Error al abrir archivos\n";
        return;
    }

    for ( Bicicleta *b : this->bicicletas) {
        //Grabar la información principal de la bicicleta
        strBicicleta regBici;
        regBici.numero = b->getNumero();
        std::strncpy(regBici.descripcion, b->getDescripcion(), sizeof(regBici.descripcion) - 1);
        regBici.descripcion[sizeof(regBici.descripcion) - 1] = '\0';
        regBici.precio = b->getPrecio(); // si existe

        outBicis.write((char*)(&regBici), sizeof(strBicicleta));

        //Grabar las relaciones bicicleta–parte ---
        for (auto parte : b->getPartes()) {
            strBicicletaParte rel;
            rel.idBicicleta = b->getNumero();
            rel.idParte = parte->getNumero();
            outRelaciones.write((char*)(&rel), sizeof(strBicicletaParte));
        }
    }
    std::cout << "Archivos grabados correctamente\n";
}


void Bicicleteria::guardarOfertasTxt(const string& nombreArchivo) const
{
    ofstream out(nombreArchivo);
    if (!out) {
        cerr << "Error: Could not open file " << nombreArchivo << " for writing.\n";
        return;
    }

    for (Oferta* o : ofertas) {
        if (o) {
            out << *o << "\n";
        } else {
            cerr << "No hay datos para guardar.\n";
        }
    }
}


vector<Bicicleta *> Bicicleteria::bicisMasCaras()
{
    float maxPrecio = 0;
    vector<Bicicleta*> resultado;
    for (Bicicleta* b : bicicletas){
        double precio = b->getPrecio();
        if (precio > maxPrecio){
            maxPrecio = precio;
            resultado.clear();
            resultado.push_back(b);
        } else if (precio == maxPrecio){
            resultado.push_back(b);
        }
    }
    return resultado;
}

Bicicleta *Bicicleteria::bicicletaMasCompleja() const
{
    if (bicicletas.empty())
        return nullptr;
    auto it = std::max_element(bicicletas.begin(), bicicletas.end(),
                               [](const Bicicleta* a, const Bicicleta* b) {
        return a->getPartes().size() < b->getPartes().size();
    });
    return *it;
}

Parte *Bicicleteria::parteMasUsada()
{
    map<int, int> contador;
    for (Bicicleta* b : bicicletas){
        for (Parte* p : b->getPartes()){
            contador[p->getNumero()]++;
        }
    }
    int max = 0;
    int id = -1;
    for (auto& par : contador){
        if (par.second > max){
            max = par.second;
            id = par.first;
        }
    }
    for (Parte* p : partes){
        if (p->getNumero() == id)
            return p;
    }
    return nullptr;
}
