#include <iostream>
#include "ListaCampos.h"

ListaCampos::ListaCampos() : cabeza(nullptr) {}

ListaCampos::~ListaCampos() {
    while (cabeza) {
        Campo* temp = cabeza;
        cabeza = cabeza->obtenerSiguiente();
        delete temp;
    }
}

Campo* ListaCampos::obtenerCampo(int indice) const {
    Campo* actual = cabeza;
    int contador = 0;
    while (actual && contador < indice) {
        actual = actual->obtenerSiguiente();
        contador++;
    }
    return actual;
}

void ListaCampos::agregarCampo(const std::string& nombre, const std::string& valor) {
    Campo* nuevoCampo = new Campo(nombre, valor);
    if (!cabeza) {
        cabeza = nuevoCampo;
    } else {
        Campo* actual = cabeza;
        while (actual->obtenerSiguiente()) {
            actual = actual->obtenerSiguiente();
        }

        actual->establecerSiguiente(nuevoCampo);
    }
}
int ListaCampos::obtenerTamanio() const {
    int contador = 0;
    Campo* actual = cabeza;
    while (actual) {
        contador++;
        actual = actual->obtenerSiguiente();
    }
    return contador;
}
void ListaCampos::imprimir() const {
    Campo *actual = cabeza;
    while (actual) {
        cout  << actual->obtenerNombre() << " : " << actual->obtenerValor()<<"  " ;
        actual = actual->obtenerSiguiente();
    }
    cout<<endl<<endl;
}

std::string ListaCampos::contactoToString(int indice) const {
    Campo* contacto = obtenerCampo(indice);
    if (!contacto) {
        return "Índice de contacto fuera de rango.";
    }

    std::string contactoStr;
    contactoStr += " " + contacto->obtenerNombre() + ": ";
    contactoStr += " " + contacto->obtenerValor() + "\n";

    return contactoStr;
}
