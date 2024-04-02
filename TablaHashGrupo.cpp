//
// Created by angel on 22/03/24.
//

#include <iostream>
#include "TablaHashGrupo.h"
#include "TablaHashCampo.h"
#include <fstream>


using namespace std;

TablaHashGrupo::TablaHashGrupo() {

}

int TablaHashGrupo::funcionHash(const std::string& clave) {
    int suma = 0;
    for (size_t i = 0; i < clave.length(); ++i) {
        suma += clave[i] * (i + 1);
    }
   // cout<<"SUMA:  "<< suma;

    return suma % (  TAMANO_TABLA-1);
}

ListaCampos* nombreGrupos = new ListaCampos(); //SI JALA



void TablaHashGrupo::agregarGrupo(const std::string& nombreGrupo, const std::string& nombreCampo) {
    int indice = funcionHash(nombreGrupo);
    nombreGrupos->agregarCampo(nombreGrupo, "");
    cout << endl << endl << "SE INGRESO GRUPO: " << nombreGrupo << "   AL INDICE: " << indice << endl <<"campo que se ingreso "<<nombreCampo<< endl;




    cout << "lista de campos: " << endl;



    cout << endl;

//    tabla[indice] = TablaHashCampo(tablaCampo);  // Almacena una copia independiente de tablaCampo en la tabla de grupos

    tabla[indice].agregarCampo(nombreCampo);

}

ListaCampos* TablaHashGrupo::obtenerNombreGrupos() {

    return nombreGrupos;
}

TablaHashCampo* TablaHashGrupo::obtenerTablaCampo(const std::string& nombreGrupo) {


    int indice = funcionHash(nombreGrupo);
  //  cout<<"IDNDICE DE TABLA HASH CAMPO: "<<indice<<" NOMBRE GRUPO:" <<nombreGrupo<<endl<<endl<<endl;

    return &tabla[indice];
}

