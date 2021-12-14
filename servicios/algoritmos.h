#ifndef BIBLIOTECA_ALGORITMOS_H
#define BIBLIOTECA_ALGORITMOS_H
#include "../dominio/libro.h"
#include "../dominio/alumno.h"
#include <list>

struct Solucion {
    list<Alumno> alumnosAprobados;
    int cantidadAlumnosAprobados;
    int cantidadEstados;
};

Solucion maximizarLibrosAsignadosBack(list<Libro> listaLibros, int cantidadAlumnos, int puntajeMinimo);
Solucion maximizarLibrosAsignadosGreedy(list<Libro> listaLibros, int cantidadAlumnos, int puntajeMinimo);

#endif //BIBLIOTECA_ALGORITMOS_H
