#pragma once
#include <iostream>
using namespace std;
#include "ResumenDiarioArchivo.h"
class ModeloParcial
{
public:
    // 1) El nombre del tipo de combustible que haya registrado el precio por litro más caro. Si existe más de un tipo de combustible que cumpla esta condición, mostrar el primero que encuentren en el archivo.
    void punto1();
    int buscarPrecioPorLitroMasCaro();
    std::string obtenerTipoDeCombustible(int idTipoCombustible);
    // 2) A partir de un IDEstación que se ingresa como parámetro, mostrar los meses en los que no se haya vendido Nafta Súper en esa estación.
    void punto2();
    // 3) El nombre del tipo de combustible que haya registrado el precio por litro promedio más caro. Mostrar todos los tipos de combustibles que cumplan esta condición.
    void punto3();
    // 4) Hacer un archivo llamado Anuario.dat que a partir de un año que se ingrese por teclado genere un resumen mensual con el total de litros de combustibles vendidos en ese año y mes (en total se deben generar 12 registros).
    //     Aclaraciones:
    //     El archivo Anuario.dat debe contener solamente el resumen del último año que se ingresó.
    //     Si el año ingresado no tiene litros acumulados para ninguno de los 12 meses, entonces no debe generar el anuario y mostrar un mensaje aclaratorio al usuario.
    void punto4();
    // 5) Mostrar el archivo Anuario.dat con el siguiente formato:
    //     Año: XXXX

    //     Mes		Total litros
    //     Enero		9999
    //     Febrero	    9999
    //     Marzo		9999
    //     . . .
    //     Diciembre	9999
    void punto5();
};
