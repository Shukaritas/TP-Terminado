#include <iostream>

using namespace std;

#include <ctime>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <sstream>

#include "Cola.h"
#include "Lista.h"
#include "Persona.h"
#include "Parentezco.h"
#include "Profesor.h"
#include "Curso.h"
#include "Pension.h"

Lista<CParentezco*>* arrParentezco = new Lista<CParentezco*>();
Lista<CProfesor*>* arrProfesor = new Lista<CProfesor*>();
Lista<CPadre*>* arrPadre = new Lista<CPadre*>();
CCurso* pCursos = new CCurso();
Pension* ppension = new Pension();

void ingresarAlumno(int iPos)
{
	system("cls");
	string nom_pa, ape_pa, cod_pa, tip_pa;
	string nom_al, ape_al, cod_al; 
	int grad_al, matr=0;

	cout << "\n";
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "     REGISTRAR DATOS DE ALUMNO       " << endl;
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;

	cout << endl;

	cout << "Ingresar el nombre padre: "; cin >> nom_pa;
	cout << "Ingresar el apellido padre: "; cin >> ape_pa;
	cout << "Ingresar codigo padre: "; cin >> cod_pa;
	cout << "Ingresar tipo padre: "; cin >> tip_pa;
	cout << "El alumno esta matriculado?" << endl;
	cout << "<1> SI" << endl;
	cout << "<2> NO" << endl;
	cin >> matr;

	CPadre* pPadre = new CPadre(nom_pa, ape_pa, cod_pa, tip_pa);

	if (matr == 1) 
	{
		pPadre->asignarPensionesAPadre();
		arrPadre->agregaPos(pPadre, iPos);
	}
	if (matr == 2) 
	{
		cout << "Matricule al alumno" << endl;
		return;
	}
	do
	{
		if (matr < 0 || matr>2){
			cout << "Ingrese una opcion valida... ";
			cin >> matr;
		}
	} while (matr < 0 || matr>2);
	cout << "Ingresar el nombre alumno: "; cin >> nom_al;
	cout << "Ingresar el apellido alumno: "; cin >> ape_al;
	cout << "Ingresar codigo alumno: "; cin >> cod_al;
	cout << "Ingresar grado alumno: "; cin >> grad_al;

	CAlumno* pAlumno = new CAlumno(nom_al, ape_al, cod_al, grad_al);
	pCursos->asignarCursoAlumno(pAlumno, grad_al);

	CParentezco* pParentezco = new CParentezco(pAlumno, pPadre);
	arrParentezco->agregaPos(pParentezco, iPos);
}

