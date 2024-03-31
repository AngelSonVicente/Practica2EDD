//
// Created by angel on 21/03/24.
//

#ifndef PRACTICA2EDD_ARBOLAVL_H
#define PRACTICA2EDD_ARBOLAVL_H

#include "Contacto.h"
#include "ListaCampos.h"

class NodoAVL {
public:
    ListaCampos* campos;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(ListaCampos* lc);
};

class ArbolAVL {
private:
    NodoAVL* raiz;

    NodoAVL* insertarRecursivo(NodoAVL* nodo, ListaCampos* campos);
    int altura(NodoAVL* nodo);
    int balanceFactor(NodoAVL* nodo);
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
    NodoAVL* balancear(NodoAVL* nodo);
    void imprimirRecursivo(NodoAVL* nodo);

public:
    ArbolAVL();

    void imprimir();

    void insertar(ListaCampos *campos, int indice);

    NodoAVL *insertarRecursivo(NodoAVL *nodo, ListaCampos *campos, int indice);





    string generarDot(const string &nombreArbol);

    void generarDotRecursivo(stringstream &ss, NodoAVL *nodo, const string &nombreRaiz);
};

#endif

//PRACTICA2EDD_ARBOLAVL_H
