#pragma once
#include <iostream>
#include "Estadistica.h"

class EstadisticaArchivo
{
public:
    Estadistica leer(int nroRegistro);
    bool leerTodos(Estadistica estadisticas[], int cantidad);
    bool guardar(Estadistica est);
    bool guardar(Estadistica est, int nroRegistro);
    int getCantidad();
};
