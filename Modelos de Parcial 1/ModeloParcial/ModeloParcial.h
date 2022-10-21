#pragma once
#include"EstudiantesArchivo.h"
#include"ExamenesArchivo.h"
#include"rlutil.h"
#include<iostream>
using namespace std;
class ModeloParcial
{
public:

	// Mostrar legajo, apellidos y nombres de aquellos estudiantes que no hayan rendido ning�n examen en el año 2022.
	void punto1();
	int obtenerCantidadDeExamenesRealizados(int legajo);
/*
	Por cada alumno listar legajo, apellidos, nombres, cantidad de ex�menes aprobados(nota >= 6) y cantidad de exámenes desaprobados.Utilizar el siguiente formato :
	Legajo		Apellidos	Nombres	CantAprob	CantDesaprob
		99999		XXXXXX	XXXXXX	99		99
		99999		XXXXXX	XXXXXX	99		99
		99999		XXXXXX	XXXXXX	99		99
*/
	void punto2();
	int cantidadAprobados(int legajo);
	int cantidadDesaprobados(int legajo);
/*
	Listar la cantidad de alumnos que hayan rendido examen más de una vez para la misma materia entre los años 2018 y 2022 (ambos años inclusive).
	Aclaración: Los IDMateria son valores entre 1 y 60.
*/
	void punto3();
	int cantidadRendidaMasDeUnaVez(int legajo);
};

