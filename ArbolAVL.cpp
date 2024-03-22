#include "ArbolAVL.h"
#include <iostream>


NodoAVL::NodoAVL(const Contacto& c) : contacto(c), izquierda(nullptr), derecha(nullptr), altura(1) {}

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

NodoAVL* ArbolAVL::insertarRecursivo(NodoAVL* nodo, const Contacto& contacto) {
    if (nodo == nullptr) {
        return new NodoAVL(contacto);
    }

    if (contacto.obtenerTelefono() < nodo->contacto.obtenerTelefono()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, contacto);
    } else {
        nodo->derecha = insertarRecursivo(nodo->derecha, contacto);
    }

    return balancear(nodo);
}

void ArbolAVL::insertar(const Contacto& contacto) {
    raiz = insertarRecursivo(raiz, contacto);
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
    std::cout << nodo->contacto.obtenerNombre() << " (" << nodo->contacto.obtenerTelefono() << ") ";
    imprimirRecursivo(nodo->derecha);
}

void ArbolAVL::imprimir() {
    imprimirRecursivo(raiz);
    std::cout << std::endl;
}
