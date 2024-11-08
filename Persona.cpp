#include "Persona.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>




// Constructor por defecto
Persona::Persona() : nombre("") {}


Persona::Persona(const std::vector<std::string>& columnas, const std::vector<std::string>& valores){
    for (int i = columnas.size()-1; i>=0 ;i--) {
        hashmap[columnas[i]]=valores[i];
    }
    setCriterio(valores[0]);

}
    // Constructor
std::unordered_map<std::string,std::string> Persona::getValores(){
    return hashmap;
   }

void Persona::setValores(std::map<std::string, std::string> asignaciones){
    for (const auto& asignacion : asignaciones) {
        hashmap[asignacion.first] = asignacion.second;                   
    }
}


// Método para obtener el nombre
std::string Persona::getCriterio() const {
    return nombre;
}

// Método para establecer el nombre
void Persona::setCriterio(std::string n) {
    nombre = n;
}

// Método para mostrar los datos de la persona
void Persona::mostrarDatos() const {
        for (const auto& par : hashmap) {
        std::cout << par.first << ": "<<par.second<<" ";
    }
    //  std::cout <<std::endl;
}
