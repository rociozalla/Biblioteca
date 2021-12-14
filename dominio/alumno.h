#ifndef BIBLIOTECA_ALUMNO_H
#define BIBLIOTECA_ALUMNO_H
#include <set>
#include "libro.h"

class Alumno {
private:
     set<Libro> libros;
     int puntaje;
     int puntajeRequerido;
     bool aprobo;

public:
    Alumno();
    Alumno(set<Libro> libros, int puntaje, int puntajeRequerido, bool aprobo);
    ~Alumno() = default;

    void asignarLibro(const Libro& libro);
    void quitarLibro(const Libro& libro);
    void establecerPuntajeRequerido(int puntajeRequerido);
    void mostrarLibros();

    int obtenerPuntaje();
    set<Libro> obtenerLibros();
    bool estaAprobado();
    bool estaLibro(const Libro& libro);

};


#endif //BIBLIOTECA_ALUMNO_H
