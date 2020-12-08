#pragma once
#include <string>

using namespace std;

class Misil
{
private:
	string nombre;
	int rango;
	int dano;
	int cantMax;
public:
	Misil();
	Misil(string nombre, int rango, int dano, int cantMax);
	string get_nombre();
	int get_rango();
	int get_dano();
	int get_cantMax();
	void set_cantMax(int cant);
	~Misil();
};

