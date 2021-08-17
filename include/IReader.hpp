#pragma once
#include "List.hpp"

template<class T>
class IReader
{
public:
	virtual List<T>* read() = 0;
	virtual ~IReader() = default;
};
