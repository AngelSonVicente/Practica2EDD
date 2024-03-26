//
// Created by angel on 22/03/24.
//

#include <string>
#include "TablaHashCampo.h"
#include "ArbolAVL.h"

using namespace std;

TablaHashCampo::TablaHashCampo() {
    for (int i = 0; i < TAMANO_TABLA; ++i) {
        tabla[i] = nullptr; // Inicializamos cada posición con un puntero nulo
    }
}

int TablaHashCampo::funcionHash(const std::string& clave) {
    int suma = 0;
    for (size_t i = 0; i < clave.length(); ++i) {
        suma += clave[i] * (i + 1); // Multiplicamos por la posición del carácter
    }
    return suma % TAMANO_TABLA;
}

void TablaHashCampo::agregarCampo(const std::string& nombreCampo) {
    int indice = funcionHash(nombreCampo);
    tabla[indice] = new ArbolAVL(); // Creamos un nuevo árbol AVL para este campo
}

ArbolAVL* TablaHashCampo::buscarCampo(const std::string& nombreCampo) {
    int indice = funcionHash(nombreCampo);
    return tabla[indice]; // Retornamos el puntero al árbol AVL asociado a este campo
}
