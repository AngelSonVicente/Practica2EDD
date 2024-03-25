//
// Created by angel on 22/03/24.
//

#ifndef PRACTICA2EDD_TABLAHASHCAMPO_H
#define PRACTICA2EDD_TABLAHASHCAMPO_H


#include "ArbolAVL.h"

class TablaHashCampo {
private:
    static const int TAMANO_TABLA = 5;

    int funcionHash(const std::string& clave);

public:
    std::string tabla[TAMANO_TABLA];
    TablaHashCampo();
    void agregarCampo(const std::string& nombreCampo);
    bool buscarCampo(const std::string& nombreCampo);

};


#endif //PRACTICA2EDD_TABLAHASHCAMPO_H
