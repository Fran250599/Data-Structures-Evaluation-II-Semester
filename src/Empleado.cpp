#include "../include/Empleado.hpp"

Empleado::Empleado(){
 this->id = " ";
 this->firstLName = " ";
 this->secondLName = " ";
 this->name = " ";
 this->bornDate = " ";
 this->auxSalary = " ";
}

Empleado::Empleado(string _id, string _firstLName, string _secondLName, string _name, string _bornDate, string _auxSalary){
    this->id = _id;
    this->firstLName = _firstLName;
    this->secondLName = _secondLName;
    this->name = _name;
    this->bornDate = _bornDate;
    this->auxSalary = _auxSalary;
    this->salary = std::stoi(auxSalary);
}

int Empleado::salarioNeto(){

    if(this->salary < 950000){
        

        this->salary = this->salary * 0.09;
        return salary;

    }
}
