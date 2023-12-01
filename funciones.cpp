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
void AgregarBitacoraUsu(Bitacora_usu nuevabitacora)
{
    bitacora.push_back(nuevabitacora);
}
void AgregarBitacoraProd(Bitacora_prod nuevabitacora)
{
    bitacoraprod.push_back(nuevabitacora);
}
void AgregarBitacoraVen(Bitacora_ven nuevabitacora)
{
    bitacoraven.push_back(nuevabitacora);
}
void ImprimirBitacoraUsu(string nombre)
{
    // for off
    for (Bitacora_usu bitacora : bitacora)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego un usuario")
            {
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario ingresado fue el: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario ingresado es jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario ingresado es empleado administrador" << endl;
                    }
                        
                }
            } else if (bitacora.accion == "Se modifico un usuario")
            {
                
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario modificado fue: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario es jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario es empleado administrador" << endl;
                    }
                        
                }
            } else
            {
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario eliminado fue: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario era jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario era empleado administrador" << endl;
                    }
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}
void ImprimirBitacoraPro(string nombre)
{
    // for off
    for (Bitacora_prod bitacora : bitacoraprod)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego un producto")
            {
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto ingresado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente es: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta sera de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            } else if (bitacora.accion == "Se modifico un producto")
            {
                
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto modificado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente es: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta sera de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            } else
            {
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto eliminado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente fue: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta fue de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}
void ImprimirBitacoraVen(string nombre)
{
    // for off
    for (Bitacora_ven bitacora : bitacoraven)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego una venta")
            {
                if (bitacora.venta_afectada == bitacora.ventas.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El numero de venta es: $" << bitacora.ventas.identificador << endl;
                    cout << "El nombre del consumidor es: $" << bitacora.ventas.nombre_consumidor << endl;
                    cout << "El producto vendido fue el: " << bitacora.venta_afectada << endl;
                    cout << "El numero de lote utilizado fue: " << bitacora.ventas.lote << endl;
                    cout << "La cantidad vendida fue de: " << bitacora.ventas.cantidad << endl;
                    cout << "El precio final fue de: $" << bitacora.ventas.precio_total << endl;
                    
                        
                }
            }  else
            {
                if (bitacora.venta_afectada == bitacora.ventas.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El numero de venta fue: $" << bitacora.ventas.identificador << endl;
                    cout << "El nombre del consumidor fue: $" << bitacora.ventas.nombre_consumidor << endl;
                    cout << "El producto vendido fue el: " << bitacora.venta_afectada << endl;
                    cout << "El numero de lote utilizado fue: " << bitacora.ventas.lote << endl;
                    cout << "La cantidad vendida fue de: " << bitacora.ventas.cantidad << endl;
                    cout << "El precio final fue de: $" << bitacora.ventas.precio_total << endl;
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}


