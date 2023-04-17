#include "SegundoParcial.h"

/**
 * 1- Crear un método llamado alumnosDesaprobados que muestre el curso cuya
 * cantidad de alumnos que desaprobaron el examen final sean la más alta, en caso de
 * haber más de uno, mostrar todos los cursos que cumplan dicha condición.
 */
void SegundoParcial::alumnosDesaprobados()
{
    InscripcionesArchivo inscripcionesArchivo;
    int cantidadInscripciones = inscripcionesArchivo.getCantidad();
    Inscripcion *inscripciones = new Inscripcion[cantidadInscripciones];
    if (inscripciones == NULL)
    {
        return;
    }
    if (!inscripcionesArchivo.leerTodos(inscripciones, cantidadInscripciones))
    {
        return;
    }

    CursosArchivo cursosArchivo;
    int cantidadCursos = cursosArchivo.getCantidadRegistros();
    Cursos *cursos = new Cursos[cantidadCursos];
    if (cursos == NULL)
    {
        return;
    }
    if (!cursosArchivo.leerTodos(cursos, cantidadCursos))
    {
        return;
    }
    
    /* Counting the number of students that failed the final exam for each course. */
    int *alumnosDesaprobados = ContarAlumnosDesaprobadosPorCursos(inscripciones, cantidadInscripciones, cursos, cantidadCursos);

    mostrarCursosConMasDesaprobados(alumnosDesaprobados, cantidadCursos, cursos);
}

/**
 * 2 - Crear un método llamado peorCurso que muestre los cursos donde todos sus
 * alumnos desaprobaron.
 */
void SegundoParcial::peorCurso()
{
    InscripcionesArchivo inscripcionesArchivo;
    int cantidadInscripciones = inscripcionesArchivo.getCantidad();
    Inscripcion *inscripciones = new Inscripcion[cantidadInscripciones];
    if (inscripciones == NULL)
    {
        return;
    }
    if (!inscripcionesArchivo.leerTodos(inscripciones, cantidadInscripciones))
    {
        return;
    }

    CursosArchivo cursosArchivo;
    int cantidadCursos = cursosArchivo.getCantidadRegistros();
    Cursos *cursos = new Cursos[cantidadCursos];
    if (cursos == NULL)
    {
        return;
    }
    if (!cursosArchivo.leerTodos(cursos, cantidadCursos))
    {
        return;
    }

    mostrarCursosDesaprobados(inscripciones, cantidadInscripciones, cursos, cantidadCursos);
}

/**
 * 3 - Crear un método llamado verGeneraciones que muestre para cada curso la
 * generación en la que más alumnos tenga inscriptos. Se clasifican según el año de
 * nacimiento de la siguiente manera:
 * ● Generación silenciosa <= 1945
 * ● Baby boomers 1946 - 1964
 * ● Generación X 1965 - 1980
 * ● Millennials 1981 - 1995
 * ● Generación Z 1996 - 2012
 * ● Generación Alpha >= 2013
 */
void SegundoParcial::verGeneraciones()
{
    InscripcionesArchivo inscripcionesArchivo;
    int cantidadInscripciones = inscripcionesArchivo.getCantidad();
    Inscripcion *inscripciones = new Inscripcion[cantidadInscripciones];
    if (inscripciones == NULL)
    {
        return;
    }
    if (!inscripcionesArchivo.leerTodos(inscripciones, cantidadInscripciones))
    {
        return;
    }

    CursosArchivo cursosArchivo;
    int cantidadCursos = cursosArchivo.getCantidadRegistros();
    Cursos *cursos = new Cursos[cantidadCursos];
    if (cursos == NULL)
    {
        return;
    }
    if (!cursosArchivo.leerTodos(cursos, cantidadCursos))
    {
        return;
    }
}

/*
 * 4 - Crear un método llamado generarReporte que genere un archivo llamado
 * reportes.dat donde se guarde para cada curso el porcentaje de aprobados y
 * desaprobados de todos los cursos que se hayan terminado.
 * Un curso está terminado cuando todos sus alumnos realizaron el examen final.
 */
void SegundoParcial::generarReporte()
{
}

/*
 * Crear un método llamado mostrarReporte que muestre el reporte leyéndolo del archivo de reportes.dat
 */
void SegundoParcial::mostrarReporte()
{
}
