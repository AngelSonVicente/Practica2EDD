#include <iostream>
#include <vector>
#include <regex>
#include "ArbolAVL.h"
#include "TablaHashCampo.h"
#include "TablaHashGrupo.h"
#include "ListaCampos.h"

using namespace std;


// Función para analizar el comando ingresado
void analizarComando(const std::string& comando) {
    regex regexCrearGrupo("ADD\\s+NEW-GROUP\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regexCrearContacto("ADD\\s+CONTACT\\s+IN\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regexBuscarContacto("FIND\\s+CONTACT\\s+IN\\s+(\\w+)\\s+CONTACT-FIELD\\s+(\\w+)=([^;]+);");

    smatch matches;

    if (regex_match(comando, matches, regexCrearGrupo)) {
        string nombreGrupo = matches[1];
        string campos = matches[2];
        cout << "Instruccion: Creacion de grupo" << endl;
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Campos: " << campos << endl;

        //  logica para guardar los campos en una Lista
    } else if (std::regex_match(comando, matches, regexCrearContacto)) {
        string nombreGrupo = matches[1];
        string datos = matches[2];
        cout << "Instruccion: Creacion de contacto" << endl;
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Datos del contacto: " << datos << endl;

        //  logica para guardar los datos en una Lista
    } else if (std::regex_match(comando, matches, regexBuscarContacto)) {
        string nombreGrupo = matches[1];
        string campo = matches[2];
        string dato = matches[3];
        cout << "Instruccion: Busqueda de contacto" << endl;
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Campo: " << campo << endl;
        cout << "Dato a buscar: " << dato << endl;

        // logica para realizar la busqueda
    } else {
        cout << "Comando no reconocido" << endl;
    }
}





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


    //--------------------------PRUEBA CON CONTACTOS----------
    /*
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
*/





   /*
    ListaCampos listaCampos;


    listaCampos.agregarCampo("Nombre", "Juan");
    listaCampos.agregarCampo("Apellido", "Perez");
    listaCampos.agregarCampo("Edad", "30");


    std::cout << "Lista de Campos:" << std::endl;
    listaCampos.imprimir();
*/


/*
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
    ListaCampos* camposGrupo1 = new ListaCampos();
    camposGrupo1->agregarCampo("Nombre", "Juan");
    camposGrupo1->agregarCampo("Apellido", "Perez");
    camposGrupo1->agregarCampo("Correo", "juan.perez@example.com");
ListaCampos* campos2Grupo1 = new ListaCampos();
    campos2Grupo1->agregarCampo("Nombre", "Auan");
    campos2Grupo1->agregarCampo("Apellido", "Aerez");
    campos2Grupo1->agregarCampo("Correo", "Auan.perez@example.com");

    ListaCampos* camposGrupo2 = new ListaCampos();
    camposGrupo2->agregarCampo("Edad", "25");
    camposGrupo2->agregarCampo("Telefono", "123456789");

    tablaCampoGrupo1.buscarCampo("Nombre")->insertar(camposGrupo1,0); // Insertamos en el árbol AVL asociado al campo "Nombre" del grupo 1
    tablaCampoGrupo1.buscarCampo("Apellido")->insertar(campos2Grupo1,1); // Insertamos en el árbol AVL asociado al campo "Nombre" del grupo 1
    tablaCampoGrupo1.buscarCampo("Apellido")->insertar(camposGrupo1,1); // Insertamos en el árbol AVL asociado al campo "Nombre" del grupo 1
    tablaCampoGrupo1.buscarCampo("Correo")->insertar(camposGrupo1,2); // Insertamos en el árbol AVL asociado al campo "Nombre" del grupo 1


    tablaCampoGrupo2.buscarCampo("Edad")->insertar(camposGrupo2,1); // Insertamos en el árbol AVL asociado al campo "Edad" del grupo 2

// Podemos imprimir los árboles AVL para verificar los datos ingresados
    std::cout << "Arbol AVL asociado al campo 'Apellido' del Grupo1:" << std::endl;
    //tablaCampoGrupo1.buscarCampo("Nombre")->imprimir();
    tablaCampoGrupo1.buscarCampo("Apellido")->imprimir();

*/


    string comando = "FIND CONTACT IN clientes CONTACT-FIELD apellido=alvarez;";

    // Analizar el comando
    analizarComando(comando);










    return 0;
}
