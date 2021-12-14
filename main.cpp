#include <iostream>
#include <fstream>
#include <list>
#include "dominio/libro.h"
#include "utilidades/lectorLibros.h"
#include "servicios/algoritmos.h"

using namespace std;

bool operator<(const Libro & primero, const Libro & segundo) {
    return primero.obtenerId() < segundo.obtenerId();
}

void procesar_archivo_entrada(string origen, list<Libro> & destino);
void mostrarListaLibros(list<Libro> listaLibros);
void mostrarListaAlumnos(list<Alumno> listaAlumnos);
void menu(list<Libro> listaLibros);

int main() {
    string dataset;
    list<Libro> listaLibros;
    cout << "Ingrese nombre del dataset: ";
    cin >> dataset;
    procesar_archivo_entrada("../datasets/" + dataset, listaLibros);
    // mostrarListaLibros(listaLibros);
    menu(listaLibros);

    return 0;
}

void menu (list<Libro> listaLibros) {
    int opcion;

    while (true) {
        cout << "--------------------------------------------------------" << endl;
        cout << "1 - Comenzar simulacion con backtracking" <<endl;
        cout << "2 - Comenzar simulacion con greedy" << endl;
        cout << "3 - Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int alumnos, puntaje;

                cout << "Ingrese cantidad de alumnos y puntaje minimo para aprobar: " << endl;
                cin >> alumnos >> puntaje;

                Solucion solucion = maximizarLibrosAsignadosBack(listaLibros, alumnos, puntaje);
                list<Alumno> listaAlumnosAprobados = solucion.alumnosAprobados;

                cout << "Pueden completar el puntaje minimo " << solucion.cantidadAlumnosAprobados <<
                     " alumnos, en " << solucion.cantidadEstados << " estados, con la siguiente asignacion: " << endl;
                mostrarListaAlumnos(listaAlumnosAprobados);
                break;
            }
            case 2: {
                int alumnos, puntaje;

                cout << "Ingrese cantidad de alumnos y puntaje minimo para aprobar: " << endl;
                cin >> alumnos >> puntaje;

                Solucion solucion = maximizarLibrosAsignadosGreedy(listaLibros, alumnos, puntaje);
                list<Alumno> listaAlumnosAprobados = solucion.alumnosAprobados;

                cout << "Pueden completar el puntaje minimo " << solucion.cantidadAlumnosAprobados <<
                     " alumnos, en " << solucion.cantidadEstados << " estados, con la siguiente asignacion: " << endl;
                mostrarListaAlumnos(listaAlumnosAprobados);
                break;
            }
            case 3: {
                cout << "Hasta luego" << endl;
                return;
            }
            default: {
                cout << "Ingrese una opcion valida" << endl;
            }
        }
    }
}

void procesar_archivo_entrada(string origen, list<Libro> & destino) {
    ifstream archivo(origen);
    Libro * libroLeido;
    LectorLibros lectorLibros;

    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        // int cantidadLibros = atoi(linea.c_str());

        while (getline(archivo, linea)) { //Leemos de una linea completa por vez (getline)
            libroLeido = lectorLibros.leerLibro(linea);
            destino.push_back(* libroLeido);

            int cantEjemplares = libroLeido->obtenerCantidadEjemplares();
            while (cantEjemplares > 1) {
                destino.push_back(* libroLeido);
                cantEjemplares--;
            }
        }

        int cantidadLibros = destino.size();
        cout << "Se cargaron " << cantidadLibros << " libros." << endl; // 5 o 7?
    }
}

void mostrarListaLibros(list<Libro> lista) {
    list<Libro>::iterator it = lista.begin();

    while (it != lista.end()) {
        cout << "Id: " << it->obtenerId() << endl;
        cout << "Titulo: " << it->obtenerTitulo() << endl;
        cout << "Autor: " << it->obtenerAutor() << endl;
        cout << "Genero: " << it->obtenerGenero() << endl;
        cout << "Cantidad de paginas: " << it->obtenerCantidadPaginas() << endl;
        cout << "Puntaje: " << it->obtenerPuntaje() << endl;
        cout << "Cantidad de ejemplares: " << it->obtenerCantidadEjemplares() << endl;
        cout << "Estado: " << it->estaAsignado() << endl;
        it++;
    }
}

void mostrarListaAlumnos(list<Alumno> lista) {
    list<Alumno>::iterator itAlumnos = lista.begin();

    int alumno = 1;
    while (itAlumnos != lista.end()) {
        cout << "Alumno: " << alumno << endl;
        cout << "Libros asignados: " << itAlumnos->obtenerLibros().size() << endl;
        itAlumnos->mostrarLibros();

        alumno++;
        itAlumnos++;
    }
}