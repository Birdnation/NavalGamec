#include "stdafx.h"
#include "Jugador.h"


Jugador::Jugador()
{
}

Jugador::Jugador(string alias){
	this->alias = alias;
	this->carga = new Misil*[20];
	this->usados = new Misil*[20];
	this->destruidos = new Barco*[20];
}

string Jugador::get_alias(){
	return this->alias;
}

Misil Jugador::get_misiles(int pos){
	return *this->carga[pos];
}

void Jugador::set_cantidad(int cantidad, int pos){
	this->carga[pos]->set_cantMax(cantidad);
}

void Jugador::set_danoTotal(int dano){
	this->danoTotal = this->danoTotal + dano;
}

void Jugador::cargaMisil(Misil* misil, int cant){
	Misil* nuevoMisil = new Misil(misil->get_nombre(), misil->get_rango(), misil->get_dano(), cant);
	for (int i = 0; i < this->posCarga; i++){
		if (this->carga[i]->get_nombre() == nuevoMisil->get_nombre()){
			this->carga[i]->set_cantMax(this->carga[i]->get_cantMax() + cant);
			return;
		}
	}
	this->carga[this->posCarga] = nuevoMisil;
	this->posCarga++;
}

void Jugador::cargaUsados(Misil * misil){
	Misil* nuevoMisil = new Misil(misil->get_nombre(), misil->get_rango(), misil->get_dano(), 1);
	for (int i = 0; i < this->posUsados; i++){
		if (this->usados[i]->get_nombre() == nuevoMisil->get_nombre()) {
			this->usados[i]->set_cantMax(this->usados[i]->get_cantMax() + 1);
			return;
		}
	}
	this->usados[this->posUsados] = nuevoMisil;
	this->posUsados++;
}

void Jugador::cargaDestruidos(Barco * barco){
	this->destruidos[this->posDestruidos] = barco;
	this->posDestruidos++;
}

void Jugador::eliminarMisil(int pos){
	for (int i = pos; i < this->posCarga; i++) {
		this->carga[i] = this->carga[(i + 1)];
	}
	this->posCarga--;
}

int Jugador::get_posCarga(){
	return this->posCarga;
}

int Jugador::get_posUsados(){
	return this->posUsados;
}

int Jugador::get_posDestruidos(){
	return this->posDestruidos;
}

int Jugador::get_danoTotal(){
	return this->danoTotal;
}

Misil Jugador::get_usados(int pos){
	return *this->usados[pos];
}

Barco Jugador::get_destruidos(int pos){
	return *this->destruidos[pos];
}

Jugador::~Jugador()
{
}
