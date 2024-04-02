cmake_minimum_required(VERSION 3.27)
project(Practica2EDD)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practica2EDD main.cpp
        ArbolAVL.cpp
        ArbolAVL.h
        Contacto.cpp
        Contacto.h
        TablaHashGrupo.cpp
        TablaHashGrupo.h
        TablaHashCampo.cpp
        TablaHashCampo.h
        Campo.cpp
        Campo.h
        ListaCampos.cpp
        ListaCampos.h
        Graficar.cpp
        Graficar.h
)
