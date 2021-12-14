cmake_minimum_required(VERSION 3.19)
project(Biblioteca)

set(CMAKE_CXX_STANDARD 14)

add_executable(Biblioteca
        main.cpp
        dominio/libro.h
        dominio/libro.cpp
        utilidades/lectorLibros.h
        utilidades/lectorLibros.cpp
        servicios/algoritmos.h
        servicios/algoritmos.cpp
        dominio/alumno.h
        dominio/alumno.cpp
        )