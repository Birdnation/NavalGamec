#pragma once
#include "Barco.h"
class Nougat: public Barco 
{
private:
	bool skill;
public:
	Nougat();
	Nougat(char id, string nombre,int vida, int blindaje);
	~Nougat();
};

