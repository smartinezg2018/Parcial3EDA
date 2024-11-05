#ifndef ARBOL_BPLUS_H
#define ARBOL_BPLUS_H

#include <string>    // Biblioteca para manejar cadenas de texto (std::string)
#include <vector>    // Biblioteca para manejar listas de elementos (std::vector)
#include <map>       // Biblioteca para manejar pares clave-valor (std::map)
#include <iostream>  // Biblioteca para operaciones de entrada y salida (std::cout)
#include <string>
#include <iostream>
#include <algorithm>
#include "Persona.h"

class NodoBMas {
public:
    bool esHoja;
    std::vector<Persona> llaves;
    std::vector<NodoBMas*> hijos;

    // Constructor del nodo, define si es hoja o no
    NodoBMas(bool hoja) : esHoja(hoja) {}
};

// Clase ArbolBPlus simula un árbol B+ con métodos básicos para las operaciones de SQL.
class ArbolBPlus {
    private:
    NodoBMas* raiz = nullptr;
    int maxLlaves;

    // Función auxiliar para insertar en un nodo no lleno
    void insertarEnNoLleno(NodoBMas* nodo, Persona persona);

    // Función auxiliar para dividir un hijo de un nodo
    NodoBMas* dividirHijo(NodoBMas* nodo, int indice);

    // Función auxiliar para recorrer el árbol




public:

 
    // Función para recorrer y mostrar el árbol en orden
    void recorrer();
    void recorrerNodo(NodoBMas* nodo);    // Función auxiliar para mostrar el árbol de forma estructurada    void mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo);

    ~ArbolBPlus() { limpiar(); }  // Llama a limpiar en el destructor

    void limpiar();  // Declaración de función para limpiar todo el árbol
    void limpiarNodo(NodoBMas* nodo);  
 
    // Constructor de ArbolBMas con el número máximo de llaves por nodo
    ArbolBPlus(int maxLlaves) : maxLlaves(maxLlaves) {}
    ArbolBPlus() : maxLlaves(3) {} 

    // Función para insertar una persona en el árbol
    void insertarArbol(Persona persona);

    // Función para buscar una persona por edad en el árbol
    void buscar(int edad);


    // Función para mostrar el árbol de forma estructurada
    void mostrarArbol();


    void updateRecursivo(NodoBMas* nodo, const std::map<std::string, std::string>& asignaciones, const std::string& condicion);




    // Método para simular la inserción en el árbol B+
    // Recibe el nombre de la tabla, una lista de columnas y una lista de valores
    void insertar(const std::string& tabla, const std::vector<std::string>& columnas, const std::vector<std::string>& valores);

    // Método para simular la selección de datos en el árbol B+
    // Recibe el nombre de la tabla y una lista de columnas
    void seleccionar(const std::string& tabla, const std::vector<std::string>& columnas);

    // Método para simular la actualización de datos en el árbol B+
    // Recibe el nombre de la tabla, un mapa de asignaciones (columna=valor), y una condición
    void actualizar(const std::string& tabla, const std::map<std::string, std::string>& asignaciones, const std::string& condicion);

    // Método para simular la eliminación de datos en el árbol B+
    // Recibe el nombre de la tabla y una condición para eliminar filas que la cumplan
    void eliminar(const std::string& tabla, const std::string& condicion);


    void buscarSeleccionados(const std::vector<std::string>& columnas, NodoBMas* nodo);

    void mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo);


    
    
};

#endif