void ingresarProfesor(int iPos)
{
	system("cls");
	string nom, ape, cod;
	int ele,volver;
	cout << "\n";
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "     REGISTRAR DATOS DE PROFESOR       " << endl;
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;

	cout << endl;

	cout << "Ingresar el nombre profesor: "; cin >> nom;
	cout << "Ingresar el apellido profesor: "; cin >> ape;
	cout << "Ingresar codigo profesor: "; cin >> cod;

	CProfesor* pProfesor = new CProfesor(nom, ape, cod);
	pCursos->asignarCursoProfesor(pProfesor);
	cout << "\n";
	cout << " -------------------------------------" << endl;
	cout << "|<1> Calificar a todos los Alumnos    |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "|<2> Citar Tutor                      |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Elegir: ";
	cin >> ele;
	switch(ele) 
	{
	case 1:
	{
		system("cls");
		int indices_al = 0;

		Lista<CAlumno*>* arrAlumnos = pCursos->obtenerCursos(pProfesor, arrParentezco);

		for (size_t i = 0; i < arrAlumnos->longitud(); i++)
		{
			CAlumno* pAlumno = arrAlumnos->obtenerPos(i);

			cout << "ALUMNO: " << i + 1 << endl;
			cout << "--------------------------------------" << endl;
			cout << "NOMBRE DEL ALUMNO: " << pAlumno->getNombre() << endl;
			cout << "APELLIDO DEL ALUMNO: " << pAlumno->getApellido() << endl;
			cout << "CODIGO DE ALUMNO: " << pAlumno->getCodigo() << endl;
			cout << "GRADO DEL ALUMNO: " << pAlumno->getGrado() << endl;
			cout << endl;
		}
		int list = arrAlumnos->longitud();
		do
		{
			cout << "Elige el alumno a calificar" << endl;
			cin >> indices_al;

			if (indices_al < 0 || indices_al > arrAlumnos->longitud())
			{
				cout << "Alumno invalido, ingrese un alumno valido" << endl;
				break;
			}
			CAlumno* pAlumno = arrAlumnos->obtenerPos(indices_al - 1);

			CCalificar* pCalificacion = pCursos->asignarNotas(pProfesor->getCursos(), pAlumno->getCursos(), pAlumno->getCursosExamenes());
			pAlumno->setCalificacion(pCalificacion);
			list--;
			arrAlumnos->obtenerPos(list - 1);
		} while (list!=0);
		break;
	}
	case 2: 
	{
		system("cls");
		bool bRomper = false;
		int romper = 0;
		int lista = 0;
		do
		{
			int indice_prof = 0;
			Lista<CPadre*>* arrPadre = pCursos->obtenerPadres(pProfesor, arrParentezco);
			lista = arrPadre->longitud();

			for (size_t i = 0; i < arrPadre->longitud(); i++)
			{
				CPadre* pPadre = arrPadre->obtenerPos(i);
				cout << "APODERADO: " << i + 1 << endl;
				cout << "--------------------------------------" << endl;
				cout << "NOMBRE DEL APODERADO: " << pPadre->getNombre() << endl;
				cout << "APELLIDO DEL APODERADO: " << pPadre->getApellido() << endl;
				cout << "CODIGO DE APODERADO: " << pPadre->getCodigo() << endl;
				cout << endl;
			}
			cout << "Elige el apoderado a citar" << endl;
			cin >> indice_prof;

			if (indice_prof < 0 || indice_prof > arrPadre->longitud())
			{
				cout << "Invalido. Ingrese de nuevo el dato" << endl;
				continue;
			}

			CPadre* pPadre = arrPadre->obtenerPos(indice_prof-1);
			pProfesor->gestionarCita(pPadre);

			cout << "Citar otro tutor?" << endl;
			cout << "[1] Si" << endl;
			cout << "[2] No" << endl;
			cin >> romper;

			if (romper == 1)
			{
				lista--;
			}
			else if(romper == 2)
			{
				break;
			}

		} while (!bRomper or lista > 0);
	}
	}
	arrProfesor->agregaPos(pProfesor, iPos);
}

