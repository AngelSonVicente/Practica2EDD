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




    // Creamos las tablas de campos para los grupos
    TablaHashCampo tablaCampoGrupo1;
    TablaHashCampo tablaCampoGrupo2;

    // Agregamos campos a las tablas de campos
    tablaCampoGrupo1.agregarCampo("Nombre");
    tablaCampoGrupo1.agregarCampo("Apellido");
    tablaCampoGrupo1.agregarCampo("Correo");

    tablaCampoGrupo2.agregarCampo("Edad");
    tablaCampoGrupo2.agregarCampo("Teléfono");

    // Creamos la tabla hash de grupos
    TablaHashGrupo tablaGrupo;

    // Agregamos los grupos a la tabla
    tablaGrupo.agregarGrupo("Grupo1", &tablaCampoGrupo1);
    tablaGrupo.agregarGrupo("Grupo2", &tablaCampoGrupo2);

    // Insertamos algunos datos en los árboles AVL asociados a los campos

    Contacto contacto1("Juan",  "7948732");
    Contacto contacto2("Maria", "78784");

    tablaCampoGrupo1.buscarCampo("Nombre")->insertar(contacto1); // Insertamos en el árbol AVL asociado al campo "Nombre" del grupo 1
    tablaCampoGrupo2.buscarCampo("Edad")->insertar(contacto2); // Insertamos en el árbol AVL asociado al campo "Edad" del grupo 2

    // Podemos imprimir los árboles AVL para verificar los datos ingresados
    std::cout << "Arbol AVL asociado al campo 'Nombre' del Grupo1:" << std::endl;
    tablaCampoGrupo1.buscarCampo("Nombre")->imprimir();

    std::cout << "Arbol AVL asociado al campo 'Edad' del Grupo2:" << std::endl;
    tablaCampoGrupo2.buscarCampo("Edad")->imprimir();








    return 0;
}
