#include <iostream>
#include "ArbolAVL.h"


using namespace std;


int main() {


    ArbolAVL arbol;

    arbol.insertar(Contacto("Alice","100"));
    arbol.insertar(Contacto("Bob","50"));
    arbol.insertar(Contacto("Charlie","75"));
    arbol.insertar(Contacto("David","150"));
   // arbol.insertar(Contacto("Eve","5"));

    std::cout << "Arbol : ";
    arbol.imprimir();











    return 0;
}
