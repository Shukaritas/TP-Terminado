#pragma once
template <class T>
class NodoCola {
public:
	T dato;
	NodoCola<T>* siguiente;

	NodoCola(T v, NodoCola<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};