#include "../include/System.hpp"
#include "../include/BinaryReader.hpp"
#include "../include/List.hpp"


void System::principal(){

    //List
    List<std::string>* e;


    //Deserializacion binaria
    IReader<std::string>* binaryReader = new BinaryReader<std::string>("../Docs/salarios.txt", new TransformadorBinarioString());

    e = binaryReader->read();

    std::cout << e->toString() << std::endl;
             


}