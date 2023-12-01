#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>


using namespace std;
//Declaraciones de estructuras a utilizar
struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
    string usuario_creacion;
};
struct Bebida
{
    string nombre_bebida;
    int tipo_bebida;
    float precio;
    int cantidad;
    float precio_venta;
    int lote;
};
struct Ventas
{
    string nombre_bebida;
    int lote;
    int cantidad;
    string nombre_consumidor;
    float precio_total;
    int identificador;
    string fecha;
};
struct Bitacora_usu{
    string usuario;
    string accion;
    string fecha;
    string usuario_afectado;
    Usuarios usuarios;
};
struct Bitacora_prod{
    string usuario;
    string accion;
    string fecha;
    string producto_afectado;
    Bebida bebida;
};
struct Bitacora_ven{
    string usuario;
    string accion;
    string fecha;
    string venta_afectada;
    Ventas ventas;
};

void InicializarUsuarios();
int BuscarUsuario();
int BuscarUsuario(string, string);
void AgregarUsuarios(Usuarios);
void ModificarUsuario(string);
void ImprimirUsuarios();
void EliminarUsuario(string);
int BuscarUsuario(string, string);
void ImprimirBebidas();
void BuscaryModificarBebida(string, int);
void ImprimirLotes(string);
int BuscarBebidaPack(int, string);
int BuscarBebidapack6(string);
int BuscarBebidapack12(string);
int BuscarBebidapack24(string);
void EliminarBebida(string, int);
void AgregarBebida(Bebida);
int BuscarLote(int);
string GetCurrentDate();
void RegistrarVenta(Ventas venta);
void AgregarVenta(Ventas);
void EliminarVenta(string, int);
void MostrarRegistro(string archivo);
void ImprimirVentas();
void ImprimirLotes(string);
void ModificarStock(int, int);
void ModificarStockDevolucion(int, int, string);
float BuscarPrecioVenta(int);
void AgregarBitacoraUsu(Bitacora_usu); 
void AgregarBitacoraProd(Bitacora_prod);
void AgregarBitacoraVen(Bitacora_ven);
void ImprimirBitacoraUsu(string);
void ImprimirBitacoraPro(string);
void ImprimirBitacoraVen(string);


#endif // FUNCIONES_H