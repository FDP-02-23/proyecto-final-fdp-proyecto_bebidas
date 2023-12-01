#include "encabezado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

//Archivo que se encarga de la ejecucion de funciones
vector<Ventas> venta;
vector<Bitacora_usu> bitacora;
vector<Bitacora_prod> bitacoraprod;
vector<Bitacora_ven> bitacoraven;

void RegistrarVenta(Ventas venta)
{
    ofstream file;

    file.open("RegistroVentas.txt", ios::app);

    if (file.is_open())
    {
        file << "-------------------------------------------" << endl;
        file << "  Fecha de realizacion: " << GetCurrentDate() << endl;
        file << "  Nombre del consumidor: " << venta.nombre_consumidor << endl;
        file << "  Nombre de la bebida: " << venta.nombre_bebida << endl;
        file << "  Cantidad de packs: " << venta.cantidad << endl;
        file << "  Numero de lote: " << venta.lote << endl;
        file << "  Costo final: $" << venta.precio_total << endl;
        file.close();
    }
    else
    {
        cout << "Error al registrar la venta!" << endl;
    }
}
void AgregarVenta(Ventas nuevaVenta)
{
    venta.push_back(nuevaVenta);
}
