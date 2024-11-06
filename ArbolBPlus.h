#ifndef ARBOL_BPLUS_H
#define ARBOL_BPLUS_H

#include <string>    
#include <vector>   
#include <map>      
#include <iostream>  
#include <string>
#include <iostream>
#include <algorithm>
#include "Persona.h"

class NodoBMas {
public:

    bool esHoja;
    std::vector<Persona> llaves;
    std::vector<NodoBMas*> hijos;

    NodoBMas(bool hoja) : esHoja(hoja) {}
};


class ArbolBPlus {
    private:
    NodoBMas* raiz = nullptr;
    int maxLlaves;

    void insertarEnNoLleno(NodoBMas* nodo, Persona persona);

    NodoBMas* dividirHijo(NodoBMas* nodo, int indice);

public:
   

 
    ArbolBPlus(int maxLlaves) : maxLlaves(maxLlaves) {}

    ArbolBPlus() : maxLlaves(3) {} 


    void insertarArbol(Persona persona);

    void mostrarArbol();

    void mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo);


    void recorrer();

    void recorrerNodo(NodoBMas* nodo);  

    void insertar(const std::string& tabla, const std::vector<std::string>& columnas, const std::vector<std::string>& valores);

    void updateRecursivo(NodoBMas* nodo, const std::map<std::string, std::string>& asignaciones, const std::string& condicion);

    void seleccionar(const std::string& tabla, const std::vector<std::string>& columnas);
   
    void buscarSeleccionados(const std::vector<std::string>& columnas, NodoBMas* nodo);

    void actualizar(const std::string& tabla, const std::map<std::string, std::string>& asignaciones, const std::string& condicion);

    void eliminar(const std::string& tabla, const std::string& condicion);


    
    
};

#endif



