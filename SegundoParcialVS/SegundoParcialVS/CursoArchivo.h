#pragma once
#include <iostream>
#include <string>
using namespace std;

///////////////////////////
// TIPOS ENUMERADOS PARA USAR CON LA CLASE ARCHIVO
enum Estado
{ // DEFINE LOS ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
    NoExiste,
    Cerrado,
    AbiertoR,
    AbiertoW,
    AbiertoA,
    AbiertoRW
};

enum Modo
{ // DEFINE LOS MODOS DE APERTURA DE UN ARCHIVO
    SoloLectura,
    Escritura,
    Agregar,
    LecturaEscritura
};

class Cursos
{
private:
    int _idcurso;

public:
    int getIdCurso() { return _idcurso; }
    void setIdCurso(int idcurso) {
        _idcurso = idcurso;
    }
    std::string toString() {
        std::string cadena;
        cadena = std::to_string(_idcurso);
        return cadena;
    }
    int getSize()
    {
        return sizeof *this;
    }
    void operator=(Cursos aux)
    {
        _idcurso = aux._idcurso;
    }

    friend ostream &operator<<(ostream &salida, Cursos &obj)
    {
        cout << "ID Curso: ";
        salida << obj._idcurso << endl;
        return salida;
    }
    friend istream &operator>>(istream &entrada, Cursos &obj)
    {
        cout << "ID Curso: ";
        entrada >> obj._idcurso;
        return entrada;
    }
    bool comparaID(Cursos *temp)
    {
        Cursos *aux = temp;
        if (_idcurso == aux->_idcurso)
            return true;
        return false;
    }
};

class CursosArchivo
{
private:
    FILE *pFile;
    int tamanioRegistro;
    void *pRegistro;
    char *nombreArchivo;
    int cantRegistros;
    int estado;
    int cantidadRegistros();
    bool abrirArchivo(Modo modo);
    void cerrarArchivo();

public:
    CursosArchivo();
    ~CursosArchivo();
    // FUNCIONES ARCHIVOS
    Cursos leer(int nroRegistro);
    bool leer(Cursos &clase, int nroRegistro);
    bool leerTodos(Cursos estadisticas[], int cantidad);
    bool guardar(Cursos clase);
    bool guardar(Cursos clase, int nroRegistro);
    int getCantidadRegistros();

    void mostrar(Cursos);

    void mostrarArchivo();

    const char *getNombreArchivo();
};
