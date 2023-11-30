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
void AgregarBebida(Bebida nuevaBebida)
{
    packs.push_back(nuevaBebida);
}
int BuscarBebidaPack(int lote, string nombrebebida)
{
    int contadorpacks = 0;
    for (Bebida bebida : packs)
    {
        if (lote == bebida.lote && nombrebebida == bebida.nombre_bebida)
        {
            contadorpacks = bebida.cantidad;
        }
    }
    return contadorpacks;
}
int BuscarBebidapack6(string nombreBebida)
{
    int contadorpacks6 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 1)
            {
                contadorpacks6 = contadorpacks6 + bebida.cantidad;
            }
        }
    }
    return contadorpacks6;
}
int BuscarBebidapack12(string nombreBebida)
{
    int contadorpacks12 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 2)
            {
                contadorpacks12 = contadorpacks12 + bebida.cantidad;
            }
        }
    }
    return contadorpacks12;
}
int BuscarBebidapack24(string nombreBebida)
{
    int contadorpacks24 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 3)
            {
                contadorpacks24 = contadorpacks24 + bebida.cantidad;
            }
        }
    }
    return contadorpacks24;
}
// Funcion que se encarga de buscar al lote del producto usado
int BuscarLote(int identificador) 
{
    int lote = 0;
    for (Ventas ventas : venta)
    {
        if (identificador == ventas.identificador)
        {
            lote = ventas.lote;
        }
    }
    return lote;
}
void BuscaryModificarBebida(string nombreBebida, int lote)
{
    string nuevoNombre;
    int nuevoTipo;
    float nuevoPrecio;
    int nuevaCantidad;
    float nuevoPrecioVenta;

    for (int i = 0; i < packs.size(); i++)
    {
        cin.ignore();
        if (nombreBebida == packs[i].nombre_bebida && lote == packs[i].lote)
        {
            cout << " Nuevo nombre: ";
            getline(cin, nuevoNombre);
            cout << " Nuevo tipo de pack: ";
            cin >> nuevoTipo;
            cout << " Nueva cantidad: ";
            cin >> nuevaCantidad;
            cout << " Nuevo monto total invertido: $";
            cin >> nuevoPrecio;
            cout << " Nuevo precio de venta: $";
            cin >> nuevoPrecioVenta;

            packs[i].nombre_bebida = nuevoNombre;
            packs[i].tipo_bebida = nuevoTipo;
            packs[i].precio = nuevoPrecio;
            packs[i].cantidad = nuevaCantidad;
            packs[i].precio_venta = nuevoPrecioVenta;

            cout << endl;
            cout << " Bebida modificada exitosamente" << endl;
            return;
        }
    }
    cout << " No se ha encontrado la bebida!" << endl;
}
void EliminarBebida(string nombreBebida, int lote)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (nombreBebida == packs[i].nombre_bebida && lote == packs[i].lote)
        {
            packs.erase(packs.begin() + i);
            return;
        }
    }
    cout << " No se ha encotrado la bebida! Ingrese bien el nombre o el lote" << endl;
}


//Archivo que se encarga de la ejecucion de funciones