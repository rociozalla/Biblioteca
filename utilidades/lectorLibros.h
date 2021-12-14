#ifndef BIBLIOTECA_LECTORLIBROS_H
#define BIBLIOTECA_LECTORLIBROS_H
#include <iostream>
#include "../dominio/libro.h"

using namespace std;

class LectorLibros {
    public:
        LectorLibros();
        Libro * leerLibro(string libro);
};

#endif //BIBLIOTECA_LECTORLIBROS_H
