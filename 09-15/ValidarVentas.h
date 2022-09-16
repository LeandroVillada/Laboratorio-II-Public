#pragma once
#include"ArchivoVentas.h"
#include"Venta.h"

class ValidarVentas
{
public:
	// Validaciones
	bool validarRegistro(Venta venta);
	bool validarCodigo(int codigo);
	bool validarPrecio(float precio);
	bool validarCantidad(int cantidad);

	// Comprobaciones
	bool codigoRepetido(int codigo);
	bool codigoNegativo(int codigo);
	bool precioNegativo(float precio);
	bool cantidadNegativa(int cantidad);
};

