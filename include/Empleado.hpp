#include <iostream>
#include <sstream>

using std::string;

class Empleado {

private:
    string id;
    string firstLName;
    string secondLName;
    string name;
    string bornDate;
    string grossSalary;
    int salary;
    
public:
    Empleado();
    Empleado(string, string,string, string,string, string);

    string getID() { return this->id; }
    string getFirstLName() { return this->firstLName; }
    string getSecondLName() { return this->secondLName; }
    string getName() { return this->name; }
    string getBornDate(){ return this->bornDate; }
    string getSalary(){ return this->grossSalary; }

    int salaryDeduction();
    int netSalary();
};