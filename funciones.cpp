//Archivo que se encarga de la definicion de funciones 

#include "encabezado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

//Vectores utilizados
vector<Bebida> packs;
vector<Usuarios> usuario;

// Imprimir la fecha actual
string GetCurrentDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    return to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
}
// Imprimir informacion de bebidas existentes
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
// Imprimir el numero de lote y la informacion de este
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

// Agregar bebida al vector
void AgregarBebida(Bebida nuevaBebida)
{
    packs.push_back(nuevaBebida);
}
// Buscar bebida por packs 
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
// Buscar y modificar una bebida existente
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
// Eliminar bebida existente
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

void InicializarUsuarios() {
    usuario.push_back({"admin123", "123", 1, "system"});
    usuario.push_back({"admin456", "456", 1, "system"});
    usuario.push_back({"admin789", "789", 2, "admin123"});
}
int BuscarUsuario()
{
    int tipo_usu = 0;
    string nombre_usuario;
    string contrasenia;
    do
    {
        system("cls");
        // Encabezado del sistema
        cout << endl;
        cout << "             ------PEPITO'S------" << endl;
        cout << "   ------- DISTRIBUIDORA DE BEBIDAS -------" << endl;
        cout << endl;
        cout << "        En vez de una, llevate varias" << endl;
        cout << endl;

        cout << "*************************************************" << endl;
        cout << "Ingrese su usuario: ";
        cin >> nombre_usuario;
        cout << "Ingrese su clave: ";
        cin >> contrasenia;
        cin.ignore();
        cout << endl;

        for (Usuarios usuarioActual : usuario)
        {
            if (nombre_usuario == usuarioActual.usuario)
            {
                if (usuarioActual.contrasenia == contrasenia)
                {
                    if (usuarioActual.tipo_usuario == 1)
                    {
                        tipo_usu = 1;
                    }
                    else
                    {
                        tipo_usu = 2;
                        break;
                    }
                }
            }
        }
        if (tipo_usu == 0)
        {
            cout << " Credenciales incorrectas!" << endl;
            cout << endl;
            system("pause");
        }

    } while (tipo_usu == 0);
    return tipo_usu;
}
void AgregarUsuarios(Usuarios nuevoUsuario)
{
    // Variable dentro de la funcion encargada de verificar si existe el usuario y dependiendo del valor retornara 1 si no existe
    for (int i = 0; i < usuario.size(); i++)
    {
        if (nuevoUsuario.usuario == usuario[i].usuario)
        {
            cout << " Usuario ya axistente! Por favor agregue un usuario valido\n";
            cout << endl;
            return;
        }
    }
    usuario.push_back(nuevoUsuario);
    cout << " Usuario agregado existosamente\n";
    cout << endl;
    return;
}
void ModificarUsuario(string nombreUsuario) // Funcion que se encarga de modificar al usuario
{
    string nuevoNombre;
    string contrasenia;
    int tipo;

    for (int i = 0; i < usuario.size(); i++)
    {
        if (nombreUsuario == usuario[i].usuario)
        {
            cout << endl;
            cout << " Ingrese el nuevo nombre de usuario: ";
            cin >> nuevoNombre;
            cout << " Ingrese la nueva clave: ";
            cin >> contrasenia;
            cout << endl;
            cout << " Ingrese el nuevo tipo de usuario:\n (1) Si es administrador\n (2) Si es empleado\n >";
            cin >> tipo;
            cout << endl;

            usuario[i].usuario = nuevoNombre;
            usuario[i].contrasenia = contrasenia;
            usuario[i].tipo_usuario = tipo;

            cout << " Usuario modificado exitosamente\n";
            cout << endl;
            return;
        }
    }
    cout << " No se ha encontrado el usuario!" << endl;
}
void ImprimirUsuarios()
{
    cout << " Usuarios existentes: " << endl;
    for (Usuarios imprimir : usuario)
    {
        cout << " > " << imprimir.usuario << endl;
    }
    cout << endl;
}
void EliminarUsuario(string usuarioEliminar)
{
    for (int i = 0; i < usuario.size(); i++)
    {
        if (usuarioEliminar == usuario[i].usuario)
        {
            usuario.erase(usuario.begin() + i);
            cout << " Usuario eliminado correctamente" << endl;
            return;
        }
    }
    cout << "El usuario no existe!" << endl;
}
int BuscarUsuario(string nombreusuario, string contrasenia)
{
    int tipo_usu = 0;
    int contador = 0;
    
    for (Usuarios usuario : usuario)
    {
        if (nombreusuario == usuario.usuario)
        {
            if(usuario.contrasenia == contrasenia){
                if(usuario.tipo_usuario == 1){
                    //cout << "Bienvenido usuario administrador" << endl;
                    tipo_usu = 1;
                    return tipo_usu;
                } else {
                    //cout << "Bienvenido empleado" << endl;
                    tipo_usu = 2;
                    return tipo_usu;
                }

            }
        }
    }
    cout << "No se ha encontrado el usuario" << endl;
    system("pause");
    return tipo_usu;
}
