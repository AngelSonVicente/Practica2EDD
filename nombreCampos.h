//
// Created by angel on 2/04/24.
//

#ifndef PRACTICA2EDD_NOMBRECAMPOS_H
#define PRACTICA2EDD_NOMBRECAMPOS_H

#include "string"

using namespace std;


class nombreCampos {

public:
    class Nodo{
    public:
        string nombre;

        Nodo* siguiente;
        Nodo(const string& nombre) : nombre(nombre), siguiente(nullptr) {}


    };
    Nodo* frente;
    Nodo* fin;
public:


    bool estaVacia() const;



    void imprimir() const;

    int obtenerTamanio() const;

    void agregar(const string &nombre);

    Nodo *obtenerCAmpo(int indice);
};


#endif //PRACTICA2EDD_NOMBRECAMPOS_H
