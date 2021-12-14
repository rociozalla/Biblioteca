#include "alumno.h"

bool operator<(const Libro & primero, const Libro & segundo);

Alumno::Alumno() {
    this->libros = set<Libro>();
    this->puntaje = 0;
    this->puntajeRequerido = 0;
    this->aprobo = false;
}

Alumno::Alumno(set<Libro> libros, int puntaje, int puntajeRequerido, bool aprobo) {
    this->libros = libros;
    this->puntaje = puntaje;
    this->puntajeRequerido = puntajeRequerido;
    this->aprobo = aprobo;
}

void Alumno::asignarLibro(const Libro& libro) {
    libros.insert(libro);
    puntaje = puntaje + libro.obtenerPuntaje();

    if (puntaje >= puntajeRequerido) {
        aprobo = true;
    }
}

void Alumno::quitarLibro(const Libro& libro) {
    libros.erase(libros.find(libro)); // ver
    puntaje = puntaje - libro.obtenerPuntaje();

    if (puntaje < puntajeRequerido) {
        aprobo = false;
    }
}

void Alumno::mostrarLibros() {
    auto itLibros = libros.begin();
    for (itLibros; itLibros != libros.end(); itLibros++) {
        cout << itLibros->obtenerId() << endl;
    }
}

void Alumno::establecerPuntajeRequerido(int puntajeRequerido) {
    this->puntajeRequerido = puntajeRequerido;
}

set<Libro> Alumno::obtenerLibros() {
    return this->libros;
}

int Alumno::obtenerPuntaje() {
    return this->puntaje;
}

bool Alumno::estaAprobado() {
    return this->aprobo;
}

bool Alumno::estaLibro(const Libro& libro) {
    return (libros.find(libro) != libros.end());
}

