//
// Created by angel on 22/03/24.
//

#include <string>
#include <iostream>
#include "TablaHashCampo.h"
#include "ArbolAVL.h"

using namespace std;

TablaHashCampo::TablaHashCampo() {
    for (int i = 0; i < TAMANO_TABLA; ++i) {
        tabla[i] = new ArbolAVL(); // Inicializamos cada posición con un puntero nulo
    }
}

int TablaHashCampo::funcionHash(const std::string& clave) {
    int suma = 0;
    for (size_t i = 0; i < clave.length(); ++i) {
        suma += clave[i] * (i + 1);
    }
    return suma % (TAMANO_TABLA-1);
}

ListaCampos* nombreCamposs = new ListaCampos(); //SI JALA

void TablaHashCampo::agregarCampo(const std::string& nombreCampo) {


    int indice = funcionHash(nombreCampo);

    nombreCamposs->agregarCampo(nombreCampo, "");

    Campos.agregar(nombreCampo);



    //tabla[indice] = new ArbolAVL(); // Creamos un nuevo arbol AVL para este campo


    //nombreCamposs->imprimir();

}

ArbolAVL* TablaHashCampo::buscarCampo(const std::string& nombreCampo) {
    int indice = funcionHash(nombreCampo);
   // cout<<"INIDICE DEL ARBOL AL QUE SE INGRESO:  "<<indice<<"nombreCAmpo:  " <<nombreCampo<<endl;
    return tabla[indice]; // Retornamos el puntero al árbol AVL asociado a este campo
}

ListaCampos* TablaHashCampo::obtenerNombreCampos() {

    return nombreCamposs;
}

nombreCampos* TablaHashCampo::getCampos(){

return &Campos;
}

void TablaHashCampo::eliminarTodosCampos() {


    delete nombreCamposs;  // Eliminar la lista de nombres de campos
    nombreCamposs = new ListaCampos();  // Crear una nueva lista vacía
}
