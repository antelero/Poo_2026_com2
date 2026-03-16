#include <iostream>
/*
Ejercicio 2
Escribir un programa C++ que calcule el importe de una factura sabiendo que el IVA a aplicar
es del 13% y que si el importe bruto de la factura es superior a 50, se debe realizar un
descuento del 5%.
*/
using namespace std;
double importe_factura(double importe);
int iva = 13;
int desc = 5;
int main()
{

    cout << "Facturas" << endl;
    cout << "Monto " << 100 << "  " << importe_factura(100)<< endl;
    cout << "Monto " << 25 << "  " <<importe_factura(25)<< endl;
    return 0;
}
double importe_factura(double importe)
{

    importe = importe + (importe * iva)/100;
    if (importe>50){
        importe = importe - (importe * desc)/100;
    }
    return importe;
}
