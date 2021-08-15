#pragma once
#include "Node.hpp"

//ListaGenerica para usuarios
template <class T>
class List {
private:
	Node<T>* first;
	int cantidad;
public:
	List<T>();
	List<T>(Node<T>* f);
	Node<T>* getFirst() const;
	void setFirst(Node<T>* first);
	int getCantidad() const;
	void setCantidad(int cantidad);
	void insert(T element);
	T obtenerElemento(int);
  	T obtenerElementoPorCodigo(std::string);
	T obtenerElementoPorId(std::string);
	bool vacia() const;
	bool buscarEspecificoPorCodigo(std::string code);   
	bool buscarEspecificoPorNombre(std::string name);
	bool buscarEspecificoPorId(std::string id);
	void eliminarEspecifico(std::string id);
	std::string toString(); 
	~List();
};
template <class T>
List<T>::List() { this->first = nullptr; this->cantidad = 0; }

template <class T>
List<T>::List(Node<T>* f) { this->first = f; }

template <class T>
Node<T>* List<T>::getFirst() const {
	if (this->first != nullptr) {
		return first;
	}
	else{
		throw std::invalid_argument("Lista vacia.");
	}
}

template <class T>
void List<T>::setFirst(Node<T>* first) { this->first = first; }

template <class T>
int List<T>::getCantidad() const { return cantidad; }

template <class T>
void List<T>::setCantidad(int cantidad) { this->cantidad = cantidad; }

template <class T>
void List<T>::insert(T element) {
	if (this->first == nullptr) {
		this->first = new Node<T>(element, nullptr);
		cantidad++;
	}
	else {
		Node<T>* aux = this->first;

		while (aux->getNext() != nullptr) {
			aux = aux->getNext();
		}
		aux->setNext(new Node<T>(element, nullptr));
		this->cantidad++;
	}
}


template <class T>
T List<T>::obtenerElemento(int i) {

	Node<T>* aux = this->first;
	int j = 0;

	if (j == i) {
		return this->first->getData();
	}
	else {
		while (j < i) {
			aux = aux->getNext();
			j++;
		}
		return aux->getData();
	}

}

/*--------------------------------------------------------------------------*/
template <class T>
T List<T>::obtenerElementoPorCodigo(std::string code) {
	if (this->first != nullptr) {
		if (this->first->getData()->getCode() == code) {
			return this->first->getData();
		}
		else {
			Node<T>* aux = this->first->getNext();

			while (aux->getNext() != nullptr) {
				if (aux->getData()->getCode() == code) {
					return aux->getData();
				}
				aux = aux->getNext();
			}
			throw std::invalid_argument("No existe.");
		}

	}
	else {
		throw std::invalid_argument("No existe.");
	}
}

template <class T>
T List<T>::obtenerElementoPorId(std::string id) {
	if (this->first != nullptr) {
		if (this->first->getData()->getId() == id) {
			return this->first->getData();
		}
		else {
			Node<T>* aux = this->first->getNext();

			while (aux->getNext() != nullptr) {
				if (aux->getData()->getId() == id) {
					return aux->getData();
				}
				aux = aux->getNext();
			}
			return nullptr;
		}

	}
	else {
		throw std::invalid_argument("No existe.");
	}
}

template <class T>
bool List<T>::buscarEspecificoPorCodigo(std::string code) {
	Node<T>* aux = first;

	if (aux != nullptr) {
		if (aux->getData()->getCode() == code) {
			return true;
		}
		else {
			while (aux->getNext() != nullptr) {
				aux = aux->getNext();
				if (aux->getData()->getCode() == code) {
					return true;
				}
			}
			
		}
	}
	return false;
}

template <class T>
bool List<T>::buscarEspecificoPorNombre(std::string nombre) {
	Node<T>* aux = first;

	if (aux != nullptr) {
		if (aux->getData()->getCode() == nombre) {
			return true;
		}
		else {
			while (aux->getNext() != nullptr) {
				aux = aux->getNext();
				if (aux->getData()->getName() == nombre) {
					return true;
				}
			}
			
		}
	}
	return false;
}

template <class T>
bool List<T>::buscarEspecificoPorId(std::string id) {
	Node<T>* aux = first;

	if (aux != nullptr) {
		if (aux->getData()->getId() == id) {
			return true;
		}
		else {
			while (aux->getNext() != nullptr) {
				aux = aux->getNext();
				if (aux->getData()->getId() == id) {
					return true;
				}
			}

		}
	}
	return false;
}

/*T* buscarElemento(double datoEspecifico) {
	Node* aux = this->first;
	while (aux != NULL) {
		if (aux->getData()->getValor() == datoEspecifico)
			return pactual->obtenerInformacionNodo();
		else
			pactual = pactual->avanzar();
	}
	return NULL;
}*/

/*int buscarPosicionElemento(double datoEspecifico) {
	pactual = pinicio;
	int i = 1;
	while (pactual != NULL) {
		if (pactual->obtenerInformacionNodo()->getValor() == datoEspecifico)
			return i;
		else {
			pactual = pactual->avanzar();
			i++;
		}
	}
	return -1;
}*/
template <class T>
bool List<T>::vacia() const {
	return this->first == nullptr;
}

template <class T>
void List<T>::eliminarEspecifico(std::string id) {		//Nos ayudar� a eliminar usuarios especificos de cualquier tipo
	Node<T>* aux;
	Node<T>* actual = this->first;
	if (this->first == NULL) { //SI LA LISTA ESTA VAC�A.
		throw std::invalid_argument("Lista vacia.");
	}
	if (this->first->getData()->getId() == id) { //SI ES EL PRIMER NODO.
		actual = actual->getNext();
		this->first->~Nodo();
		this->first = actual;
		this->cantidad--;
	}
	//CUANDO NO ES EL PRIMER NODO, DEBE BUSCAR EN LA LISTA. 
	while (actual != nullptr && actual->getNext()->getData()->getId() != id)
		actual = actual->getNext();

	if (actual == nullptr) {//SI NO LO ENCONTR�.
		throw std::invalid_argument("No se encontr� el usuario.");
	}
	//SI LO ENCONTR�.
	aux = actual->getNext();
	actual->setNext(aux->getNext());
	aux->~Node();
	this->cantidad--;
}


//void eliminarPrimero() {
//	if (this->first != nullptr)
//		Node* aux = this->first;
//	aux = this->first->getNext();
//	this->first = this->first->getNext();	
//	this->cantidad--;
//}

template <class T>
std::string List<T>::toString() {
	std::stringstream l;
	int i = this->cantidad;
	i++;
	Node<T>* aux = this->first;

	int j = 1;
	while (aux != nullptr) {

		l << "[" << j << "] ";
		l << aux->toString() << std::endl;
		aux = aux->getNext();
		i--;
		j++;
	}
	return l.str();
}
/*--------------------------------------------------------------------------*/




template <class T>
List<T>::~List() {
	while (this->first != nullptr) {
		Node<T>* aux = this->first;
		this->first = this->first->getNext();
		aux->~Node();
	}
	this->cantidad = 0;
}
