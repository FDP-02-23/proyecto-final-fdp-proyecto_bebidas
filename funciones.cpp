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