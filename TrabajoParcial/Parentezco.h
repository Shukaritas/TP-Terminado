#pragma once

#include "Alumno.h"
#include "Padre.h"

class CParentezco
{
private:
	CAlumno* pAlumno;
	CPadre* pPadre;
	Pension* pension;

public:
	CParentezco(CAlumno* pAlumno, CPadre* pPadre)
	{
		this->pAlumno = pAlumno;
		this->pPadre = pPadre;
		this->pension = pension;
	}

	~CParentezco()
	{
		delete this->pAlumno;
		delete this->pPadre;
		delete this->pension;
	}

	CPadre* getPadre() { return this->pPadre; }
	CAlumno* getAlumno() { return this->pAlumno; }	
	Pension* getPension() { return this->pension; }
	
	void setPadre(CPadre* dummy) { this->pPadre = dummy; }
	void setAlumno(CAlumno* dummy) { this->pAlumno = dummy; }
	void setPension(Pension* dummy) { this->pension = dummy; }

	void listar() 
	{
		cout << "TIPO DE APODERADO: " << pPadre->getTipo() << endl;
		cout << "NOMBRE DE " << pPadre->getTipo() << ": " << pPadre->getNombre() << endl;
		cout << "APELLIDO DE " << pPadre->getTipo() << ": " << pPadre->getApellido() << endl;
		cout << "CODIGO DE " << pPadre->getTipo() << ": " << pPadre->getCodigo() << endl;
		cout << "NOMBRE ALUMNO: " << pAlumno->getNombre() << endl;
		cout << "APELLIDO ALUMNO: " << pAlumno->getApellido() << endl;
		cout << "CODIGO ALUMNO: " << pAlumno->getCodigo() << endl;
		cout << "GRADO ALUMNO: " << pAlumno->getGrado() << endl;
		cout << "CURSOS: " << endl;
	}
	void listarPadre() {
		cout << "TIPO DE APODERADO: " << pPadre->getTipo() << endl;
		cout << "NOMBRE DE " << pPadre->getTipo() << ": " << pPadre->getNombre() << endl;
		cout << "APELLIDO DE " << pPadre->getTipo() << ": " << pPadre->getApellido() << endl;
		cout << "CODIGO DE " << pPadre->getTipo() << ": " << pPadre->getCodigo() << endl;
		cout << "Pensiones: " << pPadre->getCant() << endl;
	}
	void listaGeneralPensiones() {
		cout << "Numero de mensualidades:  ";
		cout << pPadre->getCant() << endl;;
		cout << "Precio: ";
		cout << "1200" << " * " << pPadre->getCant() << " = ";
		cout << 1200 * pPadre->getCant() << endl;
	}

};