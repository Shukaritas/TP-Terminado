#pragma once

#include "Padre.h"

class Pension 
{
private:
	int precio;
public:
	Pension() {
		this->precio = 0;
	}
	Pension(int precio) {
		this->precio = 1200;
	}
	~Pension(){}

	int getPrecio() { return this->precio=1200; }

	string toString(int index) 
	{
		ostringstream ss;
		ss << "Pension N";
		ss << index + 1;
		ss << " | Precio: ";
		ss << this->getPrecio();

		return (ss.str());
	}
};