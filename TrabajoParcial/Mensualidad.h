#pragma once
#include "NodoMensualidad.h"
#include <iostream>
using namespace std;
template<class T>
class Mensualidad {
private:
	NodoMensualidad<T>* inicio;
	NodoMensualidad<T>* fin;
public:
	Mensualidad() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	bool esVacia();
	void encolar(T v);
	T desencolar();

};
//Implementacion
template<class T>
bool Mensualidad<T>::esVacia(){
	return(inicio == NULL);
}
template<class T>
void Mensualidad<T>::encolar(T v) {
	NodoMensualidad<T>* nodo = new NodoMensualidad<T>(v);
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
T Mensualidad<T>::desencolar() {
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