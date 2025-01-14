﻿#include "NodoLista.h"
#include <functional>
typedef unsigned int uint;
template <class T>
class Lista 
{
private:
    NodoLista<T>* nodo;
    typedef function<int(T, T)> Comp;
    NodoLista<T>* ini;
    uint lon; // longitud de elementos en la lista

public:
    Lista() : ini(nullptr), lon(0) { nodo = new NodoLista<T>(); }
    ~Lista();
    Lista(NodoLista<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    T buscar(T elem);


    void agregar(T pNodo); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
    //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d);// suma nodos ordenados de menor a mayor
    bool esta(T d); //retorna true cuando d est� en la lista
    void borrarDato(T d);// borra el nodo que contiene a d

};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    NodoLista<T>* nuevo = new NodoLista<T>(elem);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}
template <class T>
T Lista<T>::buscar(T elem) {
    NodoLista<T>* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elem, elem) == 0) {
            return aux->elem;
        }
        aux = aux->sgte;
    }
    return 0;
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        NodoLista<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        NodoLista<T>* nuevo = new NodoLista<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregarPos(elem, lon);
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        NodoLista<T>* aux = ini;
        ini = ini->sgte;
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= lon) {
        cout << "La posición está fuera de los límites de la lista." << endl;
        return;
    }

    NodoLista<T>* actual = ini;
    NodoLista<T>* anterior = nullptr;

    for (uint i = 0; i < pos; ++i) {
        anterior = actual;
        actual = actual->get_Sgte();
    }

    if (anterior == nullptr) {
        ini = actual->get_Sgte();
    }
    else {
        anterior->set_Sgte(actual->get_Sgte());
    }
    delete actual;
    --lon;
}
template <class T>
void Lista<T>::eliminaFinal() {
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        NodoLista<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sgte;
        }
        aux->elem = elem;
    }
}
template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}


template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        NodoLista<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return NULL;
    }
}
template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <class T>
void Lista<T>::agregar(T d)
{
    NodoLista<T>* nuevo = new NodoLista<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}




