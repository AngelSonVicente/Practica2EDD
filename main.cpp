#include <iostream>
#include <vector>
#include <regex>
#include "ArbolAVL.h"
#include "TablaHashCampo.h"
#include "TablaHashGrupo.h"
#include "ListaCampos.h"
#include "Graficar.h"
#include "set"
#include "Util.h"

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

//       tablaGrupo.obtenerTablaCampo(nombreGrupo)->index= tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerTamanio();

//        TablaHashCampo tablaCampos ;

        // Extraemos cada palabra de la cadena
        int contador=0;
        while (ss >> campo) {
            // Eliminamos la coma al final del campo, si es que existe
            if (campo.back() == ',') {
                campo.pop_back();
            }
            if(contador%2==0){


//            std::cout << "Campo: " << campo << std::endl;

           // tablaCampos.agregarCampo(campo);

            tablaGrupo.agregarGrupo(nombreGrupo,campo);
            //aca lo metemos a una lista
            }

            //agregamos el grupo a la tabla con su nombre y su tabla de campos

            contador++;
        }

        cout<<"GRUPO CREADO EXITOSAMENTE!"<<endl;

      //  tablaCampos.eliminarTodosCampos();
        // CREAR CONTACTOS
    } else if (regex_match(comando, matches, regexCrearContacto)) {
        string nombreGrupo = matches[1];
        string datos = matches[2];

        cout << "-----------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Instruccion: Creacion de contacto" << endl;

       /*
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Datos del contacto: " << datos << endl;
*/
        std::istringstream ss(datos);

        std::string campo;




    //cout<<"Obteniendo tabla hash de cmapos del grupo: "<<nombreGrupo<<endl;
        TablaHashCampo* tablaCampoGrupo1=tablaGrupo.obtenerTablaCampo(nombreGrupo);


        //tablaCampoGrupo1->obtenerNombreCampos()->imprimir();

       // cout<<"Obteniendo nombre de los campos"<<endl;





            ListaCampos* listaCampos = tablaCampoGrupo1->obtenerNombreCampos();

          //  cout<<endl<<endl<<"LISTA DE CAMPOS";
           // listaCampos->imprimir();







//        listaCampos->imprimir();


       // cout<<"Creando lista de campos que se ingeraran"<<endl;
        ListaCampos* camposGrupo = new ListaCampos();

        int c=0;
        while (ss >> campo) {
            // Eliminamos la coma al final del campo, si es que existe
            if (campo.back() == ',') {
                campo.pop_back();
            }


                //aca lo metemos a una lista

               // std::cout << "Campo: " << campo << std::endl;



            camposGrupo->agregarCampo(tablaGrupo.obtenerTablaCampo(nombreGrupo)->getCampos()->obtenerCAmpo(c)->nombre,campo);


            c++;

        }


        for (int i = 0; i < tablaGrupo.obtenerTablaCampo(nombreGrupo)->getCampos()->obtenerTamanio(); ++i) {

            tablaCampoGrupo1->buscarCampo(listaCampos->obtenerCampo(i)->obtenerNombre())->insertar(camposGrupo,i);
        }



//        tablaCampoGrupo1->buscarCampo(listaCampos->obtenerCampo(1)->obtenerNombre())->insertar(camposGrupo,1);



      //  tablaCampoGrupo1->buscarCampo(listaCampos->obtenerCampo(1)->obtenerNombre())->imprimir();





    cout<<"CONTACTO CREADO EXITOSAMENTE!"<<endl;

    } else if (std::regex_match(comando, matches, regexBuscarContacto)) {
        string nombreGrupo = matches[1];
        string campo = matches[2];
        string dato = matches[3];

        cout << "Instruccion: Busqueda de contacto" << endl;

        /*
        cout << "Nombre del grupo: " << nombreGrupo << endl;
        cout << "Campo: " << campo << endl;
        cout << "Dato a buscar: " << dato << endl;
*/


        // logica para realizar la busqueda


      //  tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->imprimir();

        //con esto se grafica el arbol


       cout<<"-------------------------------------------------------------"<<endl;

        // cout<<endl<<endl<<  tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->generarDot(nombreGrupo);


        tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->buscarCampos(campo,dato);


        cout<<"-------------------------------------------------------------"<<endl;



    } else {
        cout << "Comando no reconocido" << endl;
    }
}


