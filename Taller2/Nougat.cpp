#include "stdafx.h"
#include "Nougat.h"


Nougat::Nougat()
{
}

Nougat::Nougat(char id, string nombre, int vida, int blindaje): Barco(id,nombre,vida,blindaje){
	this->skill = true;
}


Nougat::~Nougat()
{
}
