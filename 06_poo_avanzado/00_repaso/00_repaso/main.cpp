#include <iostream>
#include "alumno.h"
#include "alumnoregular.h"
#include "examen.h"

using namespace std;

int main()
{
    Examen ex;
    AlumnoRegular *jose = new AlumnoRegular(2222222,"Jose", ex);
    cout << jose->mostrar()<< endl;

    AlumnoRegular *jorge = new AlumnoRegular(33333333,"Jorge", ex);
    cout << jorge->mostrar()<< endl;
    return 0;
}
