#include "ModeloParcial.h"

void ModeloParcial::punto1()
{
	EstudiantesArchivo estudiante;
	for (int i = 0; i < estudiante.getCantidad(); i++)
	{
		if (obtenerCantidadDeExamenesRealizados(estudiante.leer(i).getLegajo()) == 0)
		{
			cout << estudiante.leer(i).toString() << endl;
		}
	}
}

int ModeloParcial::obtenerCantidadDeExamenesRealizados(int legajo)
{
	ExamenesArchivo examen;
	int cantidad = 0;
	for (int i = 0; i < examen.getCantidad(); i++)
	{
		if (legajo == examen.leer(i).getLegajo())
		{
			cantidad++;
		}
	}
	return cantidad;
}

void ModeloParcial::punto2()
{
	int y = 1, x = 0, espacio = 8;
	cout << "legajo";
	x = strlen("Legajo") + espacio;
	rlutil::locate(x, y);
	cout << "Nombre";
	x += espacio + 29;
	rlutil::locate(x, y);
	cout << "Apellido";
	x += espacio + 29;
	rlutil::locate(x, y);
	cout << "CantAprob";
	x += espacio + strlen("CantAprob");
	rlutil::locate(x, y);
	cout << "CantDesaprob";

	EstudiantesArchivo estudiante;
	for (int i = 0; i < estudiante.getCantidad(); i++)
	{
		y++;
		x = 1;
		rlutil::locate(x, y);
		cout << estudiante.leer(i).getLegajo();
		x = strlen("Legajo") + espacio;
		rlutil::locate(x, y);
		cout << estudiante.leer(i).getNombres();
		x += espacio + 29;
		rlutil::locate(x, y);
		cout << estudiante.leer(i).getApellidos();
		x += espacio + 29;
		rlutil::locate(x, y);
		cout << cantidadAprobados(estudiante.leer(i).getLegajo());
		x += espacio + strlen("CantAprob");
		rlutil::locate(x, y);
		cout << cantidadDesaprobados(estudiante.leer(i).getLegajo());
	}
}

int ModeloParcial::cantidadAprobados(int legajo)
{
	ExamenesArchivo examen;
	int cantidad = 0;
	for (int i = 0; i < examen.getCantidad(); i++)
	{
		if (legajo == examen.leer(i).getLegajo())
		{
			if (examen.leer(i).getNota() >= 6)
			{
				cantidad++;
			}
		}
	}
	return cantidad;
}

int ModeloParcial::cantidadDesaprobados(int legajo)
{
	ExamenesArchivo examen;
	int cantidad = 0;
	for (int i = 0; i < examen.getCantidad(); i++)
	{
		if (legajo == examen.leer(i).getLegajo())
		{
			if (examen.leer(i).getNota() < 6)
			{
				cantidad++;
			}
		}
	}
	return cantidad;
}

void ModeloParcial::punto3()
{
	int cantidad = 0;

	EstudiantesArchivo estudiantes;
	for (int i = 0; i < estudiantes.getCantidad(); i++)
	{
		if (cantidadRendidaMasDeUnaVez(estudiantes.leer(i).getLegajo()) != 0)
		{
			cantidad++;
		}
	}
	cout << "cantidad de alumnos que hayan rendido examen más de una vez para la misma materia: " << cantidad << endl;
}

int ModeloParcial::cantidadRendidaMasDeUnaVez(int legajo)
{
	int *materias = new int[60]{0};
	ExamenesArchivo examenes;

	for (int i = 0; i < examenes.getCantidad(); i++)
	{
		if (legajo == examenes.leer(i).getLegajo())
		{
			if (examenes.leer(i).getFecha().getAnio() >= 2018 && examenes.leer(i).getFecha().getAnio() <= 2022)
			{
				materias[examenes.leer(i).getIDMateria() - 1]++;
			}
		}
	}
	int cantidad = 0;
	for (int i = 0; i < 60; i++)
	{
		if (materias[i] > 1)
		{
			cantidad++;
		}
	}
	// for (int i = 0; i < 60; i++)
	// {
	// 	cout << "ID " << i + 1 << "\tRindio: " << materias[i] << endl;
	// }
	return cantidad;
}