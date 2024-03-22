//
// Created by angel on 21/03/24.
//

#ifndef PRACTICA2EDD_ARBOLAVL_H
#define PRACTICA2EDD_ARBOLAVL_H

#include "Contacto.h"

class NodoAVL {
public:
    Contacto contacto;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(const Contacto& c);
};

class ArbolAVL {
private:
    NodoAVL* raiz;

    NodoAVL* insertarRecursivo(NodoAVL* nodo, const Contacto& contacto);
    int altura(NodoAVL* nodo);
    int balanceFactor(NodoAVL* nodo);
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
    NodoAVL* balancear(NodoAVL* nodo);
    void imprimirRecursivo(NodoAVL* nodo);

public:
    ArbolAVL();
    void insertar(const Contacto& contacto);
    void imprimir();
};

#endif

//PRACTICA2EDD_ARBOLAVL_H
