//
// Created by angel on 21/03/24.
//


#include "Contacto.h"

Contacto::Contacto(const std::string& nombre, const std::string& telefono) : nombre(nombre), telefono(telefono) {}

const std::string& Contacto::obtenerNombre() const {
    return nombre;
}

const std::string& Contacto::obtenerTelefono() const {
    return telefono;
}