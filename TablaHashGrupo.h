//
// Created by angel on 22/03/24.
//

#ifndef PRACTICA2EDD_TABLAHASHGRUPO_H
#define PRACTICA2EDD_TABLAHASHGRUPO_H


#include <string>
#include "TablaHashCampo.h"

class TablaHashGrupo {

private:
    static const int TAMANO_TABLA = 20;
    TablaHashCampo tabla[TAMANO_TABLA];

    int funcionHash(const std::string& clave);

public:
    TablaHashGrupo();

    TablaHashCampo* obtenerTablaCampo(const std::string& nombreGrupo);

    ListaCampos *obtenerNombreGrupos();


    void agregarGrupo(const string &nombreGrupo, const string &nombreCampo);
};




#endif //PRACTICA2EDD_TABLAHASHGRUPO_H
