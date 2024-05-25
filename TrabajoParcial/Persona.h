#pragma once

class CPersona
{
protected:
	string nombre, apellido, codigo;
	//Mas variables de persona

public:
	CPersona(string& nombre, string& apellido, string& codigo) : 
		nombre(nombre), apellido(apellido), codigo(codigo)
	{

	}
	
	~CPersona()
	{

	}
};