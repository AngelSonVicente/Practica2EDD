//
// Created by MSI on 31/03/2024.
//

#include "Graficar.h"
#include <iostream>
#include <fstream>
#include <string>


void Graficar::generarImagen(const std::string& contenidoDot) {

    // Paso 1: Crear un archivo .dot
    std::ofstream archivoDot("grafo.dot");
    if (!archivoDot) {
        std::cerr << "Error al abrir el archivo grafo.dot" << std::endl;
        return;
    }
    archivoDot << contenidoDot;
    archivoDot.close();

    // Paso 2: Llamar a Graphviz para generar la imagen
    std::string comando = "dot -Tpng grafo.dot -o grafo.png";
    int resultado = std::system(comando.c_str());
    if (resultado != 0) {
        std::cerr << "Error al ejecutar Graphviz para generar la imagen" << std::endl;
        return;
    }



    // Abrir la imagen
   // std::system("start grafo.png");  // Para sistemas Windows
     std::system("xdg-open grafo.png");  // Para sistemas Linux



}