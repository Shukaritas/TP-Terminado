#pragma once
#include "Cola.h"
#include "NodoCola.h"
#include "Cita.h"

class CProfesor : CPersona
{
private:
	string curso;
	Cola<Cita*>* citas;
	int num_citas;

public:
	CProfesor(string& nombre, string& apellido, string& codigo) :
		CPersona(nombre, apellido, codigo)
	{
		this->citas = new Cola<Cita*>();
	}

	~CProfesor()
	{

	}

	void gestionarCita(CPadre* pPadre)
	{
		citas->encolar(new Cita(pPadre));
		num_citas++;
	}

	void mostrarCitas()
	{
		Cola<Cita*>* dummy = new Cola<Cita*>();
		Cita* pDummy;

		do
		{
			pDummy = citas->desencolar();
			dummy->encolar(pDummy);
			cout << pDummy->toString() << endl;
		} while (!citas->esVacia());

		citas = dummy;
	}

	void desencolarCita()
	{
		citas->desencolar();
	}

	string getCursos() { return this->curso; }
	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCodigo() { return this->codigo; }
	void setCurso(string dummy) { this->curso = dummy; }
	void listarProfesor() 
	{
		cout << "NOMBRE PROFESOR: "<< this->getNombre() <<endl;
		cout << "APELLIDO PROFESOR: " << this->getApellido() << endl;
		cout << "CODIGO PROFESOR: " << this->getCodigo() << endl;
		cout << "AREA: " << this->getCursos() << endl;
	}
};