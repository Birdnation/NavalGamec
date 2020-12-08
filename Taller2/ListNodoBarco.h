#pragma once
#include "NodoBarco.h"
#include "Jugador.h"
#include "Misil.h"
#include <iostream>
using namespace std;

class ListNodoBarco
{
private:
	int filas, col;
	int atkSiri = 0, atkHp = 0;
	NodoBarco* arrow[20];
	NodoBarco* acol[10];

public:
	ListNodoBarco();
	ListNodoBarco(int filas, int col);
	void agregarBarco(Barco* barco, int fila, int col);
	void mostrarMatriz();
	void printBarcos();
	void eliminarBarco(int x, int y);
	void dañarBarco(int x, int y, int dano, Jugador* jugador, Misil* misil);
	int movimiento();
	bool derrota();
	void skill(Barco* barco);
	NodoBarco* buscar(char id);
	~ListNodoBarco();
};

