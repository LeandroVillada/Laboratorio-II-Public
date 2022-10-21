#include "ModeloParcial.h"

void ModeloParcial::punto1()
{
	ResumenDiarioArchivo resumen;
	cout << "Tipo de combustible registrado con el mayor precio: " << obtenerTipoDeCombustible(resumen.leer(buscarPrecioPorLitroMasCaro()).getIDTipoCombustible()) << endl;
}

int ModeloParcial::buscarPrecioPorLitroMasCaro()
{
	ResumenDiarioArchivo resumen;
	float PrecioMaximo = 0.0;
	int posMax = 0;
	for (int i = 0; i < resumen.getCantidad(); i++)
	{
		if (resumen.leer(i).getPrecioPorLitro() > PrecioMaximo)
		{
			PrecioMaximo = resumen.leer(i).getPrecioPorLitro();
			posMax = i;
		}
	}
	return posMax;
}

std::string ModeloParcial::obtenerTipoDeCombustible(int idTipoCombustible)
{
	std::string tipoCombustible;
	switch (idTipoCombustible)
	{
	case 1:
		tipoCombustible = "Nafta super";
		break;
	case 2:
		tipoCombustible = "Nafta comun";
		break;
	case 3:
		tipoCombustible = "Diesel";
		break;
	case 4:
		tipoCombustible = "Gasoil";
		break;
	case 5:
		tipoCombustible = "GNC";
		break;
	}
	return tipoCombustible;
}