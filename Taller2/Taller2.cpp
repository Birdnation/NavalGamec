// Taller2.cpp : Defines the entry point for the console application.
// Taller2 Solucion. Creado por: Rodrigo Dominguez
// Estructura de datos. UCN.

#include "stdafx.h"
#include "Juego.h"


int main(){
	bool again = false, pregunta = false;
	string pregunta_str;
	Juego j = Juego();
	do{
		pregunta = false;
		j.ciclo();
		while (!pregunta){
			cout << "Desea volver a jugar? (SI/NO)";
			cin >> pregunta_str;
			if (pregunta_str == "SI"){
				pregunta = true;
			}else if (pregunta_str == "NO"){
				pregunta = true;
				again = true;
			}
		}
	} while (!again);
	system("pause");
	exit(0);
    return 0;
}

