
#include "turismo.h"
#include <iomanip>


int main(){

    Turismo turismo;

    // =====================================================
    // SERVICIOS INDIVIDUALES
    // =====================================================

    Vuelo *v1 = new Vuelo(
                1,
                "Buenos Aires - Madrid",
                1200,
                "Buenos Aires",
                "Madrid"
                );

    Vuelo *v2 = new Vuelo(
                2,
                "Madrid - Paris",
                900,
                "Madrid",
                "Paris"
                );

    Vuelo *v3 = new Vuelo(
                3,
                "Buenos Aires - Roma",
                1100,
                "Buenos Aires",
                "Roma"
                );

    Vuelo *v4 = new Vuelo(
                4,
                "Roma - Madrid",
                1400,
                "Roma",
                "Madrid"
                );

    Vuelo *v5 = new Vuelo(
                5,
                "Madrid - Londres",
                1250,
                "Madrid",
                "Londres"
                );


    Hotel *h1 = new Hotel(
                10,
                "Hotel Madrid Centro",
                5
                );

    Hotel *h2 = new Hotel(
                11,
                "Hotel Paris",
                4
                );

    Hotel *h3 = new Hotel(
                12,
                "Hotel Roma",
                6
                );

    Hotel *h4 = new Hotel(
                13,
                "Hotel Londres",
                3
                );


    Excursion *e1 = new Excursion(
                20,
                "Excursion Toledo",
                2
                );

    Excursion *e2 = new Excursion(
                21,
                "Excursion Torre Eiffel",
                1
                );

    Excursion *e3 = new Excursion(
                22,
                "Excursion Coliseo",
                2
                );

    Excursion *e4 = new Excursion(
                23,
                "Excursion Londres",
                3
                );


    // =====================================================
    // PAQUETE ESPAÑA
    // =====================================================

    Paquete *espana =
            new Paquete(100, "Espana");

    espana->agregar(h1);
    espana->agregar(e1);


    // =====================================================
    // PAQUETE FRANCIA
    // =====================================================

    Paquete *francia =
            new Paquete(101, "Francia");

    francia->agregar(h2);
    francia->agregar(e2);


    // =====================================================
    // PAQUETE ITALIA
    // =====================================================

    Paquete *italia =
            new Paquete(102, "Italia");

    italia->agregar(h3);
    italia->agregar(e3);


    // =====================================================
    // PAQUETE INGLATERRA
    // =====================================================

    Paquete *inglaterra =
            new Paquete(103, "Inglaterra");

    inglaterra->agregar(h4);
    inglaterra->agregar(e4);


    // =====================================================
    // PAQUETE EUROPA
    // =====================================================

    Paquete *europa =
            new Paquete(200, "Europa");

    europa->agregar(v1);
    europa->agregar(espana);
    europa->agregar(v2);
    europa->agregar(francia);


    // =====================================================
    // PAQUETE GRAN EUROPA
    // =====================================================

    Paquete *granEuropa =
            new Paquete(300, "Gran Europa");

    granEuropa->agregar(europa);
    granEuropa->agregar(v3);
    granEuropa->agregar(italia);
    granEuropa->agregar(v4);
    granEuropa->agregar(inglaterra);
    granEuropa->agregar(v5);


    // =====================================================
    // REGISTRAMOS LOS OBJETOS EN TURISMO
    // =====================================================

    turismo.agregarServicio(v1);
    turismo.agregarServicio(v2);
    turismo.agregarServicio(v3);
    turismo.agregarServicio(v4);
    turismo.agregarServicio(v5);

    turismo.agregarServicio(h1);
    turismo.agregarServicio(h2);
    turismo.agregarServicio(h3);
    turismo.agregarServicio(h4);

    turismo.agregarServicio(e1);
    turismo.agregarServicio(e2);
    turismo.agregarServicio(e3);
    turismo.agregarServicio(e4);

    turismo.agregarServicio(espana);
    turismo.agregarServicio(francia);
    turismo.agregarServicio(italia);
    turismo.agregarServicio(inglaterra);

    turismo.agregarServicio(europa);
    turismo.agregarServicio(granEuropa);
    //Antes de imprimir seteo la presicion numerica
    cout << fixed << setprecision(0);
    // =====================================================
    // PRUEBAS
    // =====================================================
    turismo.imprimirPrecios();
    turismo.guardarBinario();
    //turismo.cargarBinario();
    auto lista=turismo.cincoMasCaros();
    cout<<"\n5 PAQUETES MAS CAROS\n";
    for(auto p:lista)
        cout<<p->getDescripcion()
           <<" $"<<p->calcularPrecio()<<endl;


    auto mapa=turismo.vuelosPorOrigen();

    cout<<"\nVUELOS POR CIUDAD DE ORIGEN\n";

    for(auto par:mapa){

        cout<<par.first
           <<" : "<<par.second<<endl;
    }
    turismo.guardarTexto("precios.txt");

    return 0;
}




