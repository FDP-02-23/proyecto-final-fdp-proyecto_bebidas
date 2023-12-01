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
void EliminarVenta(string nombreBebida, int identificador)
{
    for (int i = 0; i < venta.size(); i++)
    {
        if (nombreBebida == venta[i].nombre_bebida && identificador == venta[i].identificador)
        {
            venta.erase(venta.begin() + i);
            cout << " Venta eliminada correctamente y stock actualizado" << endl;
            cout << endl;
            return;
        }
    }
    cout << " No se ha encotrado la bebida! Ingresar bien el nombre o el lote" << endl;
}
void MostrarRegistro(string archivo)
{

    ifstream file(archivo);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No hay registros de ventas existentes!" << endl;
    }
}
void ImprimirVentas()
{
    for (Ventas venta : venta)
    {
        cout << endl;
        cout << GetCurrentDate() << endl;
        cout << " ID de venta: " << venta.identificador << endl;
        cout << " Nombre del Cliente: " << venta.nombre_consumidor << endl;
        cout << " Nombre Bebida: " << venta.nombre_bebida << endl;
        cout << " Cantidad de packs: " << venta.cantidad << endl;
        cout << " Numero de lote: " << venta.lote << endl;
        cout << " Total a pagar: $" << venta.precio_total << endl;
    }
    cout << "\n\n";
}

