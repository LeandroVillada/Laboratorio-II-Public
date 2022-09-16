#include "Venta.h"

Venta::Venta()
{
	_codigo = 0;
	_precio = 0.0;
	_cantidad = 0;
	_estado = true;
}

Venta::Venta(int codigo, float precio, int cantidad)
{
	_codigo = codigo;
	_precio = precio;
	_cantidad = cantidad;
	_estado = true;
}

void Venta::setCodigo(int codigo)
{
	_codigo = codigo;
}

void Venta::setPrecio(float precio)
{
	_precio = precio;
}

void Venta::setCantidad(int cantidad)
{
	_cantidad = cantidad;
}

void Venta::setEstado(bool estado)
{
	_estado = estado;
}

void Venta::setVenta(Venta venta)
{
	_codigo = venta.getCodigo();
	_precio = venta.getPrecio();
	_cantidad = venta.getCantidad();
	_estado = venta.getEstado();
}

int Venta::getCodigo()
{
	return _codigo;
}

float Venta::getPrecio()
{
	return _precio;
}

int Venta::getCantidad()
{
	return _cantidad;
}

bool Venta::getEstado()
{
	return _estado;
}

float Venta::getTotal()
{
	return _precio * _cantidad;
}
