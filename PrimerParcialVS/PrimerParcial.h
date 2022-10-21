#pragma once
#include <iostream>
using namespace std;
#include "PagosArchivo.h"
#include "EstudiantesArchivo.h"
#include "EstadisticaArchivo.h"
#include <ctime>

class PrimerParcial
{
public:
	void listarRecaudacion();
	bool fechaMayor(Fecha fecha);
	void listarAlumnosNoMorosos();
	void soloUnCurso();
	void generarEstadistica();
	void mostrarEstadisticas();
	void cursosPremium(int legajo);
};
