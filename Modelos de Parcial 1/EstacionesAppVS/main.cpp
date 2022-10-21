#include <iostream>
#include "ResumenDiarioArchivo.h"
#include "ModeloParcial.h"
using namespace std;

int main()
{
  // ResumenDiarioArchivo resumen;
  // int cantidad = resumen.getCantidad();
  // ResumenDiario *resumenes = new ResumenDiario[cantidad];
  // resumen.leerTodos(resumenes, cantidad);

  // // mostrar
  // for (int i = 0; i < cantidad; i++)
  // {
  //   cout << "Estacion: " << resumenes[i].getIDEstacion() << endl;
  //   cout << "Tipo de Combustible: " << resumenes[i].getIDTipoCombustible() << endl;
  //   cout << "Fecha: ";    resumenes[i].getFecha().mostrar();
  //   cout << "litrosIniciales: " << resumenes[i].getLitrosIniciales() << endl;
  //   cout << "litrosFinales: " << resumenes[i].getLitrosFinales() << endl;
  //   cout << "precioPorLitro: " << resumenes[i].getPrecioPorLitro() << endl;
  // }

  // cout << "\n\n\n";

  ModeloParcial modelo;
  modelo.punto1();

  return 0;
}
