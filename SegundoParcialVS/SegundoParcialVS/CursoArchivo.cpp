#include "CursoArchivo.h"

/**
 * It opens a file, seeks to the end of the file, gets the current position, divides it by the size of
 * the record, and returns the result
 *
 * @return The number of records in the file.
 */
int CursosArchivo::cantidadRegistros()
{
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    long cant = ftell(pFile) / tamanioRegistro;
    cerrarArchivo();
    return (int)cant;
}

// abrirArchivo(Modo modo)
// ABRE EL ARCHIVO EN EL MODO ESTABLECIDO POR EL PARAMETRO modo.
// DEVUELVE TRUE SI PUDO ABRIR Y FALSE SI NO PUDO ABRIR
/**
 * It opens a file in the specified mode, and returns true if it was successful
 *
 * @param modo
 *
 * @return A boolean value.
 */
bool CursosArchivo::abrirArchivo(Modo modo)
{
    switch (estado)
    {
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:
        cerrarArchivo();
        break;
    }
    switch (modo)
    {
    case SoloLectura:
        pFile = fopen(nombreArchivo, "rb");
        if (!pFile)
            return false;
        estado = AbiertoR;
        break;
    case Escritura:
        pFile = fopen(nombreArchivo, "wb");
        if (!pFile)
            return false;
        estado = AbiertoW;
        break;
    case Agregar:
        pFile = fopen(nombreArchivo, "ab");
        if (!pFile)
            return false;
        estado = AbiertoA;
        break;
    case LecturaEscritura:
        pFile = fopen(nombreArchivo, "rb+");
        if (!pFile)
            return false;
        estado = AbiertoRW;
        break;
    }
    return true;
}

void CursosArchivo::cerrarArchivo()
{
    fclose(pFile);
    estado = Cerrado;
}

CursosArchivo::CursosArchivo()
{
    Cursos registro;
    // Nombre para guardar o abrir los registros
    std::string nombre = "cursos.dat";
    nombreArchivo = new char[strlen(nombre.c_str()) + 1];
    if (nombreArchivo == NULL)
    {
        exit(1);
    }
    strcpy(nombreArchivo, nombre.c_str());

    tamanioRegistro = registro.getSize();
    pRegistro = (void *)malloc(tamanioRegistro);
    cantRegistros = cantidadRegistros();
    estado = Cerrado;
}

CursosArchivo::~CursosArchivo()
{
    delete nombreArchivo;
    if (pFile)
    {
        fclose(pFile);
    }
    free(pRegistro);
}

/**
 * It opens a file, seeks to a specific position, reads a record, and closes the file
 *
 * @param nroRegistro The number of the record to read.
 *
 * @return A Clase object.
 */
Cursos CursosArchivo::leer(int nroRegistro)
{
    Cursos obj;
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return obj;
    }

    fseek(pFile, nroRegistro * sizeof(Cursos), SEEK_SET);
    fread(&obj, sizeof(Cursos), 1, pFile);
    cerrarArchivo();
    return obj;
}

/**
 * It opens the file, seeks to the nth record, reads the record, and closes the file
 *
 * @param clase is a struct that contains the data I want to write to the file.
 * @param nroRegistro The number of the record to read.
 *
 * @return A boolean value.
 */
bool CursosArchivo::leer(Cursos &clase, int nroRegistro)
{
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Cursos), SEEK_SET);
    bool ok = fread(&clase, sizeof(Cursos), 1, pFile);
    cerrarArchivo();
    return ok;
}

/**
 * It reads all the records from the file into an array of Clase objects
 *
 * @param clases is an array of Clase objects
 * @param cantidad the amount of objects to read
 *
 * @return a boolean value.
 */
bool CursosArchivo::leerTodos(Cursos clases[], int cantidad)
{
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return false;
    }

    bool ok = fread(clases, sizeof(Cursos), cantidad, pFile);
    cerrarArchivo();
    return ok;
}

/**
 * It opens a file, writes a struct to it, and closes the file
 *
 * @param clase is a struct that contains the data that I want to save.
 *
 * @return a boolean value.
 */
bool CursosArchivo::guardar(Cursos clase)
{
    if (!abrirArchivo(Agregar))
    {
        estado = Cerrado;
        return false;
    }

    bool ok = fwrite(&clase, sizeof(Cursos), 1, pFile);
    cerrarArchivo();
    return ok;
}

/**
 * It opens a file, seeks to a specific position, writes a record, and closes the file
 *
 * @param clase is a struct that contains the data I want to save.
 * @param nroRegistro The number of the record to be written.
 *
 * @return a boolean value.
 */
bool CursosArchivo::guardar(Cursos clase, int nroRegistro)
{
    if (!abrirArchivo(LecturaEscritura))
    {
        estado = Cerrado;
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Cursos), SEEK_SET);
    bool ok = fwrite(&clase, sizeof(Cursos), 1, pFile);
    cerrarArchivo();
    return ok;
}

/**
 * It returns the number of records in the file.
 *
 * @return The number of records in the file.
 */
int CursosArchivo::getCantidadRegistros()
{
    return cantRegistros;
}

void CursosArchivo::mostrar(Cursos registro)
{
    registro.toString();
}

/**
 * It reads all the records from the file and displays them on the screen
 *
 * @return the value of the variable "cantRegistros"
 */
void CursosArchivo::mostrarArchivo()
{
    Cursos *registros = new Cursos[cantRegistros];
    if (registros == NULL)
    {
        return;
    }
    if (!leerTodos(registros, cantRegistros))
    {
        return;
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        cout << registros[i].toString() << endl;
        cout << endl;
    }
}

const char *CursosArchivo::getNombreArchivo()
{
    return nombreArchivo;
}
