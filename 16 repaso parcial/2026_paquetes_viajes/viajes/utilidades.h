#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "componente.h"
#include "paquete.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>

// Punto 1: imprime codigo, descripcion y precio de TODOS los servicios
// (Vuelo/Hotel/Excursion), recorriendo recursivamente el arbol de paquetes.
void imprimirPreciosServicios(const std::vector<std::unique_ptr<Componente>>& raices,
                               std::ostream& os = std::cout);

// Punto 2: guarda una coleccion de componentes raiz (paquetes y/o
// servicios sueltos) en un unico archivo binario.
void guardarComponentesBinario(const std::vector<std::unique_ptr<Componente>>& raices,
                                const std::string& archivo);

// Punto 2: reconstruye la coleccion desde el archivo generado arriba.
std::vector<std::unique_ptr<Componente>> cargarComponentesBinario(const std::string& archivo);

// Punto 3.1 (STL: std::vector + std::partial_sort): los 5 paquetes mas
// caros considerando TODOS los paquetes del arbol (incluye subpaquetes).
std::vector<const Paquete*> obtenerTop5PaquetesMasCaros(
    const std::vector<std::unique_ptr<Componente>>& raices);

// Punto 3.2 (STL: std::map): cantidad de vuelos agrupados por ciudad de origen.
std::map<std::string, int> obtenerCantidadVuelosPorOrigen(
    const std::vector<std::unique_ptr<Componente>>& raices);

// Punto 4: guarda en un archivo de texto (una linea por servicio) los
// precios de todos los servicios.
void guardarPreciosTexto(const std::vector<std::unique_ptr<Componente>>& raices,
                          const std::string& archivo);

#endif // UTILIDADES_H
