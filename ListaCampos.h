//
// Created by MSI on 27/03/2024.
//

#ifndef PRACTICA2EDD_LISTACAMPOS_H
#define PRACTICA2EDD_LISTACAMPOS_H


#include "Campo.h"

using namespace std;

class ListaCampos {
private:
    Campo* cabeza;

public:
    ListaCampos();
    ~ListaCampos();
    void agregarCampo(const std::string& nombre, const std::string& valor);
    Campo* obtenerCampo(int indice) const;
    int obtenerTamanio() const;

    void imprimir() const;
};


#endif //PRACTICA2EDD_LISTACAMPOS_H
