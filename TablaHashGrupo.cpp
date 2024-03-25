//
// Created by angel on 22/03/24.
//

#include <iostream>
#include "TablaHashGrupo.h"
#include "TablaHashCampo.h"

using namespace std;

TablaHashGrupo::TablaHashGrupo() {
    for (int i = 0; i < TAMANO_TABLA; ++i) {
        tabla[i] = nullptr;
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
    cout<<"Indice al agregar "<<nombreGrupo<<" : " <<indice<<endl;
    tabla[indice] = tablaCampo;
}

TablaHashCampo* TablaHashGrupo::obtenerTablaCampo(const std::string& nombreGrupo) {
    int indice = funcionHash(nombreGrupo);
    cout<<"Indice tabla :"<< indice <<endl;
    return tabla[indice];
}