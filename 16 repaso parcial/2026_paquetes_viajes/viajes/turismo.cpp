#include "turismo.h"

void Turismo::agregarServicio(Servicio *s){
    servicios.push_back(s);
}

vector<Servicio *> Turismo::getServicios(){
    return servicios;
}

void Turismo::imprimirPrecios(){
    cout<<"LISTA DE SERVICIOS\n";
    for(auto s:servicios)
       cout << *s <<endl;
}

void Turismo::guardarBinario(){

    this->guardarServicios("servicios.dat");
    this->guardarComponentes("componentes.dat");
}

void Turismo::cargarBinario() {
    this->cargarServicios("servicios.dat");
    this->cargarComponentes("componentes.dat");
}


vector<Paquete*> Turismo::cincoMasCaros() {
    vector<Paquete*> lista;
    for (auto s : servicios) {
        Paquete *p = dynamic_cast<Paquete*>(s);
        if (p != nullptr)
            lista.push_back(p);
    }

    sort(lista.begin(), lista.end(),
        [](Paquete *a, Paquete *b) {
            return a->calcularPrecio() > b->calcularPrecio();
        });
    if (lista.size() > 5)
        lista.resize(5);
    return lista;
}

map<string, int> Turismo::vuelosPorOrigen()
{
    map<string, int> resultado;

    for(auto s : servicios)
    {
        Vuelo* v = dynamic_cast<Vuelo*>(s);
        if(v != nullptr)
            resultado[v->getOrigen()]++;
    }

    return resultado;
}


void Turismo::guardarTexto(string nombre){

    ofstream arch(nombre);

    for(auto s:servicios){

        arch<<s->getNumero()<<" "
            <<s->getDescripcion()
            <<" $"<<s->calcularPrecio()
            <<endl;
    }

    arch.close();
}

void Turismo::guardarServicios(string nombre) {
    ofstream arch(nombre, ios::binary);
    RegistroServicio reg;
    for(auto s : servicios) {
        reg.numero = s->getNumero();
        strcpy(reg.descripcion,
               s->getDescripcion().c_str());
        if(dynamic_cast<Vuelo*>(s)) {
            Vuelo *v = dynamic_cast<Vuelo*>(s);
            reg.tipo = 1;
            reg.dato1 = v->getKilometros();
            strcpy(reg.texto1,
                   v->getOrigen().c_str());
            strcpy(reg.texto2,
                   v->getDestino().c_str());
        }
        else if(dynamic_cast<Hotel*>(s)) {
            Hotel *h = dynamic_cast<Hotel*>(s);
            reg.tipo = 2;
            reg.dato1 = h->getNoches();
        }
        else if(dynamic_cast<Excursion*>(s)) {
            Excursion *e =
                dynamic_cast<Excursion*>(s);
            reg.tipo = 3;
            reg.dato1 = e->getDias();
        }
        else if(dynamic_cast<Paquete*>(s)) {
            reg.tipo = 4;
        }
        arch.write(
            (char*)&reg,
            sizeof(RegistroServicio)
        );
    }

    arch.close();
}

void Turismo::Turismo::cargarServicios(string nombre) {

    ifstream arch(nombre, ios::binary);
    RegistroServicio reg;

    while (arch.read((char*)&reg, sizeof(reg))) {

        Servicio *s = nullptr;

        switch(reg.tipo) {

        case 1: // Vuelo
            s = new Vuelo(reg.numero, reg.descripcion,
                          reg.dato1, reg.texto1, reg.texto2);
            break;

        case 2: // Hotel
            s = new Hotel(reg.numero, reg.descripcion,
                          reg.dato1);
            break;

        case 3: // Excursion
            s = new Excursion(reg.numero, reg.descripcion,
                              reg.dato1);
            break;

        case 4: // Paquete
            s = new Paquete(reg.numero, reg.descripcion);
            break;
        }

        servicios.push_back(s);
        indice[reg.numero] = s;
    }

    arch.close();
}

void Turismo::cargarComponentes(string nombre) {

    ifstream arch(nombre, ios::binary);
    RegistroComponente reg;

    while (arch.read((char*)&reg, sizeof(reg))) {

        Paquete *p = dynamic_cast<Paquete*>(indice[reg.numeroPaquete]);

        Servicio *comp = indice[reg.numeroComponente];

        if (p != nullptr && comp != nullptr)
            p->agregar(comp);
    }

    arch.close();
}
void Turismo::guardarComponentes(string nombre)
{
    ofstream arch(nombre, ios::binary);
    for(auto s : servicios)
    {
        Paquete *p = dynamic_cast<Paquete*>(s);
        if(p != nullptr)
        {
            for(auto componente : p->getComponentes())
            {
                RegistroComponente reg;
                reg.numeroPaquete = p->getNumero();
                reg.numeroComponente = componente->getNumero();
                arch.write(
                            (char*)&reg,
                            sizeof(RegistroComponente)
                            );
            }
        }
    }

    arch.close();
}
