//
// Created by angel on 22/03/24.
//

#ifndef PRACTICA2EDD_TABLAHASHCAMPO_H
#define PRACTICA2EDD_TABLAHASHCAMPO_H


#include "ArbolAVL.h"

class TablaHashCampo {
private:
    static const int TAMANO_TABLA = 5;
    ArbolAVL* tabla[TAMANO_TABLA];

    int funcionHash(const std::string& clave);

public:
    TablaHashCampo();
    void agregarCampo(const std::string& nombreCampo);
    ArbolAVL* buscarCampo(const std::string& nombreCampo);
};


#endif //PRACTICA2EDD_TABLAHASHCAMPO_H
