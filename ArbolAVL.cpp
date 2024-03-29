#include "ArbolAVL.h"
#include <iostream>


NodoAVL::NodoAVL(ListaCampos* lc) : campos(lc), izquierda(nullptr), derecha(nullptr), altura(1) {}

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

NodoAVL* ArbolAVL::insertarRecursivo(NodoAVL* nodo, ListaCampos* campos, int indice) {
    if (nodo == nullptr) {
        return new NodoAVL(campos);
    }

    if (campos->obtenerCampo(indice)->obtenerNombre() < nodo->campos->obtenerCampo(indice)->obtenerNombre()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, campos, indice);
    } else {
        nodo->derecha = insertarRecursivo(nodo->derecha, campos, indice);
    }

    return balancear(nodo);
}

void ArbolAVL::insertar(ListaCampos* campos, int indice) {
    raiz = insertarRecursivo(raiz, campos, indice);
}

int ArbolAVL::altura(NodoAVL* nodo) {
    return nodo ? nodo->altura : 0;
}

int ArbolAVL::balanceFactor(NodoAVL* nodo) {
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->izquierda;
    nodo->izquierda = nuevaRaiz->derecha;
    nuevaRaiz->derecha = nodo;

    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    nuevaRaiz->altura = std::max(altura(nuevaRaiz->izquierda), altura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->derecha;
    nodo->derecha = nuevaRaiz->izquierda;
    nuevaRaiz->izquierda = nodo;

    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    nuevaRaiz->altura = std::max(altura(nuevaRaiz->izquierda), altura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::balancear(NodoAVL* nodo) {
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;

    int balance = balanceFactor(nodo);

    if (balance > 1) {
        if (balanceFactor(nodo->izquierda) < 0) {
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
        }
        return rotarDerecha(nodo);
    } else if (balance < -1) {
        if (balanceFactor(nodo->derecha) > 0) {
            nodo->derecha = rotarDerecha(nodo->derecha);
        }
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::imprimirRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return;
    }

    imprimirRecursivo(nodo->izquierda);
    nodo->campos->imprimir(); // Imprimir la lista de campos en lugar de un solo campo
    imprimirRecursivo(nodo->derecha);
}

void ArbolAVL::imprimir() {
    imprimirRecursivo(raiz);
}