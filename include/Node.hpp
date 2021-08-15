#pragma once
#include<iostream>
#include<sstream>


template <class T>
class Node {
private:
	Node* next;
	T data;

public:
	Node<T>();
	Node<T>(T d, Node* n);
	Node* getNext();
	T getData();

	void setNext(Node<T>* next);
	void setData(T data);

	std::string toString();

	~Node<T>();
};

template <class T>
Node<T>::Node() {
	this->next = nullptr;
	this->data = nullptr;
}

template <class T>
Node<T>::Node(T d, Node<T>* n) {
	this->next = n;
	this->data = d;
}
template <class T>
Node<T>* Node<T>::getNext() { return this->next; }

template <class T>
T Node<T>::getData() { return this->data; }

template <class T>
void Node<T>::setNext(Node* next) { this->next = next; }

template <class T>
void Node<T>::setData(T data) { this->data = data; }

template <class T>
std::string Node<T>::toString() {
	std::stringstream x;

	x << this->data->toString();

	return x.str();
}

template <class T>
Node<T>::~Node() {  }