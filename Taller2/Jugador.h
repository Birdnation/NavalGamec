#pragma once
#include <string.h>
#include "Misil.h"
#include "Barco.h"

using namespace std;

class Jugador
{
private:
	string alias;
	Misil** carga;
	Misil** usados;
	Barco** destruidos;
	int posCarga = 0, posUsados = 0, posDestruidos = 0;
	int danoTotal;
public:
	Jugador();
	Jugador(string alias);
	string get_alias();
	Misil get_misiles(int pos);
	void set_cantidad(int cantidad, int pos);
	void set_danoTotal(int dano);
	void cargaMisil(Misil* misil, int cant);
	void cargaUsados(Misil* misil);
	void cargaDestruidos(Barco* barco);
	void eliminarMisil(int pos);
	int get_posCarga();
	int get_posUsados();
	int get_posDestruidos();
	int get_danoTotal();
	Misil get_usados(int pos);
	Barco get_destruidos(int pos);
	~Jugador();
};

