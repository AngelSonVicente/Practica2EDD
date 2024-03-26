#include <iostream>
#include "ArbolAVL.h"
#include "TablaHashCampo.h"
#include "TablaHashGrupo.h"


using namespace std;


int main() {

/*
    ArbolAVL arbol;

    arbol.insertar(Contacto("Alice","100"));
    arbol.insertar(Contacto("Bob","50"));
    arbol.insertar(Contacto("Charlie","75"));
    arbol.insertar(Contacto("David","150"));


    cout << "Arbol : ";
    arbol.imprimir();
*/

/*
    TablaHashCampo tablaCampo1;
    TablaHashCampo tablaCampo2;

    // Creamos la tabla hash de grupos
    TablaHashGrupo tablaGrupo;

    // Agregamos algunos grupos a la tabla
    tablaGrupo.agregarGrupo("dalskjdlkd", &tablaCampo1);
    tablaGrupo.agregarGrupo("Grupo2", &tablaCampo2);


    string nombreGrupoBuscado = "Grupo1";
    TablaHashCampo* tablaCampoEncontrada = tablaGrupo.obtenerTablaCampo(nombreGrupoBuscado);


    if (tablaCampoEncontrada != nullptr) {
        std::cout << "Grupo encontrado: " << nombreGrupoBuscado << std::endl;
    } else {
        std::cout << "Grupo no encontrado: " << nombreGrupoBuscado << std::endl;
    }
*/



    TablaHashCampo tablaCampoGrupo1;
    tablaCampoGrupo1.agregarCampo("Nombre");
    tablaCampoGrupo1.agregarCampo("Apellido");
    tablaCampoGrupo1.agregarCampo("Correo");

    // Creamos la tabla hash de campos para el grupo 2
    TablaHashCampo tablaCampoGrupo2;
    tablaCampoGrupo2.agregarCampo("Edad");
    tablaCampoGrupo2.agregarCampo("Teléfono");

    // Creamos la tabla hash de grupos
    TablaHashGrupo tablaGrupo;

    // Agregamos los grupos a la tabla
    tablaGrupo.agregarGrupo("Grupo1", &tablaCampoGrupo1);
    tablaGrupo.agregarGrupo("Grupo2", &tablaCampoGrupo2);

    // Buscamos un campo en el grupo 1
    std::string nombreCampoBuscado = "Nombre";
    std::string* campoEncontrado = tablaGrupo.obtenerTablaCampo("Grupo1")->buscarCampo(nombreCampoBuscado);

    // Verificamos si se encontró el campo y mostramos el resultado
    if (campoEncontrado != nullptr) {
        std::cout << "Campo encontrado en Grupo1: " << *campoEncontrado << std::endl;
    } else {
        std::cout << "Campo no encontrado en Grupo1: " << nombreCampoBuscado << std::endl;
    }

    // Buscamos un campo en el grupo 2
    nombreCampoBuscado = "Edad";
    campoEncontrado = tablaGrupo.obtenerTablaCampo("Grupo2")->buscarCampo(nombreCampoBuscado);

    // Verificamos si se encontró el campo y mostramos el resultado
    if (campoEncontrado != nullptr) {
        std::cout << "Campo encontrado en Grupo2: " << *campoEncontrado << std::endl;
    } else {
        std::cout << "Campo no encontrado en Grupo2: " << nombreCampoBuscado << std::endl;
    }








    return 0;
}
