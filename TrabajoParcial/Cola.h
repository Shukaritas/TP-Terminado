#pragma once

#include "NodoCola.h"

using namespace std;
template<class T>
class Cola {
private:
	NodoCola<T>* inicio;
	NodoCola<T>* fin;
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	bool esVacia();
	void encolar(T v);
	T desencolar();

};
//Implementacion
template<class T>
bool Cola<T>::esVacia() {
	return(inicio == NULL);
}
template<class T>
void Cola<T>::encolar(T v) {
	NodoCola<T>* nodo = new NodoCola<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {
		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}
template<class T>
T Cola<T>::desencolar() 
{
	T dato = inicio->dato;
	if (inicio == fin) {
		inicio = NULL;
		fin = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}
	return dato;
}