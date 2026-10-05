#include "obrasocial.h"

ObraSocial::ObraSocial()
{

}

void ObraSocial::inicializarPlanes() {
    planes['b'] = new Plan("basica.txt");
    planes['m'] = new Plan("medio.txt");
    planes['p'] = new Plan("premium.txt");
}

void ObraSocial::crearClientesBin()
{
    vector<strUsuario> registros = {
        {1, "Juan Perez", 'b', 10},
        {2, "Maria Lopez", 'm', 25},
        {3, "Carlos Gomez", 'p', 40},
        {4, "Ana Torres", 'm', 5},
        {5, "Luis Fernandez", 'b', 12},
        {6, "Sofia Ramirez", 'p', 33},
        {7, "Pedro Sanchez", 'b', 8},
        {8, "Lucia Alvarez", 'm', 19},
        {9, "Jorge Castro", 'p', 42},
        {10, "Laura Dominguez", 'm', 28}
    };

    ofstream arch("clientes.dat", ios::binary);
    if (!arch) {
        cerr << "Error al crear el archivo clientes.dat" << endl;
    }

    for (auto& r : registros)
        arch.write((char*)(&r), sizeof(strUsuario));

    arch.close();
    cout << "Archivo generado correctamente.\n";
}

void ObraSocial::cargarClientes(const string &nombreArchivo) {
    ifstream arch(nombreArchivo, ios::binary);
    if (!arch) {
        cerr << "No se pudo abrir el archivo binario de clientes." << endl;
        return;
    }
    strUsuario reg;
    while (arch.read((char*)&reg, sizeof(strUsuario))) {
        //Cliente c(reg.id, reg.nombre, reg.tipo, reg.cantidad, planes[reg.tipo]);
        //clientes.push_back(c);
        clientes.emplace_back(reg.id, reg.nombre, reg.tipo, reg.cantidad, planes[reg.tipo]);
    }
    arch.close();
}

vector<Cliente> ObraSocial::top5Usuarios() const {
    vector<Cliente> copia = clientes;
    sort(copia.begin(), copia.end(), [](const Cliente& a, const Cliente& b) {
        return a.getCantidad() > b.getCantidad();
    });
    if (copia.size() > 5)
        copia.resize(5);
    return copia;
}

vector<string> ObraSocial::todasLasPrestaciones() const {
    vector<string> todas;
    for (auto& par : planes) {
        for (auto& p : par.second->getPrestaciones())
            todas.push_back(p);
    }
    sort(todas.begin(), todas.end());
    todas.erase(unique(todas.begin(), todas.end()), todas.end());
    return todas;
}

vector<string> ObraSocial::prestacionesComunes() const {
    const auto& bas = planes.at('b')->getPrestaciones();
    const auto& med = planes.at('m')->getPrestaciones();
    const auto& pre = planes.at('p')->getPrestaciones();

    vector<string> comun;
    for (auto& p : bas) {
        if (find(med.begin(), med.end(), p) != med.end() &&
                find(pre.begin(), pre.end(), p) != pre.end())
            comun.push_back(p);
    }
    return comun;
}

void ObraSocial::crearArchivosPlanes() {
    vector<string> basica = {
        "consulta medica",
        "remedios gratuitos"
    };

    vector<string> medio = basica; // hereda las de básico
    medio.push_back("odontologia");
    medio.push_back("oftalmologia");

    vector<string> premium = medio; // hereda las de medio
    premium.push_back("internacion");

    auto escribirArchivo = [](const string& nombreArchivo, const vector<string>& prestaciones) {
        ofstream arch(nombreArchivo);
        if (!arch) {
            cerr << "Error al crear el archivo " << nombreArchivo << endl;
            return;
        }
        for (const auto& p : prestaciones)
            arch << p << "\n";
        arch.close();
    };

    escribirArchivo("basica.txt", basica);
    escribirArchivo("medio.txt", medio);
    escribirArchivo("premium.txt", premium);

    cout << "Archivos de planes generados correctamente.\n";
}
