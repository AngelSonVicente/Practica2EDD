//
// Created by angel on 2/04/24.
//

#include "string"
#include "Util.h"
#include <iostream>
#include <filesystem>  // Incluir la biblioteca <filesystem>

namespace fs = std::filesystem;
using namespace std;

string Util::crearcarpeta(const string& grupo ){
    std::string directorio = "/home/angel/EDD/Practica2EDD/Contactos";




    // Ruta completa de la carpeta a crear
    std::string rutaCarpeta = directorio + "/" + grupo;

    // Comprobar si el directorio existe
    if (!fs::exists(directorio)) {
     //   std::cerr << "El directorio especificado no existe." << std::endl;

    }

    // Crear la carpeta si no existe
    if (!fs::exists(rutaCarpeta)) {
        if (fs::create_directory(rutaCarpeta)) {
      //      std::cout << "Carpeta creada con éxito." << std::endl;
        } else {
        //    std::cerr << "Error al crear la carpeta." << std::endl;

        }
    } else {
    //    std::cout << "La carpeta ya existe." << std::endl;
    }

    // Crear la carpeta si no existe
    if (!fs::exists(rutaCarpeta)) {
        if (fs::create_directory(rutaCarpeta)) {
        //    std::cout << "Carpeta creada con éxito." << std::endl;
        } else {
         //   std::cerr << "Error al crear la carpeta." << std::endl;

        }
    } else {
    //    std::cout << "La carpeta ya existe." << std::endl;
    }



    return rutaCarpeta;
}