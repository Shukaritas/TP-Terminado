#pragma once

#include "Nota.h"

class CCurso : public CNota
{
private:

public:
	CCurso() : CNota()
	{

	}

	~CCurso()
	{

	}
	//hacer lista de padres;
	Lista<CPadre*>* obtenerPadres(CProfesor* pProfesor, Lista<CParentezco*>* arrParentezco) {
		Lista<CPadre*>* arrPadre = new Lista<CPadre*>();
		int pos = 0;
		for (size_t i = 0; i < arrParentezco->longitud(); i++)
		{
			CPadre* pPadre = arrParentezco->obtenerPos(i)->getPadre();
			CAlumno* pAlumno = arrParentezco->obtenerPos(i)->getAlumno();
			for (size_t j = 0; j < pAlumno->getCursos()->longitud(); j++)
			{
				if (pProfesor->getCursos() == pAlumno->getCursos()->obtenerPos(j)) {
					arrPadre->agregaPos(pPadre, pos++);
				}
			}
		}
		return arrPadre;
	}

	Lista<CAlumno*>* obtenerCursos(CProfesor* pProfesor, Lista<CParentezco*>* arrParentezco)
	{
		Lista<CAlumno*>* arrAlumnos = new Lista<CAlumno*>();
		int pos = 0;

		for (size_t i = 0; i < arrParentezco->longitud(); i++)
		{
			CAlumno* pAlumno = arrParentezco->obtenerPos(i)->getAlumno();

			for (size_t j = 0; j < pAlumno->getCursos()->longitud(); j++)
			{
				if (pProfesor->getCursos() == pAlumno->getCursos()->obtenerPos(j))
				{
					arrAlumnos->agregaPos(pAlumno, pos++);
				}
			}
		}

		return arrAlumnos;
	}

	void asignarCursoAlumno(CAlumno* pAlumno, int grado)
	{
		int DEFAULT_EXAM = 2;
		int MATE_EXAM = 2;
		int ARTE_EXAM = 3;

		switch (grado)
		{
			case 1: 
				pAlumno->setCurso("Matematica", MATE_EXAM, 0);
				pAlumno->setCurso("Comunicacion", DEFAULT_EXAM, 1);
				pAlumno->setCurso("Arte", ARTE_EXAM, 2);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM,  3);
				break;			
			case 2: 
				pAlumno->setCurso("Matematica", MATE_EXAM, 0);
				pAlumno->setCurso("Ciencias", DEFAULT_EXAM, 1);
				pAlumno->setCurso("D.P.C.C", DEFAULT_EXAM, 2);
				pAlumno->setCurso("Arte", ARTE_EXAM, 3);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM, 4);
				break;	
			case 3:
				pAlumno->setCurso("Matematica", MATE_EXAM, 0);
				pAlumno->setCurso("Fisica", DEFAULT_EXAM, 1);
				pAlumno->setCurso("Ciencias", DEFAULT_EXAM, 2);
				pAlumno->setCurso("Historia", DEFAULT_EXAM, 3);
				pAlumno->setCurso("Arte", ARTE_EXAM, 4);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM, 5);
				break;
			case 4: 
				pAlumno->setCurso("Calculo", DEFAULT_EXAM, 0);
				pAlumno->setCurso("Fisica", DEFAULT_EXAM, 1);
				pAlumno->setCurso("Quimica", DEFAULT_EXAM, 2);
				pAlumno->setCurso("Historia", DEFAULT_EXAM, 3);
				pAlumno->setCurso("Arte", ARTE_EXAM, 4);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM, 5);
				break;
			case 5:
				pAlumno->setCurso("Calculo", DEFAULT_EXAM, 0);
				pAlumno->setCurso("Computacion", DEFAULT_EXAM, 1);
				pAlumno->setCurso("Historia", DEFAULT_EXAM, 2);
				pAlumno->setCurso("Quimica", DEFAULT_EXAM, 3);
				pAlumno->setCurso("Arte", ARTE_EXAM, 4);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM, 5);
				break;
			case 6:
				pAlumno->setCurso("Calculo", DEFAULT_EXAM, 0);
				pAlumno->setCurso("Computacion", DEFAULT_EXAM, 1);
				pAlumno->setCurso("Humanidades", DEFAULT_EXAM, 2);
				pAlumno->setCurso("Filosofia", DEFAULT_EXAM, 3);
				pAlumno->setCurso("Histora", DEFAULT_EXAM, 4);
				pAlumno->setCurso("Arte", ARTE_EXAM, 5);
				pAlumno->setCurso("Eduacion_Fisica", DEFAULT_EXAM, 6);
				break;
			default: 
			{
				cout << "Grado inexistente" << endl;
				break;
			}
		}
	}

	void asignarCursoProfesor(CProfesor* pProfesor)
	{
		int elegir;

		cout << "Eliga el curso" << endl;
		cout << "[0] Matematica" << endl;
		cout << "[1] Comunicacion" << endl;
		cout << "[2] Ciencias" << endl;
		cout << "[3] Arte" << endl;
		cout << "[4] Educacion_Fisica" << endl;
		cout << "[5] D.P.C.C" << endl;
		cout << "[6] Fisica" << endl;
		cout << "[7] Quimica" << endl;
		cout << "[8] Historia" << endl;
		cout << "[9] Computacion" << endl;
		cout << "[10] Calculo" << endl;
		cout << "[11] Humanidades" << endl;
		cout << "[12] Filosofia" << endl;
		cin >> elegir;

		switch (elegir)
		{
		case 0:pProfesor->setCurso("Matematica");
			break;
		case 1:pProfesor->setCurso("Comunicacion");
			break;
		case 2:pProfesor->setCurso("Ciencias");
			break;
		case 3:pProfesor->setCurso("Arte");
			break;
		case 4:pProfesor->setCurso("Educacion_Fisica");
			break;
		case 5:pProfesor->setCurso("D.P.C.C");
			break;
		case 6:pProfesor->setCurso("Fisica");
			break;
		case 7:pProfesor->setCurso("Quimica");
			break;
		case 8:pProfesor->setCurso("Historia");
			break;
		case 9:pProfesor->setCurso("Computacion");
			break;
		case 10:pProfesor->setCurso("Calculo");
			break;
		case 11:pProfesor->setCurso("Humanidades");
			break;
		case 12:pProfesor->setCurso("Filosofia");
			break;

		}
	}
};