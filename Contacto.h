//
// Created by angel on 21/03/24.
//

#ifndef PRACTICA2EDD_CONTACTO_H
#define PRACTICA2EDD_CONTACTO_H

#include <string>

using namespace std;

class Contacto {
private:
    std::string nombre;
    std::string telefono;

public:
    Contacto(const std::string& nombre, const std::string& telefono);
    const std::string& obtenerNombre() const;
    const std::string& obtenerTelefono() const;
};

#endif

//PRACTICA2EDD_CONTACTO_H
