//
// Created by angel on 2/04/24.
//

#include "nombreCampos.h"
#include "string"
#include "iostream"

using namespace std;

bool nombreCampos::estaVacia() const {
    return frente == nullptr;
}

void nombreCampos::agregar(const string& nombre) {
    Nodo* nuevoNodo = new Nodo(nombre);
    if (estaVacia()) {
        frente = nuevoNodo;
    } else {
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
}

void nombreCampos::imprimir() const {
    Nodo* temp = frente;
    cout << "Campos:" << endl;
    while (temp != nullptr) {
       cout<< temp->nombre<<endl;
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}


int nombreCampos::obtenerTamanio() const {
    int contador=0;
    Nodo* temp = frente;

    while (temp != nullptr) {

        contador++;
        temp = temp->siguiente;

    }

    return contador;
}

nombreCampos::Nodo* nombreCampos::obtenerCAmpo(int indice)  {


    Nodo* temp = frente;
    int contador = 0;
    while (contador < indice) {
        temp = temp->siguiente;
        contador++;

    }

    return temp;
}