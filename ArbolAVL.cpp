#include "ArbolAVL.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include "string"




NodoAVL::NodoAVL(ListaCampos* lc) : campos(lc), izquierda(nullptr), derecha(nullptr), altura(1) {}

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

NodoAVL* ArbolAVL::insertarRecursivo(NodoAVL* nodo, ListaCampos* campos, int indice) {
    if (nodo == nullptr) {
        return new NodoAVL(campos);
    }

    if (campos->obtenerCampo(indice)->obtenerNombre() < nodo->campos->obtenerCampo(indice)->obtenerNombre()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, campos, indice);
    } else {
        nodo->derecha = insertarRecursivo(nodo->derecha, campos, indice);
    }

    return balancear(nodo);
}

void ArbolAVL::insertar(ListaCampos* campos, int indice) {
    raiz = insertarRecursivo(raiz, campos, indice);
}

int ArbolAVL::altura(NodoAVL* nodo) {
    return nodo ? nodo->altura : 0;
}

int ArbolAVL::balanceFactor(NodoAVL* nodo) {
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->izquierda;
    nodo->izquierda = nuevaRaiz->derecha;
    nuevaRaiz->derecha = nodo;

    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    nuevaRaiz->altura = std::max(altura(nuevaRaiz->izquierda), altura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->derecha;
    nodo->derecha = nuevaRaiz->izquierda;
    nuevaRaiz->izquierda = nodo;

    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    nuevaRaiz->altura = std::max(altura(nuevaRaiz->izquierda), altura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::balancear(NodoAVL* nodo) {
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;

    int balance = balanceFactor(nodo);

    if (balance > 1) {
        if (balanceFactor(nodo->izquierda) < 0) {
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
        }
        return rotarDerecha(nodo);
    } else if (balance < -1) {
        if (balanceFactor(nodo->derecha) > 0) {
            nodo->derecha = rotarDerecha(nodo->derecha);
        }
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::imprimirRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return;
    }

    imprimirRecursivo(nodo->izquierda);
    nodo->campos->imprimir(); // Imprimir la lista de campos en lugar de un solo campo
    imprimirRecursivo(nodo->derecha);
}

void ArbolAVL::imprimir() {
    imprimirRecursivo(raiz);
}




void ArbolAVL:: generarDotRecursivo(std::stringstream& ss, NodoAVL* nodo, const std::string& nombreRaiz) {
    if (nodo == nullptr) {
        return;
    }

    // Generar un identificador único para el nodo
    std::string nodoId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo));

    // Agregar el nodo al archivo .dot
    ss << nodoId << " [label=\"" << nodo->campos->obtenerCampo(0)->obtenerValor() << "\"];" << std::endl;

    if (nodo->izquierda != nullptr) {
        std::string izquierdaId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo->izquierda));
        ss << nodoId << " -> " << izquierdaId << ";" << std::endl;
        generarDotRecursivo(ss, nodo->izquierda, nombreRaiz);
    }

    if (nodo->derecha != nullptr) {
        std::string derechaId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo->derecha));
        ss << nodoId << " -> " << derechaId << ";" << std::endl;
        generarDotRecursivo(ss, nodo->derecha, nombreRaiz);
    }

    // Conectar el nodo raíz con el primer nodo del árbol
    if (nodoId == "N" + std::to_string(reinterpret_cast<uintptr_t>(raiz))) {
        ss << nombreRaiz << " -> " << nodoId << ";" << std::endl;
    }
}

std::string ArbolAVL::generarDot(const std::string& nombreArbol) {
    std::stringstream ss;
    ss << "digraph " << nombreArbol << " {" << std::endl;
    // Agregar el nodo raíz con el nombre del árbol y estilo rectángulo
    ss << "raiz [label=\"" << nombreArbol << "\", shape=box];" << std::endl;
    generarDotRecursivo(ss, raiz, "raiz");
    ss << "}" << std::endl;
    return ss.str();
}


