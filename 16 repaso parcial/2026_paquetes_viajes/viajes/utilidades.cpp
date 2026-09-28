#include "Utilidades.h"
#include "Servicio.h"
#include "Vuelo.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

namespace {

// Recorre recursivamente el arbol de componentes y aplica una funcion a
// cada Servicio hoja que encuentra (Vuelo, Hotel o Excursion).
template <typename Funcion>
void recorrerServicios(const Componente& c, Funcion f) {
    if (const auto* servicio = dynamic_cast<const Servicio*>(&c)) {
        f(*servicio);
    } else if (const auto* paquete = dynamic_cast<const Paquete*>(&c)) {
        for (const auto& hijo : paquete->getComponentes()) {
            recorrerServicios(*hijo, f);
        }
    }
}

// Recorre recursivamente el arbol acumulando en 'salida' TODOS los
// paquetes encontrados, incluidos los anidados dentro de otros paquetes.
void recolectarPaquetes(const Componente& c, std::vector<const Paquete*>& salida) {
    if (const auto* paquete = dynamic_cast<const Paquete*>(&c)) {
        salida.push_back(paquete);
        for (const auto& hijo : paquete->getComponentes()) {
            recolectarPaquetes(*hijo, salida);
        }
    }
}

} // namespace

void imprimirPreciosServicios(const std::vector<std::unique_ptr<Componente>>& raices,
                               std::ostream& os) {
    os << std::fixed << std::setprecision(2);
    for (const auto& raiz : raices) {
        recorrerServicios(*raiz, [&os](const Servicio& s) {
            os << "[" << s.getCodigo() << "] " << s.getDescripcion()
               << " - $" << s.getPrecio() << '\n';
        });
    }
}

void guardarComponentesBinario(const std::vector<std::unique_ptr<Componente>>& raices,
                                const std::string& archivo) {
    std::ofstream out(archivo, std::ios::binary);
    if (!out) {
        throw std::runtime_error("No se pudo abrir el archivo binario para escritura: " + archivo);
    }
    size_t cantidad = raices.size();
    out.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));
    for (const auto& c : raices) {
        c->guardarBinario(out);
    }
}

std::vector<std::unique_ptr<Componente>> cargarComponentesBinario(const std::string& archivo) {
    std::ifstream in(archivo, std::ios::binary);
    if (!in) {
        throw std::runtime_error("No se pudo abrir el archivo binario para lectura: " + archivo);
    }
    size_t cantidad = 0;
    in.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    std::vector<std::unique_ptr<Componente>> resultado;
    resultado.reserve(cantidad);
    for (size_t i = 0; i < cantidad; ++i) {
        resultado.push_back(Componente::leerBinario(in));
    }
    return resultado;
}

std::vector<const Paquete*> obtenerTop5PaquetesMasCaros(
    const std::vector<std::unique_ptr<Componente>>& raices) {
    std::vector<const Paquete*> paquetes;
    for (const auto& raiz : raices) {
        recolectarPaquetes(*raiz, paquetes);
    }

    size_t topN = std::min<size_t>(5, paquetes.size());
    std::partial_sort(paquetes.begin(),
                       paquetes.begin() + static_cast<std::ptrdiff_t>(topN),
                       paquetes.end(),
                       [](const Paquete* a, const Paquete* b) {
                           return a->getPrecio() > b->getPrecio();
                       });
    paquetes.resize(topN);
    return paquetes;
}

std::map<std::string, int> obtenerCantidadVuelosPorOrigen(
    const std::vector<std::unique_ptr<Componente>>& raices) {
    std::map<std::string, int> resultado;
    for (const auto& raiz : raices) {
        recorrerServicios(*raiz, [&resultado](const Servicio& s) {
            if (const auto* vuelo = dynamic_cast<const Vuelo*>(&s)) {
                resultado[vuelo->getOrigen()]++;
            }
        });
    }
    return resultado;
}

void guardarPreciosTexto(const std::vector<std::unique_ptr<Componente>>& raices,
                          const std::string& archivo) {
    std::ofstream out(archivo);
    if (!out) {
        throw std::runtime_error("No se pudo abrir el archivo de texto: " + archivo);
    }
    out << std::fixed << std::setprecision(2);
    for (const auto& raiz : raices) {
        recorrerServicios(*raiz, [&out](const Servicio& s) {
            out << s.getCodigo() << ";" << s.getDescripcion() << ";" << s.getPrecio() << '\n';
        });
    }
}
