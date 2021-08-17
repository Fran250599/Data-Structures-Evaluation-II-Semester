#pragma once
#include <iostream>
#include "List.hpp"
#include "IReader.hpp"
#include "BinaryTransformer.hpp"

class System{
private:
    List<Empleado*>* e = new List<Empleado*>(); 


public: 

    void principal();

};