#include "stdafx.h"
#include "Juego.h"


Juego::Juego()
{
}

void Juego::generarMisiles() {
	Misil* misil1 = new Misil("SKYPE LA", 3, 800, 5);
	Misil* misil2 = new Misil("JKING SA", 1, 200, 10);
	Misil* misil3 = new Misil("FAFI CP ", 3, 600, 5);
	Misil* misil4 = new Misil("JAMU CEE", 1, 300, 10);
	Misil* misil5 = new Misil("ITALYC DNO", 3, 1000, 3);
	Misil* misil6 = new Misil("ANGELINA FRS", 3, 2000, 1);
	this->arrMisil[0] = misil1;
	this->arrMisil[1] = misil2;
	this->arrMisil[2] = misil3;
	this->arrMisil[3] = misil4;
	this->arrMisil[4] = misil5;
	this->arrMisil[5] = misil6;
}

void Juego::generarBarcos() {

	Barco* nougat = new Barco('N', "NOUG", 750, 10);
	Barco* cortana = new Barco('C', "CORT", 2000, 0);
	Barco* vaio = new Barco('V', "VAIO", 550, 50);
	Barco* siri = new Barco('S', "SIRI", 1200, 0);
	Barco* lollipop = new Barco('L', "LPOP", 1100, 100);
	Barco* pojo = new Barco('P', "POJO", 1000, 0);
	Barco* gdg = new Barco('G', "GDG", 800, 0);
	Barco* hp = new Barco('H', "HP", 1500, 0);
	Barco* macox = new Barco('M', "MACX", 900, 10);
	Barco* zmart = new Barco('Z', "ZMRT", 600, 100);
	this->arrBarco[0] = nougat;
	this->arrBarco[1] = cortana;
	this->arrBarco[2] = vaio;
	this->arrBarco[3] = siri;
	this->arrBarco[4] = lollipop;
	this->arrBarco[5] = pojo;
	this->arrBarco[6] = gdg;
	this->arrBarco[7] = hp;
	this->arrBarco[8] = macox;
	this->arrBarco[9] = zmart;
}


int* Juego::generarAleatoriosSinRep()
{
	int vector[10];
	int numero;
	int aux;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		aux = i;
		numero = 1 + rand() % (11 - 1);
		for (int j = 0; j <= aux; j++) {
			if (numero == vector[j]) {
				aux = 0;
				i--;
			}
			while ((aux == i) && (numero != vector[j]) && (j == i)) {
				vector[i] = numero;
			}
		}
	}
	return vector;
}

int * Juego::generarAleatorios()
{
	int vector[10];
	int numero;
	int aux;
	for (int i = 0; i < 10; i++) {
		aux = i;
		numero = 1 + rand() % (11 - 1);
		vector[i] = numero;
	}
	return vector;
}

void Juego::crearNodos() {

	for (int i = 0; i < 10; i++) {
		this->list.agregarBarco(this->arrBarco[i], generarAleatorios()[i], generarAleatoriosSinRep()[i]);
	}
}


Jugador Juego::mainMenu() {
	Jugador player;
	string opcion;
	int eleccion;
	bool aux = false;
	system("cls");
	cout << "\n******************************************************";
	cout << "\n******************************************************";
	cout << "\n***************     GG GAMES (tm)     ****************";
	cout << "\n***************      NAVAL  GAME      ****************";
	cout << "\n******************************************************";
	cout << "\n**              - 1. NUEVA PARTIDA                  **";
	cout << "\n**                  - 2. SALIR                      **";
	cout << "\n******************************************************";
	cout << "\n******************************************************\n\n";
	cout << "INGRESE SU OPCION: ";
	while (!aux) {
		cin >> opcion;
		try {
			eleccion = stoi(opcion);
			switch (eleccion) {
			case 1:
				player = generarJugador();
				return player;
			case 2:
				exit(0);
			default:
				cout << "OPCION NO VALIDA. REINTENTE.\n";
				system("pause");
				mainMenu();
			}
		}
		catch (const std::exception&) {
			cout << "ERROR DEBE INGRESAR UN NUMERO.\n";
			system("pause");
			mainMenu();
		}
	}
	return nullptr;
}

