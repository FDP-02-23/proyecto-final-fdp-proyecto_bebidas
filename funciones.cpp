#include "encabezado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

//Definicion de Funciones

string GetCurrentDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    return to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
}

//Archivo que se encarga de la ejecucion de funciones