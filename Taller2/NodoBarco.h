#pragma once
#include "Barco.h"
class NodoBarco
{
private:
	NodoBarco * left;
	NodoBarco * up;
	Barco* barco;
	int fila;
	int col;
public:
	NodoBarco();
	NodoBarco(Barco* barco, int fila, int col);
	Barco* get_barco();
	int get_fila();
	int get_col();
	NodoBarco* get_left();
	NodoBarco* get_up();
	void set_fila(int fila);
	void set_col(int col);
	void set_left(NodoBarco* left);
	void set_up(NodoBarco* up);
	~NodoBarco();
};

