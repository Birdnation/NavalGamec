#pragma once
#include <string>

using namespace std;

class Barco
{
private:
	char id;
	string nombre;
	int vida;
	int blindaje;

public:
	Barco();
	Barco(char id, string nombre, int vida, int blindaje);
	char get_id();
	string get_nombre();
	int get_vida();
	int get_blindaje();
	void set_vida(int vida);
	void set_blindaje(int blindaje);
	~Barco();
};

