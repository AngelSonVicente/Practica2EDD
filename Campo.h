//
// Created by MSI on 27/03/2024.
//

#ifndef PRACTICA2EDD_CAMPO_H
#define PRACTICA2EDD_CAMPO_H

#include <string>

using namespace std;

class Campo {
private:
    string nombre;
    string valor;
    Campo* siguiente;

public:
    Campo(const string& nombre, const string& valor);
    string obtenerNombre() const;
    string obtenerValor() const;
    Campo* obtenerSiguiente() const;
    void establecerSiguiente(Campo* siguienteCampo);

};


#endif //PRACTICA2EDD_CAMPO_H
