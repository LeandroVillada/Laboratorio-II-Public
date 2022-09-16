#include "ArchivoVentas.h"
#include "ValidarVentas.h"

void ArchivoVentas::mostrarArchivo()
{
    int pos = 0;
    while (comprobarLectura(pos))
    {
        mostrarVenta(obtenerRegistro(pos++));
        puts("");
    }
}

bool ArchivoVentas::guardarRegistro(Venta venta)
{
    FILE *pFile;
    pFile = fopen("Ventas.dat", "ab");
    if (pFile == NULL)
    {
        exit(1);
        return false;
    }

    bool grabo = fwrite(&venta, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return grabo;
}

float ArchivoVentas::totalRecaudado()
{
    int pos = 0;
    float total = 0.0;
    while (comprobarLectura(pos))
    {
        if (obtenerRegistro(pos).getEstado())
        {
            total += obtenerRegistro(pos).getTotal();
        }
        pos++;
    }
    return total;
}

bool ArchivoVentas::comprobarLectura(int pos)
{
    FILE *pFile;
    pFile = fopen("Ventas.dat", "rb");
    if (pFile == NULL)
    {
        return false;
    }

    Venta venta;
    fseek(pFile, pos * sizeof(Venta), 0);
    bool leyo = fread(&venta, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return leyo;
}

Venta ArchivoVentas::obtenerRegistro(int pos)
{
    Venta venta;
    FILE *pFile;
    pFile = fopen("Ventas.dat", "rb");
    if (pFile == NULL)
    {
        exit(25);
        return venta;
    }
    fseek(pFile, pos * sizeof(Venta), 0);
    fread(&venta, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return venta;
}

bool ArchivoVentas::modificarRegistro(Venta &venta, int pos)
{
    if (!comprobarLectura(pos))
    {
        exit(22);
        return false;
    }
    FILE *pFile;
    pFile = fopen("Ventas.dat", "rb+");
    if (pFile == NULL)
    {
        return false;
    }
    fseek(pFile, sizeof(Venta) * pos, 0);

    bool leyo = fwrite(&venta, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return leyo;
}

int ArchivoVentas::cantidadRegistros()
{
    int cantidad = 0;
    while (comprobarLectura(cantidad++))
    {
    }
    return cantidad - 1;
}

bool ArchivoVentas::cargarVenta(Venta &venta)
{
    ValidarVentas validar;

    int codigo;
    std::cout << "Codigo: ";
    std::cin >> codigo;
    venta.setCodigo(codigo);

    float precio;
    std::cout << "Precio: ";
    std::cin >> precio;
    venta.setPrecio(precio);

    int cantidad;
    std::cout << "Cantidad: ";
    std::cin >> cantidad;
    venta.setCantidad(cantidad);

    if (!validar.validarRegistro(venta)) { return false; }

    return true;
}

void ArchivoVentas::mostrarVenta(Venta venta)
{
    std::cout << "Codigo: " << venta.getCodigo() << std::endl;
    std::cout << "Precio: " << venta.getPrecio() << std::endl;
    std::cout << "Cantidad: " << venta.getCantidad() << std::endl;
    std::cout << "Total: " << venta.getTotal() << std::endl;
}