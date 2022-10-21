#include "PrimerParcial.h"

void PrimerParcial::listarRecaudacion()
{
    PagosArchivo pagosArchivo;
    int cantidad = pagosArchivo.getCantidad();
    Pago *pagos = new Pago[cantidad];
    pagosArchivo.leerTodos(pagos, cantidad);

    float recaudacion[10] = {0};
    for (int i = 0; i < cantidad; i++)
    {
        if (fechaMayor(pagos[i].getFecha()))
        {
            recaudacion[pagos[i].getIdCurso() - 1] += pagos[i].getMonto();
        }
    }

    cout << "Recaudacion obtenida desde el periodo del 10/05/2020 de cada curso: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "ID Curso " << i + 1 << "\t : $" << recaudacion[i] << endl;
    }
}

bool PrimerParcial::fechaMayor(Fecha fecha)
{
    if (fecha.getAnio() < 2020)
        return false;
    if (fecha.getMes() < 5)
        return false;
    if (fecha.getDia() < 10)
        return false;
    return true;
}

void PrimerParcial::listarAlumnosNoMorosos()
{
    EstudiantesArchivo estudiantesArchivo;
    int cantidadEstudiantes = estudiantesArchivo.getCantidad();
    Estudiante *estudiante = new Estudiante[cantidadEstudiantes];
    estudiantesArchivo.leerTodos(estudiante, cantidadEstudiantes);

    PagosArchivo pagosArchivo;
    int cantidadPagos = pagosArchivo.getCantidad();
    Pago *pagos = new Pago[cantidadPagos];
    pagosArchivo.leerTodos(pagos, cantidadPagos);

    cout << "Legajos que nunca realizaron un pago vencidos: " << endl;
    int pagosVencidos;

    for (int e = 0; e < cantidadEstudiantes; e++)
    {
        pagosVencidos = 0;
        for (int p = 0; p < cantidadPagos; p++)
        {
            if (pagos[p].getLegajo() == estudiante[e].getLegajo())
            {
                if (pagos[p].esPagoVencido())
                {
                    pagosVencidos++;
                }
            }
        }
        if (pagosVencidos == 0)
        {
            cout << estudiante[e].getLegajo() << endl;
        }
    }
}

void PrimerParcial::soloUnCurso()
{
    EstudiantesArchivo estudiantesArchivo;
    int cantidadEstudiantes = estudiantesArchivo.getCantidad();
    Estudiante *estudiante = new Estudiante[cantidadEstudiantes];
    estudiantesArchivo.leerTodos(estudiante, cantidadEstudiantes);

    PagosArchivo pagosArchivo;
    int cantidadPagos = pagosArchivo.getCantidad();
    Pago *pagos = new Pago[cantidadPagos];
    pagosArchivo.leerTodos(pagos, cantidadPagos);

    cout << "Alumnos que pagaron solamente un curso del periodo (anio periodo de cursada)  2021: " << endl;
    int cursosPagados;

    for (int e = 0; e < cantidadEstudiantes; e++)
    {
        cursosPagados = 0;
        for (int p = 0; p < cantidadPagos; p++)
        {
            if (pagos[p].getLegajo() == estudiante[e].getLegajo())
            {
                if (pagos[p].getAnio() == 2021)
                {
                    cursosPagados++;
                }
            }
        }
        if (cursosPagados == 1)
        {
            cout << estudiante[e].getLegajo() << ", " << estudiante[e].getNombres() << ", " << estudiante[e].getApellidos() << endl;
        }
    }
}

void PrimerParcial::generarEstadistica()
{
    FILE *p;
    p = fopen("estadisticas.dat", "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

void PrimerParcial::mostrarEstadisticas()
{
}

void PrimerParcial::cursosPremium(int legajo)
{
    PagosArchivo pagosArchivo;
    int cantidadPagos = pagosArchivo.getCantidad();
    Pago *pagos = new Pago[cantidadPagos];
    pagosArchivo.leerTodos(pagos, cantidadPagos);

    float montoIndividual[10] = {0.0};
    int mayorMonto = 0.0;

    for (int i = 0; i < cantidadPagos; i++)
    {
        if (legajo == pagos[i].getLegajo())
        {
            if (pagos[i].getMonto() > montoIndividual[pagos[i].getIdCurso() - 1])
            {
                montoIndividual[pagos[i].getIdCurso() - 1] = pagos[i].getMonto();
            }
            if (pagos[i].getMonto() > mayorMonto)
            {
                mayorMonto = pagos[i].getMonto();
            }
        }
    }
    cout << "ID DE CURSO CON MAYOR PAGO INDIVIDUAL: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (montoIndividual[i] == mayorMonto)
        {
            cout << "ID " << i + 1 << endl;
        }
    }
}
