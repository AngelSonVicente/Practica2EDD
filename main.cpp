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
    TablaHashCampo tablaCampoGrupo2;

    // Agregamos campos a las tablas de campos
    tablaCampoGrupo1.agregarCampo("Nombre Grupo1");
    tablaCampoGrupo1.agregarCampo("Apellido Grupo1");
    tablaCampoGrupo1.agregarCampo("Correo Grupo1");

    tablaCampoGrupo2.agregarCampo("Edad Grupo2");
    tablaCampoGrupo2.agregarCampo("Telefono Grupo2");

    // Creamos la tabla hash de grupos
    TablaHashGrupo tablaGrupo;

    // Agregamos algunos grupos a la tabla
    tablaGrupo.agregarGrupo("Grupo1", &tablaCampoGrupo1);
    tablaGrupo.agregarGrupo("Grupo2", &tablaCampoGrupo2);

    // Buscamos un grupo en la tabla
    std::string nombreGrupoBuscado = "Grupo2";
    TablaHashCampo* tablaCampoEncontrada = tablaGrupo.obtenerTablaCampo(nombreGrupoBuscado);


    if (tablaCampoEncontrada != nullptr) {
        std::cout << "Grupo encontrado: " << nombreGrupoBuscado << std::endl;
        std::cout << "Campos del grupo:" << std::endl;
        for (int i = 0; i < 5; ++i) { // Suponiendo un máximo de 5 campos por grupo
            if (tablaCampoEncontrada->buscarCampo(tablaCampoEncontrada->tabla[i])) {
                std::cout << "- " << tablaCampoEncontrada->tabla[i] << std::endl;
            }
        }
    } else {
        std::cout << "Grupo no encontrado: " << nombreGrupoBuscado << std::endl;
    }









    return 0;
}
