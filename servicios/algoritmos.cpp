#include "algoritmos.h"
#include "../dominio/libro.h"

using namespace std;

bool operator<(const Libro & primero, const Libro & segundo);

bool esFactible (Libro & libroAAsignar, list<Alumno>::iterator itAlumnos) {
    return ((!itAlumnos->estaLibro(libroAAsignar)) && (!libroAAsignar.estaAsignado()));
}

void elegirMejorSolucion(Solucion & actual, Solucion & mejor) {
    if (actual.cantidadAlumnosAprobados > mejor.cantidadAlumnosAprobados)
        mejor = actual;
}

void agregarASolucion(Solucion & actual, list<Alumno>::iterator itAlumnos) {
    actual.alumnosAprobados.push_front(* itAlumnos);
    actual.cantidadAlumnosAprobados++;
}

void quitarDeSolucion(Solucion & actual, list<Alumno>::iterator itAlumnos) {
    actual.alumnosAprobados.pop_front();
    actual.cantidadAlumnosAprobados--;
}

void backBiblioteca(list<Alumno> & alumnos, list<Libro>::iterator itLibros, list<Libro>::iterator finItLibros, int & nroLibro, int cantidadAlumnos, int puntajeMinimo, Solucion & actual, Solucion & mejor, int & cantidadEstados) {
    cantidadEstados++;

    // estado solucion / final
    if ((itLibros == finItLibros) or (cantidadAlumnos == actual.cantidadAlumnosAprobados))  {
        elegirMejorSolucion(actual, mejor);
    } else { // continuar busqueda
        list<Alumno>::iterator itAlumnos = alumnos.begin();

        while (itAlumnos != alumnos.end()) { // mientras queden alumnos por aprobar
            if (esFactible(* itLibros, itAlumnos)) { // chequeo condiciones: no superar cantidad de ejemplares y no asignar mas de un ejemplar al mismo alumno
                if (!itAlumnos->estaAprobado()) { // poda - si el alumno aprobo no hago nada
                    itLibros->establecerEstadoAsignacion(true);
                    itAlumnos->asignarLibro(* itLibros);

                    if (itAlumnos->estaAprobado()) { // si el alumno aprobo lo agrego a la lista solucion
                        agregarASolucion(actual, itAlumnos);
                    }

                    // back
                    nroLibro++;
                    itLibros++;
                    backBiblioteca(alumnos, itLibros, finItLibros, nroLibro, cantidadAlumnos,
                                   puntajeMinimo, actual, mejor, cantidadEstados);
                    nroLibro--;
                    itLibros--;

                    if (itAlumnos->estaAprobado()) { // si habia aprobado quito al alumno de la solucion
                        quitarDeSolucion(actual, itAlumnos);
                    }

                    itLibros->establecerEstadoAsignacion(false);
                    itAlumnos->quitarLibro(* itLibros);
                }
            }
            itAlumnos++;
        }

        if (!itLibros->estaAsignado()) {
            itLibros++;
        }
    }
}

void inicializarListaAlumnos(list<Alumno> & alumnos, int cantidadAlumnos, int puntajeMinimo) {
    for (int i = 0; i < cantidadAlumnos; i++) {
        Alumno alumnoActual = Alumno();
        alumnoActual.establecerPuntajeRequerido(puntajeMinimo);
        alumnos.push_front(alumnoActual);
    }
}

Solucion maximizarLibrosAsignadosBack(list<Libro> listaLibros, int cantidadAlumnos, int puntajeMinimo) {
    int nroLibro = 0;

    Solucion mejor;
    mejor.cantidadAlumnosAprobados = 0;

    Solucion actual;
    actual.cantidadAlumnosAprobados = 0;

    list<Alumno> alumnos;
    inicializarListaAlumnos(alumnos, cantidadAlumnos, puntajeMinimo);

    int cantidadEstados = 0;

    list<Libro>::iterator itLibros = listaLibros.begin();
    list<Libro>::iterator finItLibros = listaLibros.end();

    backBiblioteca(alumnos, itLibros, finItLibros, nroLibro, cantidadAlumnos, puntajeMinimo, actual, mejor, cantidadEstados);
    mejor.cantidadEstados = cantidadEstados;

    return mejor;
}

void greedyBiblioteca(list<Alumno> & alumnos, list<Libro> listaLibros, int cantidadAlumnos, int puntajeMinimo, Solucion & solucion, int & cantidadEstados) {
    // recorre todos los libros
    for (auto itLibros = listaLibros.begin(); itLibros != listaLibros.end(); itLibros++) {

        // mientras el libro no este asignado y hayan alumnos a los que se les pueda asignar continuo busqueda
        list<Alumno>::iterator itAlumnos = alumnos.begin();
        while ((itAlumnos != alumnos.end()) && (!itLibros->estaAsignado())) {
            cantidadEstados++;

            if ((!itAlumnos->estaAprobado()) && (esFactible(*itLibros, itAlumnos))) {
                itAlumnos->asignarLibro(*itLibros);
                itLibros->establecerEstadoAsignacion(true);
                if (itAlumnos->estaAprobado())
                    agregarASolucion(solucion, itAlumnos);
            }

            itAlumnos++;
        }
    }
}

bool compFirst(const Libro & primero, const Libro & segundo) { return primero.obtenerPuntaje() < segundo.obtenerPuntaje(); }
// bool compFirst(const Libro & primero, const Libro & segundo) { return primero.obtenerPuntaje() > segundo.obtenerPuntaje(); }

Solucion maximizarLibrosAsignadosGreedy(list<Libro> listaLibros, int cantidadAlumnos, int puntajeMinimo) {
    Solucion solucion;
    solucion.cantidadAlumnosAprobados = 0;

    list<Alumno> alumnos;
    inicializarListaAlumnos(alumnos, cantidadAlumnos, puntajeMinimo);

    int cantidadEstados = 0;

    listaLibros.sort(compFirst); // ordena ascendentemente

    greedyBiblioteca(alumnos, listaLibros, cantidadAlumnos, puntajeMinimo, solucion, cantidadEstados);
    solucion.cantidadEstados = cantidadEstados;

    return solucion;
}