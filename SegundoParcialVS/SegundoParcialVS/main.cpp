#include <iostream>
#include <iomanip>
using namespace std;
#include "EstudiantesArchivo.h"
#include "InscripcionesArchivo.h"
#include "CursoArchivo.h"

void cargarEstudiante()
{
  FILE *p;
  p = fopen("estudiantes.dat", "wb");
  if (p == NULL)
  {
    return;
  }
  fclose(p);

  EstudiantesArchivo archivo;

  Estudiante registro1(1, "Garcia", "Jose", 16, 10, 1987);
  archivo.guardar(registro1);
  Estudiante registro2(2, "Gonzalez", "Antonio", 3, 10, 1990);
  archivo.guardar(registro2);
  Estudiante registro3(3, "Rodriguez", "Juan", 8, 3, 1992);
  archivo.guardar(registro3);
  Estudiante registro4(4, "Fernandez", "Manuel", 5, 2, 1990);
  archivo.guardar(registro4);
  Estudiante registro5(5, "Lopez", "Francisco", 12, 4, 1987);
  archivo.guardar(registro5);
  Estudiante registro6(6, "Martinez", "Luis", 19, 9, 2001);
  archivo.guardar(registro6);
  Estudiante registro7(7, "Sanchez", "Javier", 28, 8, 1990);
  archivo.guardar(registro7);
  Estudiante registro8(8, "Perez", "Miguel", 14, 3, 2004);
  archivo.guardar(registro8);
  Estudiante registro9(9, "Gomez", "Carlos", 7, 11, 1983);
  archivo.guardar(registro9);
  Estudiante registro10(10, "Martin", "Angel", 15, 9, 2004);
  archivo.guardar(registro10);
  Estudiante registro11(11, "Jimenez", "Jesus", 5, 7, 1997);
  archivo.guardar(registro11);
  Estudiante registro12(12, "Ruiz", "David", 27, 3, 1992);
  archivo.guardar(registro12);
  Estudiante registro13(13, "Hernandez", "Daniel", 16, 6, 2004);
  archivo.guardar(registro13);
  Estudiante registro14(14, "Diaz", "Pedro", 4, 3, 1991);
  archivo.guardar(registro14);
  Estudiante registro15(15, "Moreno", "Alejandro", 23, 10, 2000);
  archivo.guardar(registro15);
  Estudiante registro16(16, "Lamas", "Maria", 14, 5, 1982);
  archivo.guardar(registro16);
  Estudiante registro17(17, "Álvarez", "Alberto", 24, 11, 1992);
  archivo.guardar(registro17);
  Estudiante registro18(18, "Romero", "Pablo", 2, 12, 1981);
  archivo.guardar(registro18);
  Estudiante registro19(19, "Alonso", "Rafael", 18, 6, 1989);
  archivo.guardar(registro19);
  Estudiante registro20(20, "Gutierrez", "Fernando", 6, 1, 1997);
  archivo.guardar(registro20);
  Estudiante registro21(21, "Navarro", "Jorge", 1, 4, 1996);
  archivo.guardar(registro21);
  Estudiante registro22(22, "Torres", "Ramon", 10, 10, 1987);
  archivo.guardar(registro22);
  Estudiante registro23(23, "Dominguez", "Sergio", 13, 11, 1986);
  archivo.guardar(registro23);
  Estudiante registro24(24, "Vazquez", "Enrique", 10, 11, 1983);
  archivo.guardar(registro24);
  Estudiante registro25(25, "Ramos", "Andres", 8, 3, 1991);
  archivo.guardar(registro25);
  Estudiante registro26(26, "Gil", "Diego", 25, 12, 1982);
  archivo.guardar(registro26);
  Estudiante registro27(27, "Ramirez", "Vicente", 22, 1, 1987);
  archivo.guardar(registro27);
  Estudiante registro28(28, "Serrano", "Adrian", 17, 6, 1997);
  archivo.guardar(registro28);
  Estudiante registro29(29, "Blanco", "Victor", 17, 2, 2002);
  archivo.guardar(registro29);
  Estudiante registro30(30, "Molina", "Alvaro", 6, 6, 1982);
  archivo.guardar(registro30);
  Estudiante registro31(31, "Morales", "Ignacio", 5, 3, 1997);
  archivo.guardar(registro31);
  Estudiante registro32(32, "Suarez", "Raul", 22, 1, 1984);
  archivo.guardar(registro32);
  Estudiante registro33(33, "Ortega", "Eduardo", 22, 6, 1984);
  archivo.guardar(registro33);
  Estudiante registro34(34, "Delgado", "Ivan", 27, 1, 1985);
  archivo.guardar(registro34);
  Estudiante registro35(35, "Castro", "Oscar", 11, 5, 1986);
  archivo.guardar(registro35);
  Estudiante registro36(36, "Ortiz", "Ruben", 14, 8, 1987);
  archivo.guardar(registro36);
  Estudiante registro37(37, "Rubio", "Joaquin", 7, 12, 2004);
  archivo.guardar(registro37);
  Estudiante registro38(38, "Marin", "Santiago", 12, 12, 1990);
  archivo.guardar(registro38);
  Estudiante registro39(39, "Sanz", "Mario", 10, 4, 1983);
  archivo.guardar(registro39);
  Estudiante registro40(40, "Villagra", "Roberto", 4, 8, 1995);
  archivo.guardar(registro40);
}

