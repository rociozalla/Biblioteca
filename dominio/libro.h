#ifndef BIBLIOTECA_LIBRO_H
#define BIBLIOTECA_LIBRO_H
#include <iostream>

using namespace std;

class Libro {
private:
    string id;
    string titulo;
    string autor;
    string genero;
    int cantidadPaginas;
    int puntaje;
    int cantidadEjemplares;
    bool asignado;

public:
    Libro();
    Libro(string id, string titulo, string autor, string genero, int cantidadPaginas, int puntaje, int cantidadEjemplares, bool asignado);
    ~Libro() = default;

    void establecerId(string id);
    void establecerTitulo(string titulo);
    void establecerAutor(string autor);
    void establecerGenero(string genero);
    void establecerCantidadPaginas(int cantidadPaginas);
    void establecerPuntaje(int puntaje);
    void establecerCantidadEjemplares(int cantidadEjemplares);
    void establecerEstadoAsignacion(bool asignado);

    string obtenerId() const;
    string obtenerTitulo() const;
    string obtenerAutor() const;
    string obtenerGenero() const;
    int obtenerCantidadPaginas() const;
    int obtenerPuntaje() const;
    int obtenerCantidadEjemplares() const;
    bool estaAsignado() const;
};

#endif //BIBLIOTECA_LIBRO_H
