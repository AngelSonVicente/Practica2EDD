//
// Created by MSI on 31/03/2024.
//

#ifndef PRACTICA2EDD_GRAFICAR_H
#define PRACTICA2EDD_GRAFICAR_H

#include "string"

using namespace std;
#include "iostream"
#include "ListaCampos.h"
#include "TablaHashGrupo.h"

class Graficar {

    void graficarArbol(string contenidoDot){


    }


public:
    void garficarEstructuraCompleta(ListaCampos* nombreGrupos, TablaHashGrupo* grupos){

        for (int i = 0; i < nombreGrupos->obtenerTamanio(); ++i) {

            cout<<endl<<endl<<  grupos->obtenerTablaCampo(nombreGrupos->obtenerCampo(i)->obtenerNombre())->buscarCampo(nombreGrupos->obtenerCampo(0)->obtenerNombre())->generarDot(nombreGrupos->obtenerCampo(i)->obtenerNombre());


        }


    }
};


#endif //PRACTICA2EDD_GRAFICAR_H