Jugador Juego::generarJugador() {
	string nombre1, seleccion, cantidad_str;
	int mochila = 20, cantidad, seleccionInt;
	cout << "\n\n";
	cout << "\t - INGRESE ALIAS:\t";
	cin >> nombre1;
	cin.ignore();

	Jugador jugador1 = Jugador(nombre1);
	do {
		system("cls");
		cout << "\n\n*************************        MISILES         ************************";
		cout << "\n*************************************************************************";
		cout << "\n*\tNOMBRE\t\t**\tRANGO\t**\tDA\245O\t**\tCANT\t*";
		cout << "\n*************************************************************************";
		for (int i = 0; i < 6; i++) {
			cout << "\n*  " + to_string((i + 1)) + ".-  " + this->arrMisil[i]->get_nombre() + "\t**\t" + to_string(this->arrMisil[i]->get_rango()) + "\t**\t" + to_string(this->arrMisil[i]->get_dano()) + "\t**\t" + to_string(this->arrMisil[i]->get_cantMax()) + "\t*";
		}
		cout << "\n*************************************************************************\n\n";
		cout << "\t- " + nombre1 + ", DISPONES DE: " + to_string(mochila) + " MISILES PARA LLEVAR.\n";
		cout << "\t- Ingresa el numero del misil que deseas llevar: ";
		cin >> seleccion;
		cin.ignore();
		try {
			seleccionInt = stoi(seleccion);
			if (seleccionInt < 7 && seleccionInt > 0 && this->arrMisil[(seleccionInt - 1)]->get_cantMax() > 0) {
				cout << "\t- Misil Seleccionado: " + this->arrMisil[(seleccionInt - 1)]->get_nombre() << endl;
				cout << "\t- Ingresa la cantidad del misil seleccionado: ";
				cin >> cantidad_str;
				cin.ignore();
				try {
					cantidad = stoi(cantidad_str);
					while ((cantidad > this->arrMisil[(seleccionInt - 1)]->get_cantMax() || cantidad <= 0) || (mochila - cantidad) < 0) {
						cout << "\t- La cantidad no puede ser 0 o mayor a la capacidad maxima!\n";
						cout << "\t- Ingresa la cantidad del misil seleccionado: ";
						cin >> cantidad_str;
						try{
							cantidad = stoi(cantidad_str);
						}
						catch (const std::exception&){
							cout << "\t- Debe ingresar una cantidad numerica!\n";
						}
					}
					jugador1.cargaMisil(this->arrMisil[(seleccionInt - 1)], cantidad);
					this->arrMisil[(seleccionInt - 1)]->set_cantMax((this->arrMisil[(seleccionInt - 1)]->get_cantMax() - cantidad));
					mochila = mochila - cantidad;
				}
				catch (const std::exception&) {
					cout << "\t\tERROR DEBE INGRESAR DATOS NUMERICOS.\n";
					cout << "\t\t";
					system("pause");
				}
			}
			else {
				cout << "\t\tHA SELECCIONADO UN MISIL INVALIDO O SIN CARGAS. REINTENTE.\n";
				cout << "\t\t";
				system("pause");
			}
		}
		catch (const std::exception&) {
			cout << "\t\tERROR DEBE INGRESAR DATOS NUMERICOS.\n";
			cout << "\t\t";
			system("pause");
		}

	} while (mochila > 0);
	return jugador1;
}


