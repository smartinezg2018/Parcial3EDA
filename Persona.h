#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>




class Persona {
private:

    std::string nombre;
    std::unordered_map<std::string,std::string> hashmap;
    

public:
    Persona();
    Persona(const std::vector<std::string>& columnas, const std::vector<std::string>& valores);

    std::unordered_map<std::string,std::string> getValores();
    void setValores(std::map<std::string, std::string> asignaciones);

    std::string getCriterio() const;
    void setCriterio(std::string n);
    void mostrarDatos() const;
};

#endif
