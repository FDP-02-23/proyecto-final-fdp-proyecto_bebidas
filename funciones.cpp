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