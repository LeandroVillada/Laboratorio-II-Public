#include "ValidarVentas.h"

bool ValidarVentas::validarRegistro(Venta venta)
{
    if (validarCodigo((venta.getCodigo())) && (validarPrecio(venta.getPrecio())) && (validarCantidad(venta.getCantidad())))
    {
        return true;
    }
    return false;
}

// Validaciones
bool ValidarVentas::validarCodigo(int codigo)
{
    if (codigoRepetido(codigo) || codigoNegativo(codigo))
    {
        return false;
    }
    return true;
}

bool ValidarVentas::validarPrecio(float precio)
{
    if (precioNegativo(precio))
    {
        return false;
    }
    return true;
}

bool ValidarVentas::validarCantidad(int cantidad)
{
    if (cantidadNegativa(cantidad))
    {
        return false;
    }
    return true;
}

// Comprobaciones
bool ValidarVentas::codigoRepetido(int codigo)
{
    int pos = 0;
    ArchivoVentas ventas;
    while (ventas.comprobarLectura(pos))
    {
        if (ventas.obtenerRegistro(pos).getCodigo() == codigo)
        {
            return true;
        }
        pos++;
    }
    return false;
}

bool ValidarVentas::codigoNegativo(int codigo)
{
    if (codigo < 0)
    {
        return true;
    }
    return false;
}

bool ValidarVentas::precioNegativo(float precio)
{
    if (precio < 0)
    {
        return true;
    }
    return false;
}

bool ValidarVentas::cantidadNegativa(int cantidad)
{
    if (cantidad < 0)
    {
        return true;
    }
    return false;
}
