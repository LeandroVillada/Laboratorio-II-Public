#include "Estadistica.h"

Estadistica::Estadistica()
{
    _anio = 0;
    _recaudacion = 0.0;
}

int Estadistica::getAnio()
{
    return _anio;
}

void Estadistica::setAnio(int anio)
{
    _anio = anio;
}

float Estadistica::getRecaudacion()
{
    return -_recaudacion;
}

void Estadistica::setRecaudacion(float recaudacion)
{
    _recaudacion = recaudacion;
}
