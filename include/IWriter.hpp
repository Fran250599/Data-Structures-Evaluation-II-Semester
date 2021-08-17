#pragma once
#include "List.hpp"

template<class T>
class IWritter
{
public:
	virtual void write(T element) = 0;
	virtual void writeAll(List<T>* elements) = 0;
	virtual ~IWritter() = default;
};

