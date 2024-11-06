#include "ArbolBPlus.h"
#include "Persona.h"
#include <string>
#include <unordered_map>
#include <string>




// Insertar persona en el árbol
void ArbolBPlus::insertarArbol(Persona persona) {
    if (!raiz) {
        raiz = new NodoBMas(true);
        raiz->llaves.push_back(persona);
    } else {
        if (raiz->llaves.size() == (size_t)maxLlaves) {
            NodoBMas* nuevaRaiz = new NodoBMas(false);
            nuevaRaiz->hijos.push_back(raiz);
            NodoBMas* hijo = dividirHijo(nuevaRaiz, 0);
            nuevaRaiz->hijos.push_back(hijo);
            raiz = nuevaRaiz;
        }
        insertarEnNoLleno(raiz, persona);
    }
}

void ArbolBPlus::insertarEnNoLleno(NodoBMas* nodo, Persona persona) {
    if (nodo->esHoja) {
        nodo->llaves.push_back(persona);
        std::sort(nodo->llaves.begin(), nodo->llaves.end(), [](const Persona& a, const Persona& b) {
            return a.getCriterio() < b.getCriterio(); // Ordenar por edad
        });
    } else {
        size_t i = 0;


        while (i < nodo->llaves.size() && persona.getCriterio() > nodo->llaves[i].getCriterio()) {
            i++;
        }
        if (nodo->hijos[i]->llaves.size() == (size_t)maxLlaves) {
            NodoBMas* hijo = dividirHijo(nodo, i);
            nodo->hijos.insert(nodo->hijos.begin() + i + 1, hijo);
            if (persona.getCriterio() > nodo->llaves[i].getCriterio()) i++;
        }



        insertarEnNoLleno(nodo->hijos[i], persona);
    }
}

NodoBMas* ArbolBPlus::dividirHijo(NodoBMas* nodo, int indice) {
    NodoBMas* hijo = nodo->hijos[indice];
    NodoBMas* nuevoNodo = new NodoBMas(hijo->esHoja);

    int mitad = maxLlaves / 2;
    nodo->llaves.insert(nodo->llaves.begin() + indice, hijo->llaves[mitad]);

    nuevoNodo->llaves.assign(hijo->llaves.begin() + mitad + 1, hijo->llaves.end());
    hijo->llaves.resize(mitad);

    if (!hijo->esHoja) {
        nuevoNodo->hijos.assign(hijo->hijos.begin() + mitad + 1, hijo->hijos.end());
        hijo->hijos.resize(mitad + 1);
    }
    return nuevoNodo;
}


void ArbolBPlus::recorrer() {
    recorrerNodo(raiz);
    std::cout<<std::endl;
}

void ArbolBPlus::recorrerNodo(NodoBMas* nodo) {
    if (!nodo) return;
    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        if (!nodo->esHoja) recorrerNodo(nodo->hijos[i]);
        nodo->llaves[i].mostrarDatos();
        if (i<nodo->llaves.size()-1)std::cout<<", ";
        
    }
    if (!nodo->esHoja) recorrerNodo(nodo->hijos.back());
}

void ArbolBPlus::mostrarArbol() {
    mostrarArbolAux(raiz, "", true);
}

void ArbolBPlus::mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo) {
    if (!nodo) return;

    std::cout << prefix;
    std::cout << (esUltimo ? "└── " : "├── ");

    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        nodo->llaves[i].mostrarDatos();
        if (i != nodo->llaves.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    prefix += (esUltimo ? "    " : "|   ");
    for (size_t i = 0; i < nodo->hijos.size(); i++) {
        mostrarArbolAux(nodo->hijos[i], prefix, i == nodo->hijos.size() - 1);
    }
}








////////////////////////////////////////////////////////////////
// Implementación del método insertar
// Muestra en la consola el comando simulado de inserción con columnas y valores dados
void ArbolBPlus::insertar(const std::string& tabla, const std::vector<std::string>& columnas, const std::vector<std::string>& valores) {
    std::cout << "Ejecutando: INSERT INTO " << tabla << " (";
    // Itera y muestra cada columna, separadas por comas
    for (size_t i = 0; i < columnas.size(); ++i) {
        std::cout << columnas[i];
        if (i < columnas.size() - 1) std::cout << ", ";
    }
    std::cout << ") VALUES (";
    // Itera y muestra cada valor, separadas por comas
    for (size_t i = 0; i < valores.size(); ++i) {
        std::cout << valores[i];
        if (i < valores.size() - 1) std::cout << ", ";
    }
    std::cout << ")\n";

    // for(int i = 0; i<columnas.size();i++){
    //      std::cout << columnas[i] << " "<<std::endl;
    // }





    insertarArbol(Persona(columnas,valores));
    // mostrarArbol();
    // insertarArbol(Persona(12,"juan"));

    

}


// Implementación del método seleccionar
// Muestra en la consola el comando simulado de selección con columnas especificadas
void ArbolBPlus::seleccionar(const std::string& tabla, const std::vector<std::string>& columnas) {
    std::cout << "Ejecutando: SELECT ";
    // Itera y muestra cada columna seleccionada
    for (size_t i = 0; i < columnas.size(); ++i) {
        std::cout << columnas[i];
        if (i < columnas.size() - 1) std::cout << ", ";
    }
    std::cout << " FROM " << tabla << std::endl;

    buscarSeleccionados(columnas, raiz);
}

void ArbolBPlus::buscarSeleccionados(const std::vector<std::string>& columnas, NodoBMas* nodo) {
    if (!nodo) return;
    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        if (!nodo->esHoja) buscarSeleccionados(columnas,nodo->hijos[i]);
        
        for(int j = 0; j<columnas.size();j++){
            std::cout<<columnas[j]<<": "<<nodo->llaves[i].getValores()[columnas[j]]<<" ";
        } 
        if(i<nodo->llaves.size()-1)std::cout<<",";
    }
        std::cout<<std::endl;

    if (!nodo->esHoja) buscarSeleccionados(columnas,nodo->hijos.back());

}

// Implementación del método actualizar
// Muestra en la consola el comando simulado de actualización con asignaciones y condición
#include <string>
void ArbolBPlus::actualizar(const std::string& tabla, const std::map<std::string, std::string>& asignaciones, const std::string& condicion) {
    std::cout << "Ejecutando: UPDATE " << tabla << " SET ";
    size_t i = 0;
    // Itera y muestra cada asignación en el formato columna=valor
    for (const auto& asignacion : asignaciones) {
        std::cout << asignacion.first << " = " << asignacion.second;
        if (i < asignaciones.size() - 1) std::cout << ", ";
        ++i;
        
    }
    std::cout << " WHERE " << condicion << std::endl;
    updateRecursivo(raiz,asignaciones,condicion);
}




void ArbolBPlus::updateRecursivo(NodoBMas* nodo, const std::map<std::string, std::string>& asignaciones, const std::string& condicion) {
    if (!nodo) return;
    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        if (!nodo->esHoja) updateRecursivo(nodo,asignaciones,condicion);
        
        for (const auto& par : nodo->llaves[i].getValores()) {
            if(condicion==par.first+"="+par.second){
                nodo->llaves[i].setValores(asignaciones);
               
            }
        }
    }
    if (!nodo->esHoja) updateRecursivo(nodo,asignaciones,condicion);

}

// Implementación del método eliminar
// Muestra en la consola el comando simulado de eliminación con la condición dada
void ArbolBPlus::eliminar(const std::string& tabla, const std::string& condicion) {
    std::cout << "Ejecutando: DELETE FROM " << tabla << " WHERE " << condicion << std::endl;

}





