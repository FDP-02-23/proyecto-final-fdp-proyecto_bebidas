#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "encabezado.h"


using namespace std;


//Menu principal
int main()
{
    // Declaracion de variables y estructuras

    Bebida bebida;           // Declaracion estructura
    Usuarios usuarios;       // Declaracion estructura
    Ventas ventas;           // Declaracion estructura
    int opcion;              // Variable encargada de evaluar la opcion ingresada por el cliente
    string nombre_usuario;   // Variable que captura el nombre de usuario
    string contrasenia;      // Variable que captura la clave
    int tipo_usuario;        // Variable encargada de capturar el tipo de usuario
    int sesion = 0;          // Variable que se encarga de cerrar sesion o mantenerla
    int contador = 0;        // Variable la navegabilidad del sistema
    int regresar = 0;        // Variable la navegabilidad del sistema
    int regresarmenupro = 0; // Variable la navegabilidad del sistema en el menu productos
    int regresarmenuusu = 0; // Variable la navegabilidad del sistema en el menu usuarios
    int regresarmenuven = 0; // Variable la navegabilidad del sistema en el menu ventas
    int opcion1;             // Variable encargada de evaluar la opcion ingresada por el cliente
    int lote = 0;            // Variable que sirve como identificador cada producto, generada automaticamente
    int identificador = 0;   // Variable que sirve como identificador unico cada venta

    // Insertar datos vector usuarios, administrador
    usuario.push_back({"admin123", "123", 1});
    usuario.push_back({"admin456", "456", 1});
    usuario.push_back({"admin789", "789", 2});

    do
    {
        system("cls");
        // Encabezado del sistema
        cout << endl;
        cout << "                ------PEPITO'S------" << endl;
        cout << "   ------- TIENDA DISTRIBUIDORA DE BEBIDAS -------" << endl;
        cout << endl;
        cout << "        En vez de una, llevate varias" << endl;
        cout << endl;
        cout << "*************************************************" << endl;
        
         // Llamamiento a la funcion de buscar usuario, encargada de verificar si es admin o empleado
        tipo_usuario = BuscarUsuario();

        do
        { // Do while el funcionamiento de regresar a menus anteriores
            system("cls");
            cout << endl;     
            switch (tipo_usuario)
            {
                case 1: 

                break; 

                case 2: 

                break; 

            default:
                break;
            }
        } while(contador == 0);
    } while(sesion == 0);
    return 0;
}