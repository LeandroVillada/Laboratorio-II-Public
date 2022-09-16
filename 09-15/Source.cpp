#include <iostream>
#include <cstdlib>
#include "Venta.h"
#include "ArchivoVentas.h"
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int opc;
    Venta venta;
    ArchivoVentas archivoVentas;
    // Desarrollo del Programa
    while (true)
    {
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "\n\t1. Cargar Venta" << endl;
        cout << "\t2. Mostrar total recaudado" << endl;
        cout << "\t0. Salir" << endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            if (archivoVentas.cargarVenta(venta)) {
                archivoVentas.guardarRegistro(venta);
            }
            system("pause>nul");
            break;
        case 2:
            archivoVentas.mostrarArchivo();
            system("pause>nul");
            break;
        case 3:
            cout << archivoVentas.totalRecaudado() << endl;
            system("pause>nul");
            break;
        case 0: // Fin del Programa
            return 0;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}
