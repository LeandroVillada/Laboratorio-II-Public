#include "Funciones.h"

/**
 * *|CURSOR_MARCADOR|*
 *
 * @param inscripciones an array of Inscripcion objects
 * @param cantidadInscripciones The amount of inscriptions
 * @param cursos an array of Cursos objects
 * @param cantidadCursos The amount of courses
 *
 * @return a pointer to an array of integers.
 */
int *ContarAlumnosDesaprobadosPorCursos(Inscripcion *inscripciones, int cantidadInscripciones, Cursos *cursos, int cantidadCursos)
{
	int *AlumnosDesaprobados = new int[cantidadCursos]{0};
	if (AlumnosDesaprobados == NULL)
	{
		return 0;
	}
	for (int c = 0; c < cantidadCursos; c++)
	{
		for (int i = 0; i < cantidadInscripciones; i++)
		{
			if (cursos[c].getIdCurso() == inscripciones[i].getIdCurso())
			{
				if (inscripciones[i].getNota() < 6)
				{
					AlumnosDesaprobados[c]++;
					// AlumnosDesaprobados[cursos[c].getIdCurso() - 1]++;
				}
			}
		}
	}
	return AlumnosDesaprobados;
}

/**
 *
 *
 * @param alumnosDesaprobados an array of integers that contains the number of students that failed the
 * final exam for each course.
 * @param cantidadCursos number of courses
 * @param cursos array of Cursos objects
 */
void mostrarCursosConMasDesaprobados(int *alumnosDesaprobados, int cantidadCursos, Cursos *cursos)
{
	int posMax = maximoVector(alumnosDesaprobados, cantidadCursos);

	cout << "curso cuya cantidad de alumnos que desaprobaron el examen final sean la mas alta: " << endl;
	for (int i = 0; i < cantidadCursos; i++)
	{
		if (alumnosDesaprobados[i] == alumnosDesaprobados[posMax])
		{
			cout << "CURSO: " << cursos[i].toString() << endl;
		}
	}
}

/**
 * It returns the position of the maximum value in an array
 *
 * @param v the array
 * @param tam the size of the array
 *
 * @return The position of the maximum value in the array.
 */
int maximoVector(int v[], int tam)
{
	int i, posMax = 0;
	for (i = 1; i < tam; i++)
	{
		if (v[i] > v[posMax])
		{
			posMax = i;
		}
	}
	return posMax;
}

/**
 * It loops through all the courses and checks if any of the students in the course have a grade of 6
 * or higher. If they do, the course is marked as approved. If not, the course is marked as not
 * approved
 *
 * @param inscripciones an array of Inscripcion objects
 * @param cantidadInscripciones number of inscriptions
 * @param cursos an array of Cursos objects
 * @param cantidadCursos number of courses
 *
 * @return a pointer to a boolean array.
 */
void mostrarCursosDesaprobados(Inscripcion *inscripciones, int cantidadInscripciones, Cursos *cursos, int cantidadCursos)
{
	bool *cursosAprobados = new bool[cantidadCursos]{0};
	if (cursosAprobados == NULL)
	{
		return;
	}
	for (int c = 0; c < cantidadCursos; c++)
	{
		for (int i = 0; i < cantidadInscripciones; i++)
		{
			if (cursos[c].getIdCurso() == inscripciones[i].getIdCurso())
			{
				if (inscripciones[i].getNota() >= 6)
				{
					cursosAprobados[c] = true;
				}
			}
		}
	}

	cout << "Curso con todos sus alumnos desaprobados: " << endl;
	for (int i = 0; i < cantidadCursos; i++)
	{
		if (!cursosAprobados[i])
		{
			cout << "CURSO: " << cursos[i].toString() << endl;
		}
	}
}

/**
 * It returns the generation of a person based on the year they were born.
 * 
 * @param anio The year the person was born.
 * 
 * @return the generation of the person based on the year they were born.
 */
int obtenerGeneracion(int anio)
{
	//  ● Generación silenciosa <= 1945
	if (anio <= 1945)
	{
		return 0;
	}
	//  ● Baby boomers 1946 - 1964
	if ((anio > 1945) && (anio < 1965))
	{
		return 1;
	}
	//  ● Generación X 1965 - 1980
	if ((anio >= 1965) && (anio <= 1980))
	{
		return 2;
	}
	//  ● Millennials 1981 - 1995
	if ((anio > 1980) && (anio <= 1995))
	{
		return 3;
	}
	//  ● Generación Z 1996 - 2012
	if ((anio > 1996) && (anio < 2013))
	{
		return 4;
	}
	//  ● Generación Alpha >= 2013
	if (anio >= 2013)
	{
		return 5;
	}
}

void listarPorCursoLaGeneracionConMasInscriptos(Inscripcion* inscripciones, int cantidadInscripciones, Cursos* cursos, int cantidadCursos)
{
	int (*generaciones)[6] = new int[cantidadCursos][6]{0};
	if (generaciones == NULL)
	{
		return;
	}
	for (int c = 0; c < cantidadCursos; c++)
	{
		for (int i = 0; i < cantidadInscripciones; i++)
		{
			if (cursos[c].getIdCurso() == inscripciones[i].getIdCurso())
			{
				if (inscripciones[i].getNota() < 6)
				{
					// generaciones[c]++;
					// AlumnosDesaprobados[cursos[c].getIdCurso() - 1]++;
				}
			}
		}
	}
}
