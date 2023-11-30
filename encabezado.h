#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

#include <string>

using namespace std;

//Declaraciones de estructuras a utilizar
struct Bebida
{
    string nombre_bebida;
    int tipo_bebida;
    float precio;
    int cantidad;
    float precio_venta;
    int lote;
};

//Declaracion de las funciones a utilizar
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

#endif // FUNCIONES_H