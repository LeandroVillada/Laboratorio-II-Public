#pragma once
#include "CursoArchivo.h"
#include "InscripcionesArchivo.h"

int *ContarAlumnosDesaprobadosPorCursos(Inscripcion *inscripciones, int cantidadInscripciones, Cursos *cursos, int cantidadCursos);

void mostrarCursosConMasDesaprobados(int *alumnosDesaprobados, int cantidadCursos, Cursos *cursos);

int maximoVector(int v[], int tam);

void mostrarCursosDesaprobados(Inscripcion *inscripciones, int cantidadInscripciones, Cursos *cursos, int cantidadCursos);

int obtenerGeneracion(int anio);

void listarPorCursoLaGeneracionConMasInscriptos(Inscripcion *inscripciones, int cantidadInscripciones, Cursos *cursos, int cantidadCursos);