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
                // Menu principal Administrador
                cout << GetCurrentDate() << endl;
                cout << "***************************************" << endl;
                cout << "   ----- JEFE ADMINISTRADOR ----- " << endl;
                cout << "***************************************";
                cout << endl;
                cout << "Opciones: " << endl;
                cout << " (1) Manejo de usuarios" << endl;
                cout << " (2) Manejo de productos" << endl;
                cout << " (3) Registro de ventas diarias" << endl;
                cout << " (4) Mostrar bitacora" << endl;
                cout << " (5) Cerrar sesion\n >";
                cin >> opcion;
                cin.ignore();
                cout << endl;
                do
                {
                    system("cls");
                    cout << endl;
                    switch (opcion)
                    {
                    // Opcion 1 de menu Administrador
                    case 1: 
                    cout << "------- MANEJO DE USUARIOS ------- " << endl;
                    cout << endl;
                    break; 

                    // Opcion 2 de menu Administrador
                    case 2: 
                    cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                    cout << endl;
                    break; 

                    // Opcion 3 del menu Administrador
                    case 3: 
                    cout << endl; 
                    cout << "----- REGISTRO DE VENTAS DIARIAS ----- " << endl;
                    break; 

                    // Opcion 4 del menu Administrador
                    case 4: 
                    cout << "---------- BITACORA ---------- " << endl;
                    system("pause");
                    regresar = 1;
                    break; 

                     // Opcion 5 del menu Administrador
                    case 5: 
                        cout << "De verdad desea cerrar sesion? Si (0), No (1)  \n > ";
                        cin >> sesion;
                        cout << endl;
                        if (sesion == 0)
                        {
                            cout << " Ha cerrado sesion" << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        else if (sesion == 1)
                        {
                            cout << "  Sesion manetenida" << endl;
                            contador = 0;
                            regresar = 1;
                        }
                        else
                        {
                            sesion = 0;
                            cout << "Opcion no valida! Cerrado sesion..." << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        system("pause");
                    break;
                    system("cls");

                    default:
                        cout << "Ingrese una opcion valida! " << endl;
                        cout << endl;
                        regresar = 1;
                        contador = 0;
                        break;
                    }
                } while(regresar == 0);
                break; 

                // Menu principal Usuario Administrador 2
                case 2: 
                cout << GetCurrentDate() << endl;
                cout << "***************************************" << endl;
                cout << "  ----- EMPLEADO ADMINISTRADOR -----" << endl;
                cout << "***************************************";
                cout << endl;
                cout << "Opciones: " << endl;
                cout << " (1) Manejo de productos" << endl;
                cout << " (2) Manejo de ventas" << endl;
                cout << " (3) Cerrar sesion\n >";
                cin >> opcion;
                cout << endl;
                do
                {
                    system("cls");
                    switch (opcion)
                    {
                        // Opcion 1 del menu Usuario Administrador 2
                        case 1:
                        cout << endl;
                        cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                        break;

                        // Opcion 2 del menu Usuario Administrador 2
                        case 2: 
                        cout << endl;
                        cout << "----- MANEJO DE VENTAS ----- " << endl;
                        break; 

                        // Opcion 3 del menu Usuario Administrador
                        case 3: 
                        cout << endl;
                        cout << " De verdad desea cerrar sesion? Si (0), No (1)" << endl;
                        break; 

                    default:
                        cout << " Ingrese una opcion valida!" << endl;
                        cout << endl;
                        regresar = 1;
                        contador = 0;
                        break;
                    }
                } while(regresar == 0);
                break; 
            default:

                break;
            }
        } while(contador == 0);
    } while(sesion == 0);
    return 0;
}