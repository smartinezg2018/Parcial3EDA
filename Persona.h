#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>




class Persona {
private:
    int edad;
    std::string nombre;
    std::unordered_map<std::string,std::string> hashmap;
    

public:
    Persona();
    Persona(const std::vector<std::string>& columnas, const std::vector<std::string>& valores);
    // Constructor
    Persona(int e, std::string n);

    // Métodos para obtener la edad y el nombre
    std::unordered_map<std::string,std::string> getValores();
    void setValores(std::map<std::string, std::string> asignaciones);

    

    int getEdad() const;
    std::string getNombre() const;

    // Métodos para establecer la edad y el nombre
    void setEdad(int e);
    void setNombre(std::string n);

    // Método para mostrar los datos de la persona
    void mostrarDatos() const;
};

#endif // PERSONA_H