void Juego::ciclo() {
	generarBarcos();
	crearNodos();
	generarMisiles();
	//Variables de seleccion
	string x_str, y_str, seleccion_str;
	signed int x, y, seleccion;

	Jugador jugador = mainMenu();
	bool derrota = false, victoria = false;
	while (!derrota && !victoria){
		system("cls");
		cout << "###########  NAVAL  GAME  ############\n";
		this->list.mostrarMatriz();
		this->list.printBarcos();
		cout << "#############  MISILES  ##############\n";
		for (int i = 0; i < jugador.get_posCarga(); i++) {
			cout << to_string((i + 1)) + ".-" + jugador.get_misiles(i).get_nombre() + "\t[Damage: " + to_string(jugador.get_misiles(i).get_dano()) + " Range: " + to_string(jugador.get_misiles(i).get_rango()) + "] X " + to_string(jugador.get_misiles(i).get_cantMax()) + "\n";
		}
		cout << "Seleccione el numero de un misil: ";
		cin >> seleccion_str;
		cin.ignore();
		cout << "Seleccione la coordenada X: ";
		cin >> x_str;
		cin.ignore();
		cout << "Seleccione la coordenada Y: ";
		cin >> y_str;
		cin.ignore();
		try {
			seleccion = stoi(seleccion_str);
			x = stoi(x_str);
			y = stoi(y_str);
			if (x > 20 || y > 10 || seleccion > jugador.get_posCarga()){
				cout << "ERROR ATAQUE FUERA DE COORDENADA O MISIL ERRONEO, REINTENTE." << endl;
				system("pause");
				continue;
			}
		}
		catch (const std::exception&) {
			cout << "ERROR DEBE ESCRIBIR VALORES, REINTENTE." << endl;
			system("pause");
			continue;
		};
		if (jugador.get_misiles((seleccion - 1)).get_cantMax() >= 1) {
			if (jugador.get_misiles((seleccion - 1)).get_rango() == 3) {
				for (int i = (x - 1); i <= (x + 1); i++) {
					for (int j = (y - 1); j <= (y + 1); j++) {
						if ((i > 0 && j > 0) && (i <= 20 && j <= 10)){
							this->list.dañarBarco(i, j, jugador.get_misiles((seleccion - 1)).get_dano(), &jugador, &jugador.get_misiles((seleccion - 1)));
						}
					}
				}
			}
			else{
				this->list.dañarBarco(x, y, jugador.get_misiles((seleccion - 1)).get_dano(), &jugador, &jugador.get_misiles((seleccion - 1)));
			}
			jugador.set_cantidad((jugador.get_misiles((seleccion - 1)).get_cantMax() - 1), (seleccion - 1));
		}else{
			cout << "ERROR DEBE SELECCIONAR UN MISIL, REINTENTE." << endl;
			system("pause");
			continue;
		}
		if (this->list.movimiento() < 1) {
			victoria = true;
		}
		if (this->list.buscar('V')) {
			this->list.skill(this->list.buscar('V')->get_barco());
		}
		if (this->list.buscar('P')){
			this->list.skill(this->list.buscar('P')->get_barco());
		}
		if (this->list.buscar('G')){
			this->list.skill(this->list.buscar('G')->get_barco());
		}
		if (jugador.get_misiles((seleccion - 1)).get_cantMax() == 0) {
			jugador.eliminarMisil((seleccion - 1));
		}
		if (this->list.derrota() || jugador.get_posCarga() < 1){
			derrota = true;
		}
		system("pause");
	}
	system("cls");
	if (derrota){
		cout << " ######  ####### ######  ######  ####### #######    #    \n#     # #       #     # #     # #     #    #      # #\n#     # #       #     # #     # #     #    #     #   #\n#     # #####   ######  ######  #     #    #    #     #\n#     # #       #   #   #   #   #     #    #    #######\n#     # #       #    #  #    #  #     #    #    #     #\n######  ####### #     # #     # #######    #    #     #\n";
		cout << "#################  ESTADISTICAS  ##################\n\n";
		cout << "DA\245O TOTAL CAUSADO: " + to_string(jugador.get_danoTotal()) + "\n";
		cout << "BARCOS DESTRUIDOS: :\n";
		for (int i = 0; i < jugador.get_posDestruidos(); i++) {
			cout << "\t > " + jugador.get_destruidos(i).get_nombre() + " HP: " + to_string(jugador.get_destruidos(i).get_vida()) << endl;
		}
	}
	else if (victoria){
		cout << " #     # ###  #####  ####### ####### ######  ###    #       ###    ###\n #     #  #  #     #    #    #     # #     #  #    # #      ###    ###\n #     #  #  #          #    #     # #     #  #   #   #     ###    ###\n #     #  #  #          #    #     # ######   #  #     #     #      #\n  #   #   #  #          #    #     # #   #    #  #######              \n   # #    #  #     #    #    #     # #    #   #  #     #    ###    ###\n    #    ###  #####     #    ####### #     # ### #     #    ###    ###\n";
		cout << "#################  ESTADISTICAS  ##################\n\n";
		cout << "DA\245O TOTAL CAUSADO: " + to_string(jugador.get_danoTotal()) + "\n";
		cout << "BARCOS DESTRUIDOS: :\n";
		for (int i = 0; i < jugador.get_posDestruidos(); i++){
			cout << "\t > " + jugador.get_destruidos(i).get_nombre() + " HP: " + to_string(jugador.get_destruidos(i).get_vida()) << endl;
		}
		cout << "MISILES UTILIZADOS: :\n";
		for (int i = 0; i < jugador.get_posUsados(); i++){
			cout << "\t > Cant: " + to_string(jugador.get_usados(i).get_cantMax()) + " Nombre: " + jugador.get_usados(i).get_nombre() << endl;
		}
	}
}


Juego::~Juego()
{
}
