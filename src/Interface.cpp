#include "../include/Interface.hpp"

void Interface::print(std::string chain)
{
	std::cout << chain << '\n';
}
void Interface::printTab1(std::string chain){
	std::cout << chain << "		";
}
void Interface::printTab2(std::string chain){
	std::cout << chain << "			";
}

std::string Interface::getString()
{
	std::string chain;
	getline(std::cin, chain);
	return chain;
}

std::string* Interface::getDynamicString()
{
	std::string* chain = new std::string();
	getline(std::cin, *chain);
	return chain;
}

int Interface::getInt()
{
	int value;
	try {
		std::cin >> value;
		if (std::cin.fail()) {
			Interface::cleanTrash();
			throw - 1;
		}
		return value;
	}
	catch (int) {
		printError("Exception caught: Non integer data");
		system("PAUSE");
		return value = 0;
	}
}

float Interface::getFloat()
{
	float value;
	std::cin >> value;
	if (std::cin.fail()) {
		do {
			Interface::cleanTrash();
			Interface::printError("Exception caught: No floating data");
			std::cin >> value;
		} while (std::cin.fail());
	}
	return value;
}

void Interface::cleanTrash()
{
	std::cin.clear();
	std::cin.ignore(1024, '\n');
}

void Interface::printError(std::string word)
{
	//#define BLACK 0
	//#define BLUE 1
	//#define GREEN 2
	//#define CYAN 3
	//#define RED 4
	//#define MAGENTA 5
	//#define BROWN 6
	//#define LIGHTGREY 7
	//#define DARKGREY 8
	//#define LIGHTBLUE 9
	//#define LIGHTGREEN 10
	//#define LIGHTCYAN 11
	//#define LIGHTRED 12
	//#define LIGHTMAGENTA 13
	//#define YELLOW 14
	//#define WHITE 15
	//#define BLINK 128
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	Interface::print(word);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Interface::printWarning(std::string warning) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	Interface::print(warning);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Interface::printSuccess(std::string success)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	Interface::print(success);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Interface::cleanScreen()
{
	system("CLS");
}

int Interface::getInt(int min, int max) {// gets and int and verifies if it's between min and max
	int value = Interface::getInt();
	/*if (value == 0) { return 0; }
	else {
		try {
			if (value >= min && value <= max) {
				return value;
			}
			else { throw - 2; }
		}
		catch (int) { printError("Exception caught: Range exceeded"); system("PAUSE"); return 0; }
	}*/

	int difference = max - min;
	if (value >= min && value <= max) {
		valido:
		return value;
	}
	else {
		do {
			Interface::printError("Dato invalido.");
			std::cout << "Valor valido entre " << min << " y " << max <<std::endl;
			Interface::getInt();
		} while (value < min && value > max);
		goto valido;
	}
}

std::string Interface::intToString(int aux){
	std::stringstream ss;

	ss << aux; 
	

	return ss.str();
}


