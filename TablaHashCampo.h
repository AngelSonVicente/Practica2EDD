

#ifndef PRACTICA2EDD_TABLAHASHCAMPO_H
#define PRACTICA2EDD_TABLAHASHCAMPO_H


#include "ArbolAVL.h"

class TablaHashCampo {
private:
    static const int TAMANO_TABLA = 20;
    ListaCampos* nombreCampos = new ListaCampos(); //NO JALA
    ArbolAVL* tabla[TAMANO_TABLA];

    int funcionHash(const std::string& clave);

public:
    TablaHashCampo();
    void agregarCampo(const std::string& nombreCampo);
    ArbolAVL* buscarCampo(const std::string& nombreCampo);
    ListaCampos* obtenerNombreCampos();
};


#endif //PRACTICA2EDD_TABLAHASHCAMPO_H