string ArbolAVL::generarDotEstructuraCompleta(const std::string& nombreArbol, stringstream& ss) {


    // Agregar el nodo raíz con el nombre del árbol y estilo rectángulo

    generarDotRecursivoCompleto(ss, raiz, "raiz",nombreArbol);



    return ss.str();
}



void ArbolAVL:: generarDotRecursivoCompleto(std::stringstream& ss, NodoAVL* nodo, const std::string& nombreRaiz,const std::string& nombreGrupo ) {
    if (nodo == nullptr) {
        return;
    }

    // Generar un identificador único para el nodo
    std::string nodoId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo));

    // Agregar el nodo al archivo .dot
    ss << nodoId << " [label=\"" << nodo->campos->obtenerCampo(0)->obtenerValor() << "\"];" << std::endl;

    if (nodo->izquierda != nullptr) {
        std::string izquierdaId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo->izquierda));
        ss << nodoId << " -> " << izquierdaId << ";" << std::endl;
        generarDotRecursivo(ss, nodo->izquierda, nombreRaiz);
    }

    if (nodo->derecha != nullptr) {
        std::string derechaId = "N" + std::to_string(reinterpret_cast<uintptr_t>(nodo->derecha));
        ss << nodoId << " -> " << derechaId << ";" << std::endl;
        generarDotRecursivo(ss, nodo->derecha, nombreRaiz);
    }

    // Conectar el nodo raíz con el primer nodo del árbol
    if (nodoId == "N" + std::to_string(reinterpret_cast<uintptr_t>(raiz))) {
        ss <<"tabla:" <<nombreGrupo << " -> " << nodoId << ";" << std::endl;
    }
}




void ArbolAVL::exportarContactos(NodoAVL* nodo, const std::string& Directorio) {
    if (nodo == nullptr) {
        return;
    }


    std::string nodoId = nodo->campos->obtenerCampo(0)->obtenerValor();


    std::string nombreArchivo = Directorio + "/" + nodoId + ".txt";
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
      //  std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
        return;
    }


    archivo << "Informacion del contacto:" << std::endl;
    for (int i = 0; i < nodo->campos->obtenerTamanio(); ++i) {
        archivo << nodo->campos->contactoToString(i) << std::endl;
    }
    archivo.close();


    exportarContactos(nodo->izquierda, Directorio);
    exportarContactos(nodo->derecha, Directorio);
}

void ArbolAVL::exportarContactos(const std::string& Directorio) {
    // Crear el directorio si no existe
    if (!std::filesystem::exists(Directorio)) {
        std::filesystem::create_directory(Directorio);
    }

    //metodo recursivo
    exportarContactos(raiz, Directorio);
}

int ArbolAVL::cantidadNodosRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int izquierda = cantidadNodosRecursivo(nodo->izquierda);

    int derecha = cantidadNodosRecursivo(nodo->derecha);

    return 1 + izquierda + derecha;
}

int ArbolAVL::cantidadContactos() {
    return cantidadNodosRecursivo(raiz);
}

void ArbolAVL::buscarCamposRecursivo(NodoAVL* nodo, const std::string& campo, const std::string& valor) {
    if (nodo == nullptr) {
        return;
    }

    buscarCamposRecursivo(nodo->izquierda, campo, valor);

    // Verificar si el campo coincide con el valor deseado
    for (int i = 0; i < nodo->campos->obtenerTamanio(); ++i) {
        if (nodo->campos->obtenerCampo(i)->obtenerNombre() == campo &&
            nodo->campos->obtenerCampo(i)->obtenerValor() == valor) {
            // Imprimir los campos del nodo que coinciden con el criterio
            std::cout << "Contacto encontrado:" << std::endl;
            nodo->campos->imprimir();
            break;  // Terminar la búsqueda en este nodo una vez encontrado el campo
        }
    }

    buscarCamposRecursivo(nodo->derecha, campo, valor);
}

void ArbolAVL::buscarCampos(const std::string& campo, const std::string& valor) {
    std::cout << "Buscando campos con el nombre '" << campo << "' y el valor '" << valor << "':" << std::endl;
    buscarCamposRecursivo(raiz, campo, valor);
}



