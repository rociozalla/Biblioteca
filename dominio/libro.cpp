#include "libro.h"

Libro::Libro() {

}

Libro::Libro(string id, string titulo, string autor, string genero, int cantidadPaginas, int puntaje, int cantidadEjemplares, bool asignado) {
    this->id = id;
    this->titulo = titulo;
    this->autor = autor;
    this->genero = genero;
    this->cantidadPaginas = cantidadPaginas;
    this->puntaje = puntaje;
    this->cantidadEjemplares = cantidadEjemplares;
    this->asignado = asignado;
}

void Libro::establecerId(string id) {
    this->id = id;
}

void Libro::establecerTitulo(string titulo) {
    this->titulo = titulo;
}

void Libro::establecerAutor(string autor) {
    this->autor = autor;
}

void Libro::establecerGenero(string genero) {
    this->genero = genero;
}

void Libro::establecerCantidadPaginas(int cantidadPaginas) {
    this->cantidadPaginas = cantidadPaginas;
}

void Libro::establecerPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

void Libro::establecerCantidadEjemplares(int cantidadEjemplares) {
    this->cantidadEjemplares = cantidadEjemplares;
}

void Libro::establecerEstadoAsignacion(bool asignado) {
    this->asignado = asignado;
}

string Libro::obtenerId() const {
    return this->id;
}

string Libro::obtenerTitulo() const {
    return this->titulo;
}

string Libro::obtenerAutor() const {
    return this->autor;
}

string Libro::obtenerGenero() const {
    return this->genero;
}

int Libro::obtenerCantidadPaginas() const {
    return this->cantidadPaginas;
}

int Libro::obtenerPuntaje() const {
    return this->puntaje;
}

int Libro::obtenerCantidadEjemplares() const {
    return this->cantidadEjemplares;
}

bool Libro::estaAsignado() const {
    return this->asignado;
}



