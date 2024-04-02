#include <iostream>
#include <vector>
#include <regex>
#include "ArbolAVL.h"
#include "TablaHashCampo.h"
#include "TablaHashGrupo.h"
#include "ListaCampos.h"
#include "Graficar.h"

using namespace std;

TablaHashGrupo tablaGrupo;


void analizarComando(string& comando) {
    regex regexCrearGrupo("ADD\\s+NEW-GROUP\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regexCrearContacto("ADD\\s+CONTACT\\s+IN\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regexBuscarContacto("FIND\\s+CONTACT\\s+IN\\s+(\\w+)\\s+CONTACT-FIELD\\s+(\\w+)=([^;]+);");

    smatch matches;



    //CREAR GRUPOS
    if (regex_match(comando, matches, regexCrearGrupo)) {
        string nombreGrupo = matches[1];
        //campos de la creacion de grupos
        string campos = matches[2];

        cout<<"-----------------------------------------"<<endl;
        cout << "Instruccion: Creacion de grupo" << endl;
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Campos: " << campos << endl;

        //aca separamos los campos y los ingresaremos a una lista
        std::istringstream ss(campos);

        std::string campo;


//        TablaHashCampo tablaCampos ;

        // Extraemos cada palabra de la cadena
        int contador=0;
        while (ss >> campo) {
            // Eliminamos la coma al final del campo, si es que existe
            if (campo.back() == ',') {
                campo.pop_back();
            }
            if(contador%2==0){


            std::cout << "Campo: " << campo << std::endl;

           // tablaCampos.agregarCampo(campo);

            tablaGrupo.agregarGrupo(nombreGrupo,campo);
            //aca lo metemos a una lista
            }

            //agregamos el grupo a la tabla con su nombre y su tabla de campos

            contador++;
        }

      //  tablaCampos.eliminarTodosCampos();
        // CREAR CONTACTOS
    } else if (regex_match(comando, matches, regexCrearContacto)) {
        string nombreGrupo = matches[1];
        string datos = matches[2];
        cout << "-----------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Instruccion: Creacion de contacto" << endl;
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Datos del contacto: " << datos << endl;

        std::istringstream ss(datos);

        std::string campo;




    cout<<"Obteniendo tabla hash de cmapos del grupo: "<<nombreGrupo<<endl;
        TablaHashCampo* tablaCampoGrupo1=tablaGrupo.obtenerTablaCampo(nombreGrupo);

        tablaCampoGrupo1->obtenerNombreCampos()->imprimir();

        cout<<"Obteniendo nombre de los campos"<<endl;





            ListaCampos* listaCampos = tablaCampoGrupo1->obtenerNombreCampos();

            cout<<endl<<endl<<"LISTA DE CAMPOS";
            listaCampos->imprimir();







//        listaCampos->imprimir();


        cout<<"Creando lista de campos que se ingeraran"<<endl;
        ListaCampos* camposGrupo = new ListaCampos();

        int c=0;
        while (ss >> campo) {
            // Eliminamos la coma al final del campo, si es que existe
            if (campo.back() == ',') {
                campo.pop_back();
            }


                //aca lo metemos a una lista

                std::cout << "Campo: " << campo << std::endl;



            camposGrupo->agregarCampo(listaCampos->obtenerCampo(c)->obtenerNombre(),campo);


            c++;

        }


            tablaCampoGrupo1->buscarCampo(listaCampos->obtenerCampo(1)->obtenerNombre())->insertar(camposGrupo,1);


      //  tablaCampoGrupo1->buscarCampo(listaCampos->obtenerCampo(1)->obtenerNombre())->imprimir();




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


      //  tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->imprimir();

        //con esto se grafica el arbol


       cout<<"-------------------------------------------------------------"<<endl;

        cout<<endl<<endl<<  tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->generarDot(nombreGrupo);




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


    string comando = "ADD NEW-GROUP grupo2 FIELDS (nombre STRING, apellido "
                     "STRING, correo );";



    analizarComando(comando);
    string comandogrupo = "ADD NEW-GROUP mamalon2 FIELDS (xd STRING, ape STRING, cor );";

    analizarComando(comandogrupo);
    cout<<comando<<endl;



    string comando1 = "ADD CONTACT IN grupo2 FIELDS (Pedro, Alvarez, jlkdja@correo "
                      ");";

    cout<<endl<<comando1<<endl;
    analizarComando(comando1);

    string cg2 = "ADD CONTACT IN mamalon2 FIELDS (anaaaaa, xd, jlkdja@correo "
                      ");";
    analizarComando(cg2);

    string cg22 = "ADD CONTACT IN mamalon2 FIELDS (olaaa, xaaaaa, jlkdja@correo "
                      ");";
    analizarComando(cg22);

    string cg23 = "ADD CONTACT IN mamalon2 FIELDS (xdddddddddddd, xxxxxxxxx, jlkdja@correo "
                      ");";
    analizarComando(cg23);

string comando11 = "ADD CONTACT IN grupo2 FIELDS (wicho, Alvarez, jlkdja@correo "
                      ");";
string comando12 = "ADD CONTACT IN grupo2 FIELDS (jsjsjs, xxx, jlkdja@correo "
                      ");";
string comando13 = "ADD CONTACT IN grupo2 FIELDS (dkaslkdlsa, lkdjslakda, jlkdja@correo "
                      ");";
string comando14 = "ADD CONTACT IN grupo2 FIELDS (gurr, jjjjjjs, jlkdja@correo "
                      ");";
string comando15 = "ADD CONTACT IN grupo2 FIELDS (aaaaaaaaaaaa, mmckml, jlkdja@correo "
                      ");";


    string comando2 = "FIND CONTACT IN grupo2 CONTACT-FIELD apellido=alvarez;";
    string comandog22 = "FIND CONTACT IN mamalon2 CONTACT-FIELD apellidooo=alvarez;";





cout<<endl<<comando11<<endl;
    analizarComando(comando11);

    cout<<endl<<comando12<<endl;
    analizarComando(comando12);
 cout<<endl<<comando13<<endl;
    analizarComando(comando13);
 cout<<endl<<comando14<<endl;
    analizarComando(comando14);
cout<<endl<<comando15<<endl;
    analizarComando(comando15);



    cout<<endl<<comando2<<endl<<endl;
    analizarComando(comando2);
    analizarComando(comandog22);







//Graficar graficar;
// graficar.garficarEstructuraCompleta(tablaGrupo.obtenerNombreGrupos(),&tablaGrupo);



    return 0;
}
