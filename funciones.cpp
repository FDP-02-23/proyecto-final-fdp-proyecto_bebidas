#include "encabezado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

//Archivo que se encarga de la ejecucion de funciones

vector<Usuarios> usuario;

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