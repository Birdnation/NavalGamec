#include "stdafx.h"
#include "Misil.h"


Misil::Misil()
{
}

Misil::Misil(string nombre, int rango, int dano, int cantMax){
	this->nombre = nombre;
	this->rango = rango;
	this->dano = dano;
	this->cantMax = cantMax;
}

string Misil::get_nombre(){
	return this->nombre;
}

int Misil::get_rango(){
	return this->rango;
}

int Misil::get_dano(){
	return this->dano;
}

int Misil::get_cantMax(){
	return this->cantMax;
}

void Misil::set_cantMax(int cant){
	this->cantMax = cant;
}


Misil::~Misil()
{
}
