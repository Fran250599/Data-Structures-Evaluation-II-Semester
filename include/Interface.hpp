
#pragma once
#include<iostream>
#include <sstream>
#include<string>//includes getline()
#include<stdlib.h>//includes system() 
#include<Windows.h>

struct Interface
{
	static void print(std::string);//prints on screen "output"
	static void printTab1(std::string); 
	static void printTab2(std::string);
	static std::string getString();//asks user a string
	static std::string* getDynamicString();
	static int getInt();//asks user an integer
	static int getInt(int, int);//overload, verifies the range of the number between a max and a min
	static float getFloat();//asks user a float 
	static void cleanTrash();//eliminates the problems of getting downed lines while retrieving any data from the keyboard after using getInt() or getFloat();
	static void printError(std::string);
	static void printWarning(std::string);
	static void printSuccess(std::string);
	static void cleanScreen();
	static std::string intToString(int);
	
};