int menu(){
	cout << "\n";
	cout << " -------------------------------------" << endl;
	cout << "|                MENU                 |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<1> Gestionar Alumno                 |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<2> Gestionar Profesor               |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<3> Gestion General                  |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<4> Salir                            |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	do
	{
		cin >> opcion;
		if (opcion < 0 || opcion>4)
			cout << "Ingrese una opcion valida... ";
	} while (opcion < 0 || opcion>4);

	return opcion;
}
int main()
{
	srand(time(NULL));
	int nalumnos = 0, nprofesores = 0;
	while (true) {
		int opc = menu();
		switch (opc) {
			int oc1, oc2, oc3;
		case 1:
			system("cls");
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|               ALUMNO                |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Registrar Alumno                 |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Administrar Pendientes           |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc1;
			switch (oc1) {
			case 1:
				ingresarAlumno(nalumnos);
				nalumnos++;
				break;
			case 2:
				int indice_cit = 0;
				int op;
				cout << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				cout << "      LISTA DE PADRES        " << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				for (int i = 0; i < arrParentezco->longitud(); i++) {
					cout << "\PADRE: " << i + 1 << endl;
					arrParentezco->obtenerPos(i)->listaGeneralPensiones();;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}
				cout << "Elegir al padre para eliminar todas sus pensiones: ";
				cin >> indice_cit;

				if (indice_cit < 0 || indice_cit > arrPadre->longitud())
				{
					cout << "Invalido. Ingrese de nuevo el dato" << endl;
					break;
				}
				CPadre* padre = arrPadre->obtenerPos(indice_cit - 1);
				Cola<Pension*>* cPension = padre->desencolarPensionesAPadre(arrPadre);
			}
			break;
		case 2:
			system("cls");
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|              PROFESOR               |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Registrar Profesor               |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Administrar Pendientes           |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc2;
			switch (oc2) {
			case 1:
				ingresarProfesor(nprofesores);
				nprofesores++;
				break;
			case 2:
				int profe = 0, variable = 0;
				cout << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				cout << "      LISTA DE PROFFESORES        " << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				for (int i = 0; i < arrProfesor->longitud(); i++) {
					cout << endl;
					cout << "\nProfesor: " << i + 1 << endl;
					arrProfesor->obtenerPos(i)->listarProfesor();
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}

				if (arrProfesor->longitud() == 0)
				{
					cout << endl;
					cout << "No hay profesores ingresados";
					cout << endl;
					break;
				}
				cout << "Eliga algun profesor" << endl;
				cin >> profe;

				CProfesor* pProfe = arrProfesor->obtenerPos(profe - 1);
				pProfe->mostrarCitas();

				cout << "Desea eliminar primera cita?" << endl;
				cout << "<1> SI" << endl;
				cout << "<2> NO" << endl;
				cin >> variable;
				if (variable == 1)
				{
					pProfe->desencolarCita();
				}
				if (variable == 2)
				{
					break;
				}
				do
				{
					if (variable < 0 || variable>2) {
						cout << "Ingrese una opcion valida... ";
						cin >> variable;
					}
				} while (variable < 0 || variable>2);
				break;
			}
			break;
		case 3:
			system("cls");
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|           ADMINISTRACION            |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Listar Alumnos                   |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Borrar Alumno                    |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<3> Listar Profesores                |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<4> Borrar Profesor                  |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc3;
			switch (oc3) {
			case 1: 
				system("cls");
				for (int i = 0; i < arrParentezco->longitud(); i++) {
					cout << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "      LISTA DE ALUMNOS        " << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "\nALUMNO: " << i + 1 << endl;
					arrParentezco->obtenerPos(i)->listar();

					for (size_t j = 0; j < arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->longitud(); j++)
					{
						cout << "\t -" << arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j) << " | Promedio: " << pCursos->obtenerPromedio(arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j), arrParentezco->obtenerPos(i)->getAlumno()->getCalificacion()) << endl;
					}
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}
				if (arrParentezco->longitud() == 0)
				{
					cout << endl;
					cout << "No hay alumnos ingresados";
					cout << endl;
				}
				break;
			
			case 2: 
				system("cls");
				int del;
				for (int i = 0; i < arrParentezco->longitud(); i++) {
					cout << "\nALUMNO: " << i + 1 << endl;
					arrParentezco->obtenerPos(i)->listar();

					for (size_t j = 0; j < arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->longitud(); j++)
					{
						cout << "\t -" << arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j) << " | Promedio: " << pCursos->obtenerPromedio(arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j), arrParentezco->obtenerPos(i)->getAlumno()->getCalificacion()) << endl;
					}
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}
				if (arrParentezco->longitud() == 0)
				{
					cout << endl;
					cout << "No hay alumnos ingresados";
					cout << endl;
				}
				cout << "Elija alumno a borrar: ";
				cin >> del;
				arrParentezco->eliminaPos(del - 1);
				break;
			case 3: 
				system("cls");
				cout << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				cout << "      LISTA DE PROFFESORES        " << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				for (int i = 0; i < arrProfesor->longitud(); i++) {
					cout << "\nProfesor: " << i + 1 << endl;
					arrProfesor->obtenerPos(i)->listarProfesor();
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}
				if (arrProfesor->longitud() == 0) {
					cout << endl;
					cout << "No hay profesores ingresados";
					cout << endl;
				}
				break;
			case 4:
				system("cls");
				int ele;
				cout << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				cout << "      LISTA DE PROFFESORES        " << endl;
				cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				for (int i = 0; i < arrProfesor->longitud(); i++) {
					cout << "\nProfesor: " << i + 1 << endl;
					arrProfesor->obtenerPos(i)->listarProfesor();
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
				}
				if (arrProfesor->longitud() == 0) {
					cout << endl;
					cout << "No hay profesores ingresados";
					cout << endl;
				}
				cout << "Elegir profesor a elimnar: ";
				cin >> ele;
				arrProfesor->eliminaPos(ele - 1);
				break;
			}
		case 4:
			break;
		}
	}
}