void listarArchivoEstudiantes()
{
  EstudiantesArchivo archivo;
  int count = archivo.getCantidad();
  Estudiante *registro = new Estudiante[count];
  archivo.leerTodos(registro, count);

  // ENCABEZADO
  std::cout << left;
  std::cout << setw(2) << "";
  std::cout << setw(9) << "LEGAJO";
  std::cout << setw(30) << "NOMBRE";
  std::cout << setw(30) << "APELLIDO";
  std::cout << setw(15) << "FECHA DE NACIMIENTO";
  std::cout << "\n------------------------------------------------------------------------------------------" << std::endl;
  for (int i = 0; i < count; i++)
  {
    // cout << registro[i].toString() << endl;
    std::cout << left;
    std::cout << setw(2) << "";
    std::cout << setw(9) << registro[i].getLegajo();
    std::cout << setw(30) << registro[i].getNombres();
    std::cout << setw(30) << registro[i].getApellidos();
    std::cout << setw(15) << registro[i].getFechaNacimiento().toString();
    std::cout << std::endl;
  }
}

void cargarInscripcion()
{
  FILE *p;
  p = fopen("inscripciones.dat", "wb");
  if (p == NULL)
  {
    return;
  }
  fclose(p);
  InscripcionesArchivo archivo;

  Inscripcion registro1(1, 10, 18, 8);
  archivo.guardar(registro1);
  Inscripcion registro2(2, 4, 25, 0);
  archivo.guardar(registro2);
  Inscripcion registro3(3, 10, 31, 4);
  archivo.guardar(registro3);
  Inscripcion registro4(4, 6, 39, 2);
  archivo.guardar(registro4);
  Inscripcion registro5(5, 4, 8, 6);
  archivo.guardar(registro5);
  Inscripcion registro6(6, 11, 25, 4);
  archivo.guardar(registro6);
  Inscripcion registro7(7, 7, 23, 7);
  archivo.guardar(registro7);
  Inscripcion registro8(8, 20, 38, 1);
  archivo.guardar(registro8);
  Inscripcion registro9(9, 6, 31, 1);
  archivo.guardar(registro9);
  Inscripcion registro10(10, 13, 30, 2);
  archivo.guardar(registro10);
  Inscripcion registro11(11, 18, 11, 5);
  archivo.guardar(registro11);
  Inscripcion registro12(12, 7, 21, 3);
  archivo.guardar(registro12);
  Inscripcion registro13(13, 14, 10, 9);
  archivo.guardar(registro13);
  Inscripcion registro14(14, 22, 34, 7);
  archivo.guardar(registro14);
  Inscripcion registro15(15, 1, 5, 7);
  archivo.guardar(registro15);
  Inscripcion registro16(16, 4, 8, 8);
  archivo.guardar(registro16);
  Inscripcion registro17(17, 3, 38, 2);
  archivo.guardar(registro17);
  Inscripcion registro18(18, 5, 28, 1);
  archivo.guardar(registro18);
  Inscripcion registro19(19, 15, 12, 3);
  archivo.guardar(registro19);
  Inscripcion registro20(20, 2, 5, 10);
  archivo.guardar(registro20);
  Inscripcion registro21(21, 1, 26, 4);
  archivo.guardar(registro21);
  Inscripcion registro22(22, 2, 19, 3);
  archivo.guardar(registro22);
  Inscripcion registro23(23, 3, 38, 4);
  archivo.guardar(registro23);
  Inscripcion registro24(24, 9, 18, 8);
  archivo.guardar(registro24);
  Inscripcion registro25(25, 20, 37, 10);
  archivo.guardar(registro25);
  Inscripcion registro26(26, 5, 35, 0);
  archivo.guardar(registro26);
  Inscripcion registro27(27, 1, 17, 1);
  archivo.guardar(registro27);
  Inscripcion registro28(28, 18, 22, 5);
  archivo.guardar(registro28);
  Inscripcion registro29(29, 1, 3, 5);
  archivo.guardar(registro29);
  Inscripcion registro30(30, 8, 4, 0);
  archivo.guardar(registro30);
  Inscripcion registro31(31, 5, 2, 8);
  archivo.guardar(registro31);
  Inscripcion registro32(32, 6, 33, 0);
  archivo.guardar(registro32);
  Inscripcion registro33(33, 21, 5, 3);
  archivo.guardar(registro33);
  Inscripcion registro34(34, 9, 31, 0);
  archivo.guardar(registro34);
  Inscripcion registro35(35, 4, 9, 3);
  archivo.guardar(registro35);
  Inscripcion registro36(36, 23, 39, 5);
  archivo.guardar(registro36);
  Inscripcion registro37(37, 11, 24, 5);
  archivo.guardar(registro37);
  Inscripcion registro38(38, 14, 34, 2);
  archivo.guardar(registro38);
  Inscripcion registro39(39, 12, 22, 1);
  archivo.guardar(registro39);
  Inscripcion registro40(40, 8, 32, 7);
  archivo.guardar(registro40);
}

