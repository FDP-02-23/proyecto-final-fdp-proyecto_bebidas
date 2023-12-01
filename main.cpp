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
    Ventas ventas; 
    Bitacora_usu bitacora;   // Declaracion estructura
    Bitacora_prod bitacoraprod;
    Bitacora_ven bitacoraven;          // Declaracion estructura
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

    //Funcion para llenar el vector
    InicializarUsuarios();

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
        tipo_usuario = BuscarUsuario(nombre_usuario, contrasenia);

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
                    do
                        {
                        switch (opcion1)
                            {
                            case 1:
                                cout << " Ingrese el nombre de usuario: ";
                                cin >> usuarios.usuario;
                                cout << " Ingrese una clave: ";
                                cin >> usuarios.contrasenia;
                                cout << endl;
                                cout << " Ingrese el tipo de usuario:\n (1) Si es administrador\n (2) Si es empleado\n >";
                                cin >> usuarios.tipo_usuario;
                                cout << endl;
                                usuarios.usuario_creacion = nombre_usuario;

                                if (usuarios.tipo_usuario != 1 && usuarios.tipo_usuario != 2)
                                {
                                    cout << "Tipo de usuario no valido!" << endl;
                                    regresarmenuusu = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    AgregarUsuarios(usuarios);
                                    //Añadiendo el registro a la estructura de bitacora y asi llevar registro
                                    bitacora.usuario = nombre_usuario;
                                    bitacora.usuarios.usuario = usuarios.usuario;
                                    bitacora.usuarios.contrasenia = usuarios.contrasenia;
                                    bitacora.usuarios.tipo_usuario = usuarios.tipo_usuario;
                                    bitacora.usuario_afectado = usuarios.usuario;
                                    bitacora.usuarios.usuario_creacion = nombre_usuario;
                                    bitacora.accion = "Se agrego un usuario";
                                    bitacora.fecha = GetCurrentDate();
                                    AgregarBitacoraUsu(bitacora);
                                    regresarmenuusu = 1;
                                    regresar = 0;
                                }
                                break;
                            case 2:
                                ImprimirUsuarios();
                                regresarmenuusu = 1;
                                regresar = 0;
                                break;
                            case 3:
                                ImprimirUsuarios();
                                cout << " Ingrese el nombre del usuario a modificar: ";
                                cin >> usuarios.usuario;
                                //Añadiendo el registro a la estructura de bitacora y asi llevar registro
                                bitacora.usuario = nombre_usuario;
                                bitacora.usuarios.usuario = usuarios.usuario;
                                bitacora.usuarios.contrasenia = usuarios.contrasenia;
                                bitacora.usuarios.tipo_usuario = usuarios.tipo_usuario;
                                bitacora.usuario_afectado = usuarios.usuario;
                                bitacora.usuarios.usuario_creacion = nombre_usuario;
                                bitacora.accion = "Se modifico un usuario";
                                bitacora.fecha = GetCurrentDate();

                                ModificarUsuario(usuarios.usuario);
                                AgregarBitacoraUsu(bitacora);

                                regresarmenuusu = 1;
                                regresar = 0;

                                break;
                            case 4:
                                ImprimirUsuarios();
                                cout << " Ingrese el nombre de usuario a eliminar: ";
                                cin >> usuarios.usuario;

                                EliminarUsuario(usuarios.usuario);
                                cout << endl;
                                bitacora.usuario = nombre_usuario;
                                bitacora.usuarios.usuario = usuarios.usuario;
                                bitacora.usuarios.contrasenia = usuarios.contrasenia;
                                bitacora.usuarios.tipo_usuario = usuarios.tipo_usuario;
                                bitacora.usuario_afectado = usuarios.usuario;
                                bitacora.usuarios.usuario_creacion = nombre_usuario;
                                bitacora.accion = "Se elimino un usuario";
                                bitacora.fecha = GetCurrentDate();
                                AgregarBitacoraUsu(bitacora);
                                regresarmenuusu = 1;
                                regresar = 0;
                                break;
                            case 5:
                                regresarmenuusu = 1;
                                regresar = 1;
                                contador = 0;
                                break;
                            default:
                                cout << "Opcion no valida! Regresando..." << endl;
                                cout << endl;
                                regresarmenuusu = 1;
                                regresar = 1;
                                break;
                            }
                            system("pause");

                    } while (regresarmenuusu == 0);
                    break; 

                    // Opcion 2 de menu Administrador
                    case 2: 
                    cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                    cout << endl;
                    cout << "Opciones: " << endl;
                    cout << " (1) Agregar productos" << endl;
                    cout << " (2) Mostrar productos existentes" << endl;
                    cout << " (3) Modificar productos existentes" << endl;
                    cout << " (4) Eliminar productos existentes" << endl;
                    cout << " (5) Regresar al menu anterior\n >";
                    cin >> opcion1;
                    cout << endl;

                    do
                    {
                        cin.ignore(); 
                        switch (opcion1)
                        {
                            case 1: 
                            // Agregar productos/bebidas nuevas

                                // Lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << endl;
                                cout << " Tipos de packs: " << endl;
                                cout << "   (1) Pack de 6 botellas" << endl;
                                cout << "   (2) Pack de 12 botellas" << endl;
                                cout << "   (3) Pack de 24 botellas" << endl;
                                cout << endl;
                                cout << "  Ingrese el tipo de pack que ha comprado: ";
                                cin >> bebida.tipo_bebida;

                                // Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                if (bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3)
                                {
                                    cout << " Ingrese una opcion valida!\n";
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    cout << "  Ingrese el monto total de lo invertido en la compra: $";
                                    cin >> bebida.precio;
                                    cout << "  Ingrese la cantidad de packs que se compro: ";
                                    cin >> bebida.cantidad;
                                    cout << endl;
                                    cout << " El precio por pack es de $" << (bebida.precio / bebida.cantidad) << endl;
                                    cout << " Le sugerimos ingresar un monto mayor para generar ganancia." << endl;
                                    cout << " Ingrese el costo de venta por pack: $";
                                    cin >> bebida.precio_venta;
                                    cout << endl;
                                    lote = lote + 1;
                                    bebida.lote = lote;
                                    AgregarBebida(bebida);
                                    cout << " Producto ingresado exitosamente\n";
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                break; 

                            case 2: 
                            // Mostrar bebidas existentes disponibles
                                ImprimirBebidas();
                                break; 

                            case 3: 
                            // Modificar bebidas existentes
                                ImprimirBebidas();
                                cout << "Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cin.ignore();
                                cout << "Ingrese el numero de lote: ";
                                cin >> bebida.lote;

                                BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                regresar = 0;
                                break; 

                            case 4: 
                            // Opcion eliminar bebida existente
                                ImprimirBebidas();
                                cout << " Ingrese el nombre de la bebida a eliminar: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << " Ingrese el numero de lote: ";
                                cin >> bebida.lote;
                                EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                cout << " Bebida eliminada correctamente" << endl;
                                break; 

                            case 5: 
                            // Regresar al menu 
                                regresarmenupro = 1;
                                regresar = 1;
                                contador = 0;
                                break; 

                        default:
                            cout << "Opcion no valida! Regresando..." << endl;
                            cout << endl;
                            regresarmenupro = 1;
                            regresar = 0;
                            break;
                        }
                        system("pause"); 
                    } while(regresarmenupro == 0);
                    break; 

                    // Opcion 3 del menu Administrador
                    case 3: 
                    if (opcion == 3)
                    {
                        cout << endl;
                        cout << "----- REGISTRO DE VENTAS ----- " << endl;
                        MostrarRegistro("RegistroVentas.txt"); // Imprime el registro
                    }
                    else
                    {
                        cout << "El archivo se ha creado aparte" << endl;
                    }
                    system("pause");
                    regresar = 1;
                    break; 

                    // Opcion 4 del menu Administrador
                    case 4: 
                    cout << "Ingrese el nombre de usuario para verificar las acciones realizadas: ";
                    getline(cin, bitacora.usuario);

                    cout << "---------- BITACORA ---------- " << endl;
                    ImprimirBitacoraUsu(bitacora.usuario);
                    ImprimirBitacoraPro(bitacora.usuario);
                    ImprimirBitacoraVen(bitacora.usuario),
                    system("pause");
                    contador = 0;
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
                        cout << endl;
                        cout << "Opciones: " << endl;
                        cout << " (1) Agregar productos" << endl;
                        cout << " (2) Mostrar productos existentes" << endl;
                        cout << " (3) Modificar productos existentes" << endl;
                        cout << " (4) Eliminar productos existentes" << endl;
                        cout << " (5) Regresar al menu anterior\n >";
                        cin >> opcion1;
                        cout << endl;

                        do
                        {
                            cin.ignore(); 
                            switch (opcion1)
                            {
                                case 1: 
                                // Opcion 1
                                // Lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << endl;
                                cout << " Tipos de packs: " << endl;
                                cout << "   (1) Pack de 6 botellas" << endl;
                                cout << "   (2) Pack de 12 botellas" << endl;
                                cout << "   (3) Pack de 24 botellas\n";
                                cout << endl;
                                cout << " Ingrese el tipo de pack a comprar: ";
                                cin >> bebida.tipo_bebida;

                                // Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                if (bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3)
                                {
                                    cout << " El tipo de pack no es correcto, ingrese una opcion valida" << endl;
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    cout << " Ingrese el monto total invertido de su compra: $";
                                    cin >> bebida.precio;
                                    cout << " Ingrese la cantidad de packs: ";
                                    cin >> bebida.cantidad;
                                    cout << endl;
                                    cout << " El precio por pack es de $" << (bebida.precio / bebida.cantidad) << endl;
                                    cout << " Le sugerimos ingresar un monto mayor generar ganancia." << endl;
                                    cout << " Ingrese el costo de venta por pack: $";
                                    cin >> bebida.precio_venta;
                                    cout << endl;
                                    lote = lote + 1;
                                    bebida.lote = lote;
                                    AgregarBebida(bebida);
                                    cout << " Producto ingresado exitosamente" << endl;
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                break; 

                                case 2: 
                                // Opcion 2 menu
                                ImprimirBebidas();
                                break; 

                                case 3: 
                                // Opcion 3 menu 
                                ImprimirBebidas();
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << " Ingrese el numero de lote: ";
                                cin >> bebida.lote;
                                BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                regresar = 0;
                                break; 

                                case 4: 
                                // Opcion 4 menu 
                                ImprimirBebidas();
                                cout << " Ingrese el nombre de la bebida a eliminar: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << " Ingrese el numero de lote: ";
                                cin >> bebida.lote;

                                EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl; 
                                cout << " Bebida eliminada correctamente" << endl;
                                cout << endl;
                                regresarmenupro = 1;
                                regresar = 0;
                                break; 

                                case 5: 
                                // Regrasar al menu anterior
                                regresarmenupro = 1;
                                regresar = 1;
                                contador = 0;
                                break; 

                            default:
                                cout << "Opcion no valida! Regresando..." << endl;
                                cout << endl;
                                regresarmenupro = 1;
                                regresar = 0;
                                break;
                            }
                            system("pause"); 
                        } while(regresarmenupro == 0);
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