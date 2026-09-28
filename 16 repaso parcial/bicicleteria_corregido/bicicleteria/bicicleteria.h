#ifndef BICICLETERIA_H
#define BICICLETERIA_H
#include <string>
#include <vector>
#include "bicicleta.h"
#include "oferta.h"

/* ---- Registros de los archivos binarios (tamaño fijo) ---- */
struct strParte {
    int numero;
    char descripcion[200];
    double precio;
};

// El precio de la bicicleta NO se guarda: es un dato derivado (suma de partes)
struct strBicicleta {
    int numero;
    char descripcion[200];
};

struct strBicicletaParte {
    int idBicicleta;
    int idParte;
};

// El precio de la oferta tampoco se guarda (se calcula)
struct strOferta {
    int numero;
    char descripcion[200];
};

// tipo: 'P' = Parte, 'B' = Bicicleta, 'O' = Oferta
// (hace falta porque los numeros de partes y bicicletas pueden coincidir)
struct strOfertaItem {
    int idOferta;
    char tipo;
    int idItem;
};

/*
 * LIBRE: otros costos (mano de obra %, impuestos 21%, costos fijos)
 * ------------------------------------------------------------------
 * Cambio de diseño: hoy el precio es una suma directa. Pasaría a:
 *     precio = (suma_partes * (1 + %manoDeObra) + costoFijo) * 1.21
 * Lo implementaría con una clase/estrategia PoliticaDePrecio (o un decorador)
 * que se le inyecta a Bicicleta; Parte, Oferta y Bicicleteria casi no cambian
 * porque siguen usando getPrecio() polimórficamente. Hay que definir si el
 * 20% de la oferta se descuenta antes o después de impuestos.
 *
 * Almacenamiento: en strBicicleta se agregan porcentajeManoObra y costoFijo
 * (datos base). El IVA (21%) va como constante o en un archivo de
 * configuración. NO se guarda el precio final: es derivado y quedaría
 * desactualizado al cambiar los parámetros; se recalcula al cargar.
 */
class Bicicleteria {
private:
    std::vector<Parte*> partes;
    std::vector<Bicicleta*> bicicletas;
    std::vector<Oferta*> ofertas;
public:
    Bicicleteria() = default;
    ~Bicicleteria();                                   // libera todo lo agregado
    Bicicleteria(const Bicicleteria&) = delete;        // es dueña de punteros
    Bicicleteria& operator=(const Bicicleteria&) = delete;

    // La bicicleteria pasa a ser dueña de lo que se agrega
    void agregarParte(Parte* p);
    void agregarBicicleta(Bicicleta* b);
    void agregarOferta(Oferta* o);

    // Archivos binarios
    void guardarPartesBinario(const std::string& archivo) const;
    void guardarBicicletasBinario(const std::string& archivoBicis,
                                  const std::string& archivoBiciPartes) const;
    void guardarOfertasBinario(const std::string& archivoOfertas,
                               const std::string& archivoOfertaItems) const;

    // Archivo de texto
    void guardarOfertasTxt(const std::string& archivo) const;

    // Consultas (STL)
    std::vector<Bicicleta*> bicisMasCaras() const;
    Bicicleta* bicicletaMasCompleja() const;
    Parte* parteMasUsada() const;
};

#endif // BICICLETERIA_H