void listarArchivoInscripcion()
{
  InscripcionesArchivo archivo;
  int count = archivo.getCantidad();
  Inscripcion *registro = new Inscripcion[count];
  archivo.leerTodos(registro, count);

  // ENCABEZADO
  std::cout << left;
  std::cout << setw(2) << "";
  std::cout << setw(6) << "ID";
  std::cout << setw(11) << "ID CURSO";
  std::cout << setw(9) << "LEGAJO";
  std::cout << setw(7) << "NOTA";
  std::cout << "\n----------------------------------" << std::endl;
  for (int i = 0; i < count; i++)
  {
    // cout << registro[i].toString() << endl;
    std::cout << left;
    std::cout << setw(2) << "";
    std::cout << setw(6) << registro[i].getId();
    std::cout << setw(11) << registro[i].getIdCurso();
    std::cout << setw(9) << registro[i].getLegajo();
    std::cout << setw(7) << registro[i].getNota();
    std::cout << std::endl;
  }
}

void cargarCursos()
{
  FILE *p;
  p = fopen("cursos.dat", "wb");
  if (p == NULL)
  {
    return;
  }
  fclose(p);
  Cursos curso;
  CursosArchivo archivo;

  for (int i = 0; i < 24; i++)
  {
    curso.setIdCurso(i + 1);
    archivo.guardar(curso);
  }
}

void listarArchivoCursos()
{
  CursosArchivo archivo;
  int count = archivo.getCantidadRegistros();
  Cursos *registro = new Cursos[count];
  archivo.leerTodos(registro, count);
  for (int i = 0; i < count; i++)
  {
    cout << registro[i].toString() << endl;
  }
}

#include "SegundoParcial.h"

int main()
{

  // cargarEstudiante();
  listarArchivoEstudiantes();
  std::cout << std::endl;
  cargarInscripcion();
  listarArchivoInscripcion();
  std::cout << std::endl;
  // cargarCursos();
  // listarArchivoCursos();

  SegundoParcial prueba;
  prueba.alumnosDesaprobados();
  std::cout << std::endl;
  prueba.peorCurso();
  std::cout << std::endl;
  return 0;
}