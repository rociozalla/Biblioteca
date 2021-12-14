#include "lectorLibros.h"

LectorLibros::LectorLibros() {

};

Libro * LectorLibros::leerLibro(string linea) {
    //Primer posicion del separador ;
    int posInicial = 0;
    int posFinal = linea.find(";");

    //Informacion entre posInicial y posFinal
    string id = linea.substr(posInicial, posFinal);

    //Segunda posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    string titulo = linea.substr(posInicial, posFinal - posInicial);

    //Tercera posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    string autor = linea.substr(posInicial, posFinal - posInicial);

    //Cuarta posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    string genero = linea.substr(posInicial, posFinal - posInicial);

    //Quinta posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    int cantidadPaginas = atoi(linea.substr(posInicial, posFinal - posInicial).c_str());

    //Sexta posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    int puntaje = atoi(linea.substr(posInicial, posFinal - posInicial).c_str());

    //Septima posicion del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    int cantidadEjemplares = atoi(linea.substr(posInicial, posFinal - posInicial).c_str());

    bool estado = false;

    Libro * libro = new Libro(id, titulo, autor, genero, cantidadPaginas, puntaje, cantidadEjemplares, estado);

    return libro;
}
