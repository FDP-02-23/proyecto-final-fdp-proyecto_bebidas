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
void ImprimirLotes(string nombre)
{
    for (Bebida bebida : packs)
    {
        if (nombre == bebida.nombre_bebida)
        {
            cout << endl;
            cout << " El numero de lote es: " << bebida.lote << endl
                 << " El tipo de pack es: " << bebida.tipo_bebida << endl
                 << " La cantidad de packs comprados es de: " << bebida.cantidad << endl
                 << " El precio de venta por pack sera de: $" << bebida.precio_venta << endl
                 << " La ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio / bebida.cantidad)) << endl;
        }
    }
    cout << "\n\n";
}
void ModificarStock(int lote, int cantidad)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (lote == packs[i].lote)
        {
            packs[i].cantidad = packs[i].cantidad - cantidad;
        }
    }
}
void ModificarStockDevolucion(int lote, int cantidad, string nombrebebida)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (lote == packs[i].lote && nombrebebida == packs[i].nombre_bebida)
        {
            packs[i].cantidad = packs[i].cantidad + cantidad;
        }
    }
}
float BuscarPrecioVenta(int lote)
{
    float contadorventa;
    for (Bebida bebida : packs)
    {
        if (lote == bebida.lote)
        {
            contadorventa = bebida.precio_venta;
        }
    }
    return contadorventa;
}

