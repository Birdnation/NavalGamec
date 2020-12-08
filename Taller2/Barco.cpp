#include "stdafx.h"
#include "Barco.h"


Barco::Barco()
{
}

Barco::Barco(char id, string nombre, int vida, int blindaje){
	this->id = id;
	this->nombre = nombre;
	this->vida = vida;
	this->blindaje = blindaje;
}

char Barco::get_id(){
	return this->id;
}

string Barco::get_nombre(){
	return this->nombre;
}

int Barco::get_vida(){
	return this->vida;
}

int Barco::get_blindaje(){
	return this->blindaje;
}

void Barco::set_vida(int vida){
	this->vida = vida;
}

void Barco::set_blindaje(int blindaje)
{
	this->blindaje = blindaje;
}


Barco::~Barco()
{
}
