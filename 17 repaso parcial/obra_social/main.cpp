#include <iostream>
#include "obrasocial.h"
using namespace std;

int main() {
    ObraSocial os;
    // Generar archivo con datos
    os.crearClientesBin();
    os.crearArchivosPlanes();
    os.inicializarPlanes();    
    os.cargarClientes("clientes.dat");

    string prestacionAConsultar = "consulta medica";
    Cliente primero = os.getClientes()[0];
    cout << "\n " << primero.getNombre() << " tiene '" << prestacionAConsultar << "'? "
         << (primero.tienePrestacion(prestacionAConsultar) ? "Si" : "No") << endl;
    prestacionAConsultar = "odontologia";
    primero = os.getClientes()[0];
    cout << "\n " << primero.getNombre() << " tiene '" << prestacionAConsultar << "'? "
         << (primero.tienePrestacion(prestacionAConsultar) ? "Si" : "No") << endl;

    cout << "\nTop 5 usuarios que mas usaron el servicio:\n";
    for (auto& c : os.top5Usuarios())
        cout << c << endl;
    cout << "\nTodas las prestaciones disponibles:\n";
    for (auto& p : os.todasLasPrestaciones())
        cout << "- " << p << endl;

    cout << "\nCantidad de usos por tipo de plan:\n";
    for (auto& [tipo, total] : os.cantidadPorPlan())
        cout << tipo << " => " << total << endl;

    cout << "\nPrestaciones comunes en todos los planes:\n";
    for (auto& p : os.prestacionesComunes())
        cout << "- " << p << endl;

    return 0;
}