void graficarArbol(string nombreGrupo){
    string campo = tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerCampo(1)->obtenerNombre();

    string contenido=tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->generarDot(nombreGrupo);


    Graficar graficar;
    graficar.generarImagen(contenido);


}

string graficarEstructura(){

    stringstream  ss;

            ss << "digraph PracticaEDD2" << " {" << std::endl;
            ss<<"  node [shape=record];"<<endl;
    ss<< "tabla [label=\"" ;

    set<string> gruposProcesados;

    ListaCampos* listaGrupos = tablaGrupo.obtenerNombreGrupos();
    for (int i = 0; i < listaGrupos->obtenerTamanio(); ++i) {
        string nombreGrupo = listaGrupos->obtenerCampo(i)->obtenerNombre();
        string campo = tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerCampo(1)->obtenerNombre();

        // Verificar si el grupo ya ha sido procesado
        if (gruposProcesados.find(nombreGrupo) == gruposProcesados.end()) {


           ss<<"|<"<<nombreGrupo<<">"<<" "<<nombreGrupo;





            // Agregar el nombre del grupo al conjunto de grupos procesados
            gruposProcesados.insert(nombreGrupo);
        }


    }

    ss<<"\"];"<<endl<<endl;




    //agregamos todos los arboles
    gruposProcesados.clear();
    ss<<"node [shape=oval];"<<endl;


    for (int i = 0; i < listaGrupos->obtenerTamanio(); ++i) {
        string nombreGrupo = listaGrupos->obtenerCampo(i)->obtenerNombre();
        string campo = tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerCampo(0)->obtenerNombre();

        // Verificar si el grupo ya ha sido procesado
        if (gruposProcesados.find(nombreGrupo) == gruposProcesados.end()) {






            //retorna un string que contiene el arbol
             tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->generarDotEstructuraCompleta(nombreGrupo,ss);

            // Agregar el nombre del grupo al conjunto de grupos procesados
            gruposProcesados.insert(nombreGrupo);
        }


    }





    ss<<endl<<endl<<"}";




   // cout<<ss.str();


    return ss.str();
}


void ExportarGrupo(){

     cout <<endl<<endl<<endl<<"EXPORTAR CONTACTOS"<<endl;
    cout<<"_________________________________________________________"<<endl;
    cout<<"_________________________________________________________"<<endl<<endl;


    cout <<"Lista de grupos: "<<endl<<endl;

    set<string> gruposProcesados;

    ListaCampos* listaGrupos = tablaGrupo.obtenerNombreGrupos();

    for (int i = 0; i < listaGrupos->obtenerTamanio(); ++i) {
        string nombreGrupo = listaGrupos->obtenerCampo(i)->obtenerNombre();
        string campo = tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerCampo(1)->obtenerNombre();

        // Verificar si el grupo ya ha sido procesado
        if (gruposProcesados.find(nombreGrupo) == gruposProcesados.end()) {


            cout<<nombreGrupo<<endl;



            // Agregar el nombre del grupo al conjunto de grupos procesados
            gruposProcesados.insert(nombreGrupo);
        }


    }


    string grupo="";
    cout<<endl<<"ingrese el nombre del grupo"<<endl;
    cin>>grupo;

    string campoBusqueda=tablaGrupo.obtenerTablaCampo(grupo)->obtenerNombreCampos()->obtenerCampo(1)->obtenerNombre();
    tablaGrupo.obtenerTablaCampo(grupo)->buscarCampo(campoBusqueda)->imprimir();

    Util util;

   string path= util.crearcarpeta(grupo);

   tablaGrupo.obtenerTablaCampo(grupo)->buscarCampo(campoBusqueda)->exportarContactos(path);




}

