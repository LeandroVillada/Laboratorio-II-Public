#include "EstadisticaArchivo.h"


Estadistica EstadisticaArchivo::leer(int nroRegistro) {
  Estadistica est;
  FILE* p;
  p = fopen("estadisticas.dat", "rb");
  if (p == NULL) {
    return est;
  }
  fseek(p, nroRegistro * sizeof(Estadistica), SEEK_SET);
  fread(&est, sizeof(Estadistica), 1, p);
  fclose(p);
  return est;
}

bool EstadisticaArchivo::guardar(Estadistica est) {
  FILE* p = fopen("estadisticas.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&est, sizeof(Estadistica), 1, p);
  fclose(p);
  return ok;
}

bool EstadisticaArchivo::guardar(Estadistica est, int nroRegistro) {
  FILE* p = fopen("estadisticas.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Estadistica), SEEK_SET);
  bool ok = fwrite(&est, sizeof(Estadistica), 1, p);
  fclose(p);
  return ok;
}

int EstadisticaArchivo::getCantidad() {
  FILE* p = fopen("estadisticas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Estadistica);
  fclose(p);
  return cant;
}
