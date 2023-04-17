#pragma once
#include <string>
#include "Fecha.h"

class Estudiante
{
public:
    std::string getApellidos();
    std::string getNombres();
    std::string toString();
    int getLegajo();
    Fecha getFechaNacimiento();
    int getEdad();
    void setApellidos(std::string apellidos);
    void setNombres(std::string nombres);
    void setLegajo(int legajo);
    void setFechaNacimiento(Fecha fnac);
    Estudiante(int legajo, const char *apellido, const char *nombre, int dia, int mes, int anio)
    {
        _legajo = legajo;
        strcpy(_apellidos, apellido);
        strcpy(_nombres, nombre);
        _fnac.setDia(dia);
        _fnac.setMes(mes);
        _fnac.setAnio(anio);
    }
    Estudiante()
    {
        _legajo = 0;
        strcpy(_apellidos, "");
        strcpy(_nombres, "");
        _fnac.setDia(1);
        _fnac.setMes(1);
        _fnac.setAnio(2000);
    }

private:
    char _apellidos[50];
    char _nombres[50];
    int _legajo;
    Fecha _fnac;
};