void Reportes(){


    cout<<".................................................................."<<endl;
    cout<<"cantidad de datos (campos) por grupo: "<<endl<<endl;


    set<string> gruposProcesados;

    ListaCampos* listaGrupos = tablaGrupo.obtenerNombreGrupos();


    for (int i = 0; i < listaGrupos->obtenerTamanio(); ++i) {
        string nombreGrupo = listaGrupos->obtenerCampo(i)->obtenerNombre();
        string campo = tablaGrupo.obtenerTablaCampo(nombreGrupo)->obtenerNombreCampos()->obtenerCampo(1)->obtenerNombre();

        // Verificar si el grupo ya ha sido procesado
        if (gruposProcesados.find(nombreGrupo) == gruposProcesados.end()) {




            cout<<"_________________________________________________________________________"<<endl;
            cout<<endl<<nombreGrupo<<endl<<endl<<"cantidad de datos:  "<< tablaGrupo.obtenerTablaCampo(nombreGrupo)->getCampos()->obtenerTamanio()<<endl;

            tablaGrupo.obtenerTablaCampo(nombreGrupo)->getCampos()->imprimir();
            string NombreCampo=tablaGrupo.obtenerTablaCampo(nombreGrupo)->getCampos()->obtenerCAmpo(1)->nombre;



            cout<<"cantidad de Contactos del grupo: "<<tablaGrupo.obtenerTablaCampo(nombreGrupo)->buscarCampo(campo)->cantidadContactos() <<endl;







            // Agregar el nombre del grupo al conjunto de grupos procesados
            gruposProcesados.insert(nombreGrupo);
        }



    }

    cout<<"--------------------------------------------------------------"<<endl;

    cout<<endl<<"cantidad de datos de todo el sistema:  "<<tablaGrupo.obtenerNombreGrupos()->obtenerTamanio()<<endl;

    cout<<endl<<"--------------------------------------------------------------"<<endl;






    gruposProcesados.clear();


}










int main() {




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

string comando11 = "ADD CONTACT IN grupo2 FIELDS (wicho, alvarez, jlkdja@correo "
                      ");";
string comando12 = "ADD CONTACT IN grupo2 FIELDS (jsjsjs, xxx, jlkdja@correo "
                      ");";
string comando13 = "ADD CONTACT IN grupo2 FIELDS (dkaslkdlsa, lkdjslakda, jlkdja@correo "
                      ");";
string comando14 = "ADD CONTACT IN grupo2 FIELDS (gurr, jjjjjjs, jlkdja@correo "
                      ");";
string comando15 = "ADD CONTACT IN grupo2 FIELDS (aaaaaaaaaaaa, alvarez, jlkdja@correo "
                      ");";


    string comando2 = "FIND CONTACT IN grupo2 CONTACT-FIELD nombre=gurr;";
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






    int opcion=-1;
    while (opcion!=0){


        cout<<"Ingrese la opcion que desea realizar "<<endl;
        cout<<" --------------------------Menu----------------"<<endl;
        cout<<"|  1:  Terminal                                |"<<endl;
        cout<<"|  2:  Reportes                                |"<<endl;
        cout<<"|  3:  Graficas                                |"<<endl;
        cout<<"|  4:  Exportacion de datos                    |"<<endl;
        cout<<"|  0:  SALIR                                   |"<<endl;
        cout<<"|______________________________________________|"<<endl;
        cin>>opcion;


        if(opcion==1){


            comando="";
            cout<<"Ingrese el comando: "<<endl;
            cin>>comando;

            analizarComando(comando);



        }else if (opcion==2){
            Reportes();



        } else if(opcion==3){
            int opcionestructura=0;

            cout<<"ingrese 1 para graficar una estructura, Ingrese 2 para graficar la estructura completa"<<endl;
            cin>>opcionestructura;


            if(opcionestructura==1){
                string nombreGrupo="";
                cout<<"Ingrese el nombre del grupo"<<endl;
                cin>>nombreGrupo;

                graficarArbol(nombreGrupo);

            }
            if(opcionestructura==2){

                cout<<"GRAFICAR ESTRUCTURA COMPLETA"<<endl;
                string contenido= graficarEstructura();

                Graficar graficar;
                graficar.generarImagen(contenido);



            }




        }else if(opcion==4){
            ExportarGrupo();


        }








    }





    return 0;
}
