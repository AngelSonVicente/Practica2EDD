//
// Created by MSI on 31/03/2024.
//

#include "Graficar.h"
#include <iostream>
#include <fstream>
#include <string>


void Graficar::generarImagen(const std::string& contenidoDot) {

    std::ofstream archivoDot("grafo.dot");
    if (!archivoDot) {
        std::cerr << "Error al abrir el archivo grafo.dot" << std::endl;
        return;
    }
    archivoDot << contenidoDot;
    archivoDot.close();

  //  system("dot grafica.dot -o grafica.jpg -Tjpg -Grandkdir=TB && xdg-open grafica.jpg");




    // Abrir la imagen
   // std::system("start grafo.png");  // Para sistemas Windows
    // std::system("xdg-open grafo.png");  // Para sistemas Linux



}