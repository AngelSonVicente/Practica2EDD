

#ifndef PRACTICA2EDD_TABLAHASHCAMPO_H
#define PRACTICA2EDD_TABLAHASHCAMPO_H


#include "ArbolAVL.h"
#include "nombreCampos.h"

class TablaHashCampo {
private:
    static const int TAMANO_TABLA = 20;
    ArbolAVL* tabla[TAMANO_TABLA];

    nombreCampos Campos;
    int funcionHash(const std::string& clave);

public:

    TablaHashCampo();
    void agregarCampo(const std::string& nombreCampo);
    ArbolAVL* buscarCampo(const std::string& nombreCampo);
    ListaCampos* obtenerNombreCampos();

    void eliminarTodosCampos();

    nombreCampos *getCampos();
};


#endif //PRACTICA2EDD_TABLAHASHCAMPO_H
