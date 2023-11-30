#include "encabezado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

//Vectores utilizados
vector<Bebida> packs;

//Definicion de Funciones

string GetCurrentDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    return to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
}
void ImprimirBebidas()
{
    for (Bebida bebida : packs)
    {
        cout << endl;
        cout << bebida.nombre_bebida << endl;
        cout << "  Numero de lote: " << bebida.lote << endl;
        cout << "  Tipo de pack: " << bebida.tipo_bebida << endl;
        cout << "  Precio total de compra invertido: $" << bebida.precio << endl;
        cout << "  Cantidad de packs comprados: " << bebida.cantidad << endl;
        cout << "  Precio de venta por pack sera de: $" << bebida.precio_venta << endl;
    }
    cout << "\n\n";
}

//Archivo que se encarga de la ejecucion de funciones