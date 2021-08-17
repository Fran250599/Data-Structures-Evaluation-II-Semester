#pragma once
#include <iostream>
#include <fstream>
#include "IReader.hpp"
#include "BinaryTransformer.hpp"

template<class T>
class BinaryReader : public IReader<T>
{
private:
	std::fstream input;
	BinaryTransformer<T>* binaryT;

public:
	BinaryReader(std::string path, BinaryTransformer<T>* binaryT){
		this->binaryT = binaryT;
		this->input.open(path, std::ios::in | std::ios::binary);
		if (!input.good()) {
			throw invalid_argument("Error: No se pudo leer el archivo:  " + path);
		}
	}

	List<T>* read() override
	{
		List<T>* objetos = new List<T>();
		while (this->input.peek() != EOF)
		{
			objetos->insert(this->binaryT->deserialize(this->input));
		}
		return objetos;
	}

	~BinaryReader()
	{
		delete this->binaryT;
	}
};
