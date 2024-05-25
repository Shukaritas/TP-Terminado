 #pragma once

#include "Pension.h"

class CPadre : public CPersona
{
private:
	string tipoApoderado;
	Cola<Pension*>* cPension;
	Pension* pPension = new Pension();
	int cant_pensiones;

public:
	CPadre(string nombre, string apellido, string codigo, string tipoApoderado) :
		CPersona(nombre, apellido, codigo), 
		tipoApoderado(tipoApoderado)
	{
		cPension = new Cola<Pension*>();
		this->cant_pensiones = 1 + rand() % 12;
	}
	CPadre():CPersona(nombre, apellido, codigo) {}
	~CPadre(){}

	void setPensiones(Cola<Pension*>* dummy) {
		this->cPension = dummy;
	}
	Cola<Pension*>* getPension() {
		return this->cPension;
	}
	Cola<Pension*>* asignarPensionesAPadre() 
	{
		for (size_t i = 0; i < this->getCant(); i++)
		{
			cPension->encolar(new Pension(pPension->getPrecio()));
		}
		return cPension;
	}

	Cola<Pension*>* desencolarPensionesAPadre(Lista<CPadre*>* arrPadre)
	{
		Pension* pen = new Pension();
		int index = 0;
		do 
		{
			pen = cPension->desencolar();
			cout << pen->toString(index++) << endl;
		} while (!cPension->esVacia());
		cout << "Pensiones eliminadas" << endl;
		return cPension;
	}
	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCodigo() { return this->codigo; }
	string getTipo() { return this->tipoApoderado; }
	int getCant() { return this->cant_pensiones; }
};