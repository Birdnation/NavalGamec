#pragma once
#include <ctime>
#include <iostream>
#include "Misil.h"
#include "Jugador.h"
#include "ListNodoBarco.h"

using namespace std;

class Juego
{
private:
	Misil* arrMisil[5];
	Barco* arrBarco[10];
	ListNodoBarco list = ListNodoBarco(20, 10);
public:
	Juego();
	void generarMisiles();
	void generarBarcos();
	int* generarAleatoriosSinRep();
	int* generarAleatorios();
	void crearNodos();
	Jugador mainMenu();
	Jugador generarJugador();
	void ciclo();
	~Juego();
};

