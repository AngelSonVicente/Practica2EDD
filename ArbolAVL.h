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

    string generarDotEstructuraCompleta(const string &nombreArbol, stringstream &ss);



    void
    generarDotRecursivoCompleto(stringstream &ss, NodoAVL *nodo, const string &nombreRaiz, const string &nombreGrupo);

    void exportarContactos(const string &Directorio);

    void exportarContactos(NodoAVL *nodo, const string &Directorio);

    int cantidadContactos();

    int cantidadNodosRecursivo(NodoAVL *nodo);

    void buscarCamposRecursivo(NodoAVL *nodo, const string &campo, const string &valor);

    void buscarCampos(const string &campo, const string &valor);
};

#endif

//PRACTICA2EDD_ARBOLAVL_H
