#pragma once

#include "Calificar.h"

class CNota
{
private:

public:
	CNota()
	{

	}
	~CNota()
	{

	}
	CCalificar* asignarNotas(string curso, Lista<string>* arrCursos, Lista<int>* arrCursosExamenes)
	{
		CCalificar* pCalificar = new CCalificar();
		for (size_t i = 0; i < arrCursos->longitud(); i++)
		{
			if (curso == arrCursos->obtenerPos(i))
			{
				for (size_t j = 0; j < arrCursosExamenes->obtenerPos(i); j++)
				{
					int nota;
					cout << "INGRESE NOTA: ";
					cin >> nota;
					if (nota > 20)
					{
						nota = 20;
					}
					else if (nota < 0)
					{
						nota = 0;
					}
					pCalificar->setCurso(arrCursos->obtenerPos(i));
					pCalificar->setNota(nota, j);
					pCalificar->setExamenes(arrCursosExamenes->obtenerPos(j));
				}
			}
		}
		return pCalificar;
	}

	float obtenerPromedio(string curso, Lista<CCalificar*>* arrCalificar)
	{
		if (arrCalificar->longitud() <= 0)
			return 0;

		float sum = 0;
		float prom = 0;

		for (size_t i = 0; i < arrCalificar->longitud(); i++)
		{
			if (arrCalificar->obtenerPos(i)->getCurso() == curso)
			{
				for (size_t j = 0; j < arrCalificar->obtenerPos(i)->getNota()->longitud(); j++)
				{
					float f = arrCalificar->obtenerPos(i)->getNota()->obtenerPos(j);
					sum += f;
				}

				prom = arrCalificar->obtenerPos(i)->getNumExam();
			}
		}

		if (sum == 0 && prom == 0)
			return 0;

		return sum / prom;
	}
};
