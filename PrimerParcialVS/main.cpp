#include <iostream>
using namespace std;
#include "PrimerParcial.h"
#include "PagosArchivo.h"
int main()
{

  PagosArchivo pagosArchivo;
  int cantidad = pagosArchivo.getCantidad();
  Pago *pagos = new Pago[cantidad];
  pagosArchivo.leerTodos(pagos, cantidad);

  for (int i = 0; i < cantidad; i++)
  {
    cout << pagos[i].toString() << endl;
  }

  cout << "\n\n\n";

  PrimerParcial parcial;
  parcial.listarRecaudacion();
  cout << "\n\n\n";
  parcial.listarAlumnosNoMorosos();
  cout << "\n\n\n";
  parcial.soloUnCurso();
  cout << "\n\n\n";
  parcial.generarEstadistica();
  parcial.mostrarEstadisticas();
  cout << "\n\n\n";
  parcial.cursosPremium(1003);
  return 0;
}