#pragma once
#pragma warning(disable : 4996)
#include "Venta.h"
#include <iostream>
using namespace std;

class ArchivoVentas
{
public:
	float totalRecaudado();

    // FUNCIONES ARCHIVOS
    bool comprobarLectura(int pos);
	bool guardarRegistro(Venta venta);
    Venta obtenerRegistro(int pos);
    bool modificarRegistro(Venta &venta, int pos);
    int cantidadRegistros();

    bool cargarVenta(Venta &venta);
    void mostrarVenta(Venta venta);

    void mostrarArchivo();
};

