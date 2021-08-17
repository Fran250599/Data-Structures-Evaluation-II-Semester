#include <iostream>
#include <sstream>
#include "../include/List.hpp"
#include "../include/Empleado.hpp"

int main(){

    List<Empleado*>* hola;

    hola->insert(new Empleado);
    

    

    return 0;
}