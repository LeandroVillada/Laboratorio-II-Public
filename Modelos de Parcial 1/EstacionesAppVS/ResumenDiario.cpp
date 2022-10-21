#include "ResumenDiario.h"

int ResumenDiario::getIDEstacion()
{
  return _idEstacion;
}

void ResumenDiario::setIDEstacion(int idEstacion)
{
  _idEstacion = idEstacion;
}

int ResumenDiario::getIDTipoCombustible()
{
  return _idTipoCombustible;
}

void ResumenDiario::setIDTipoCombustible(int idTipoCombustible)
{
  _idTipoCombustible = idTipoCombustible;
}

Fecha ResumenDiario::getFecha()
{
  return _fecha;
}

void ResumenDiario::setFecha(Fecha fecha)
{
  _fecha = fecha;
}

int ResumenDiario::getLitrosIniciales()
{
  return _litrosIniciales;
}

void ResumenDiario::setLitrosIniciales(int litrosIniciales)
{
  _litrosIniciales = litrosIniciales;
}

int ResumenDiario::getLitrosFinales()
{
  return _litrosFinales;
}

void ResumenDiario::setLitrosFinales(int litrosFinales)
{
  _litrosFinales = litrosFinales;
}


float ResumenDiario::getPrecioPorLitro()
{
  return _precioPorLitro;
}

void ResumenDiario::setPrecioPorLitro(float precioPorLitro)
{
  _precioPorLitro = precioPorLitro;
}
