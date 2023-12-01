#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

#include <string>

using namespace std;

struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
    string usuario_creacion;
};

void InicializarUsuarios();
int BuscarUsuario();
void AgregarUsuarios(Usuarios);
void ModificarUsuario(string);
void ImprimirUsuarios();



#endif // FUNCIONES_H