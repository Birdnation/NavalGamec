#include "stdafx.h"
#include "NodoBarco.h"


NodoBarco::NodoBarco()
{
}

NodoBarco::NodoBarco(Barco* barco, int fila, int col){
	this->barco = barco;
	this->fila = fila;
	this->col = col;
	this->up = nullptr;
	this->left = nullptr;
}

Barco* NodoBarco::get_barco(){
	return this->barco;
}

int NodoBarco::get_fila(){
	return this->fila;
}

int NodoBarco::get_col(){
	return this->col;
}

NodoBarco * NodoBarco::get_left(){
	return this->left;
}

NodoBarco * NodoBarco::get_up() {
	return this->up;
}

void NodoBarco::set_fila(int fila){
	this->fila = fila;
}

void NodoBarco::set_col(int col){
	this->col = col;
}

void NodoBarco::set_left(NodoBarco * left){
	this->left = left;
}

void NodoBarco::set_up(NodoBarco * up) {
	this->up = up;
}

NodoBarco::~NodoBarco()
{
}
