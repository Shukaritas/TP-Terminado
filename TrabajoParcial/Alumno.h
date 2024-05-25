#pragma once

#include "Calificar.h"

class CAlumno : CPersona
{
private:
	Lista<string>* arrCursos;
	Lista<int>* arrCursosExamenes;
	Lista<CCalificar*>* arrCalificacion;
	int grado;
	int index;

public:

	CAlumno(string& nombre, string& apellido, string& codigo, int grado) : 
		CPersona(nombre, apellido, codigo)
	{
		this->grado = grado;
		this->arrCursos = new Lista<string>();
		this->arrCursosExamenes = new Lista<int>();
		this->arrCalificacion = new Lista<CCalificar*>();
		this->index = 0;
	}

	~CAlumno()
	{

	}

	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCodigo() { return this->codigo; }
	int getGrado() { return this->grado; }
	void setCurso(string curso, int maxExamen, int pos) { arrCursosExamenes->agregaPos(maxExamen, pos); arrCursos->agregaPos(curso, pos); }
	void setCalificacion(CCalificar* arrDummy) { this->arrCalificacion->agregaPos(arrDummy, index++); }
	Lista<string>* getCursos() { return this->arrCursos; }
	Lista<int>* getCursosExamenes() { return this->arrCursosExamenes; }
	Lista<CCalificar*>* getCalificacion() { return this->arrCalificacion; }
};