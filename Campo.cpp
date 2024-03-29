#include "Campo.h"

Campo::Campo(const string& nombre, const string& valor) : nombre(nombre), valor(valor), siguiente(nullptr) {}

string Campo::obtenerNombre() const {
    return nombre;
}

string Campo::obtenerValor() const {
    return valor;
}

Campo* Campo::obtenerSiguiente() const {
    return siguiente;
}

void Campo::establecerSiguiente(Campo* siguienteCampo) {
    siguiente = siguienteCampo;
}
