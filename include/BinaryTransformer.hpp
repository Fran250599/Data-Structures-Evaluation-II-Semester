#pragma once
#include<iostream>
#include"Empleado.hpp"
#include "List.hpp"

template<class T>
class BinaryTransformer
{
public:
	virtual void serialize(T elemento, std::ostream& out) = 0;
	virtual T deserialize(std::istream& in) = 0;
	virtual ~BinaryTransformer() = default;
};
class TransformadorBinarioString : public BinaryTransformer<string>
{
public:
	void serialize(string elemento, std::ostream& out) override
	{
		size_t largoString = elemento.length() + 1;
		out.write(reinterpret_cast<char*>(&largoString), sizeof(size_t));
		out.write(elemento.c_str(), (std::streamsize)largoString);
		if (!out.good())
			throw std::ios_base::failure("Error serializando string...");
	}

	string deserialize(std::istream& in) override
	{
		string nuevoString;
		size_t largoString = 0;

		in.read(reinterpret_cast<char*>(&largoString), sizeof(size_t));

		char* caracteres = new char[largoString];
		in.read(caracteres, (std::streamsize)largoString);
		nuevoString = string(caracteres);
		delete[] caracteres;

		if (!in.good()) {
			throw std::ios_base::failure("Error deserializando string...");
		}
		return nuevoString;
	}
};

template<class T>
class TransformadorBinarioLista : public BinaryTransformer<List<T>>
{
private:
	BinaryTransformer<T>* transformadorT;

public:
	TransformadorBinarioLista(BinaryTransformer<T>* transformadorT)
	{
		this->transformadorT = transformadorT;
	}

	void serialize(List<T> coleccion, std::ostream& out) override
	{
		int cantidadElementos = coleccion.getCantidad();
		out.write(reinterpret_cast<char*>(&cantidadElementos), sizeof(int));
		for (auto& item : coleccion)
		{
			this->transformadorT->serialize(item, out);
		}
	}

	List<T> deserialize(std::istream& in) override
	{
		List<T> newList;
		int cantidadElementos = 0;
		in.read(reinterpret_cast<char*>(&cantidadElementos), sizeof(int));
		for (int i = 0; i < cantidadElementos; i++)
		{
			newList.insert(this->transformadorT->deserialize(in));
		}

		return newList;
	}

	~TransformadorBinarioLista(){
		delete transformadorT;
	}

    
    class TransformadorBinarioEmpleado : public BinaryTransformer<Empleado*>
{
private:
	TransformadorBinarioString transformadorString;

public:

	void serialize(Empleado* elemento, std::ostream& out) override
	{
		this->transformadorString.serialize(elemento->getID(), out);
        this->transformadorString.serialize(elemento->getFirstLName(), out);
        this->transformadorString.serialize(elemento->getSecondLName(), out);
        this->transformadorString.serialize(elemento->getName(), out);
        this->transformadorString.serialize(elemento->getBornDate(), out);
        this->transformadorString.serialize(elemento->getSalary(), out);
		

	}

	Empleado* deserialize(std::istream& in) override
	{
		string id = this->transformadorString.deserialize(in);
		string firstLastName = this->transformadorString.deserialize(in);
        string secondLastName = this->transformadorString.deserialize(in);
        string name = this->transformadorString.deserialize(in);
        string bornDate = this->transformadorString.deserialize(in);
        string salary = this->transformadorString.deserialize(in);

		return new Empleado(id, firstLastName, secondLastName, name, bornDate, salary);
	}
};


};