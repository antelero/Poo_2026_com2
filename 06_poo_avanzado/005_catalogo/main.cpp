#include <iostream>
#include "autor.h"
#include "cancion.h"
#include "disco.h"
#include "catalogo.h"

/*
5. Deseamos diseñar un software que mantenga los catálogos de la música, una canción tiene
un autor que pudo componer varias canciones. A la vez un disco esta compuesto por un
conjunto de canciones que no necesariamente son de un solo autor
*/
using namespace std;

int main()
{
    Autor *a1 = new Autor("autor 1");
    Autor *a2 = new Autor("Autor 2");

    Cancion *cancion1 = new Cancion("Una cancion",a1, 2.5);
    Cancion * cancion2 = new Cancion("Otra cancion",a2,3.1);

    Disco *disco1 = new Disco("Disco principal");
    disco1->addCancion(cancion1);
    disco1->addCancion(cancion2);

    Catalogo * cata = new Catalogo("Catalogo 1");

    /*
     * cout << "   Disco:" << disco1->getNombreDisco() << " Cant:" << disco1->getCant() << endl;
    for (int i=0; i< disco1->getCant(); i++)
        cout << "       Cancion:"  << disco1->getCancion(i)->getNombreCancion()
             << " duracion:" << disco1->getCancion(i)->getDuracion()
             << " autor:" << disco1->getCancion(i)->getAut()->getNombreAutor() <<endl;
    */

    Disco * disco2 = new Disco("Otro disco");
    Autor *biza = new Autor("Bizarrap");
    Cancion *c22 = new Cancion("cancion 1", biza, 4);
    Cancion *c23 = new Cancion("Cancion 2", biza, 5);
    Cancion *c24 = new Cancion("Cancion 3", biza, 1.5);
    disco2->addCancion(c22);
    disco2->addCancion(c23);
    disco2->addCancion(c24);

    cata->addDisco(disco1);
    cata->addDisco(disco2);

    cout << "Cata: " << cata->getNombreCatalogo() << " Discos:" <<
            cata->getCant() << " Dur:" << cata->getDuracion() <<endl;
    for(int i=0; i<cata->getCant();i++){
        cout << "   Disco: " << cata->getDisco(i)->getNombreDisco() <<  " cant:"
             << cata->getDisco(i)->getCant() << " Dur:" <<cata->getDisco(i)->getDuracion() << endl;
        for (int j=0; j<cata->getDisco(i)->getCant();j++)
        {
            cout << "       Cancion:" << cata->getDisco(i)->getCancion(j)->getNombreCancion() <<
                    "  " << cata->getDisco(i)->getCancion(j)->getAut()->getNombreAutor() <<
                    " Duracion " << cata->getDisco(i)->getCancion(j)->getDuracion() << endl;
        }
    }
    return 0;
}
