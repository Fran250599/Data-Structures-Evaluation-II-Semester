#include "../include/Empleado.hpp"

Empleado::Empleado(){
 this->id = " ";
 this->firstLName = " ";
 this->secondLName = " ";
 this->name = " ";
 this->bornDate = " ";
 this->grossSalary = " ";
}

Empleado::Empleado(string _id, string _firstLName, string _secondLName, string _name, string _bornDate, string _grossSalary){
    this->id = _id;
    this->firstLName = _firstLName;
    this->secondLName = _secondLName;
    this->name = _name;
    this->bornDate = _bornDate;
    this->grossSalary = _grossSalary;
    this->salary = std::stoi(grossSalary);
}

int Empleado::salaryDeduction(){
    int salary1;
    int salary2;

    if(this->salary < 950000){
       salary1 = this->salary * 0.09; 
        
        return salary1;
    }
    else{
        salary1 = 950000;
        salary2 = this->salary - 950000;
        
        salary1 = salary1 * 0.09;
        salary2 = salary2 * 0.05;

        return salary1 + salary2;
    }
}

int Empleado::netSalary(){
    return salary - Empleado::salaryDeduction();
}
