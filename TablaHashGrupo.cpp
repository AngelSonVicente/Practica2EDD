//
// Created by angel on 22/03/24.
//

#include <iostream>
#include "TablaHashGrupo.h"
#include "TablaHashCampo.h"
#include <fstream>


using namespace std;

TablaHashGrupo::TablaHashGrupo() {
    for (int i = 0; i < TAMANO_TABLA; ++i) {
        tabla[i] = nullptr; // Inicializamos cada posición con un puntero nulo
    }
}

int TablaHashGrupo::funcionHash(const std::string& clave) {
    int suma = 0;
    for (size_t i = 0; i < clave.length(); ++i) {
        suma += clave[i] * (i + 1);
    }
    return suma % TAMANO_TABLA;
}

void TablaHashGrupo::agregarGrupo(const std::string& nombreGrupo, TablaHashCampo* tablaCampo) {
    int indice = funcionHash(nombreGrupo);
    tabla[indice] = tablaCampo;
}

TablaHashCampo* TablaHashGrupo::obtenerTablaCampo(const std::string& nombreGrupo) {
    int indice = funcionHash(nombreGrupo);
    return tabla[indice];
}


