#pragma once

class CCalificar
{
private:
	string curso;
	Lista<float>* notas;
	Lista<int>* examenes;
	float num_exam;

public:
	CCalificar()
	{
		notas = new Lista<float>();
		examenes = new Lista<int>();
	}

	//CCalificar(string curso, int nota, int num_exam) : curso(curso), nota(nota), num_exam(num_exam)
	//{
	//}

	~CCalificar()
	{
	}

	void setCurso(string cur) { this->curso = cur; }
	void setNota(float note, int i) 
	{ 
		this->notas->agregaPos(note, i);
	}	
	void setExamenes(float examen) 
	{ 
		num_exam = examen;
	}

	Lista<float>* getNota() { return notas; }
	string getCurso() { return curso; }
	float getNumExam() { return num_exam; }
};