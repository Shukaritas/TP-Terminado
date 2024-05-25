#pragma once

#include "Padre.h"

class Cita {
private:
	CPadre* pPadre;
public:
	Cita(CPadre* pPadre)
	{
		this->pPadre = pPadre;
	}
	~Cita()
	{

	}

	string toString() {
		ostringstream ss;
		ss << "Cita con el apoderado:" << endl;
		ss << "- NOMBRE: ";
		ss << pPadre->getNombre()<<endl;
		ss << "- APELLIDO: ";
		ss << pPadre->getApellido() << endl;
		ss << "- CODIGO: ";
		ss << pPadre->getCodigo() << endl;
		return (ss.str());
	}
};