#include "stdafx.h"
#include "ListNodoBarco.h"


ListNodoBarco::ListNodoBarco(){
}

ListNodoBarco::ListNodoBarco(int filas, int col){
	this->filas = filas;
	this->col = col;
	for (int i = 1; i <= filas; i++) {
		this->arrow[i] = new NodoBarco(nullptr, i, 0);
		this->arrow[i]->set_left(this->arrow[i]);
	}
	for (int i = 1; i <= col; i++) {
		this->acol[i] = new NodoBarco(nullptr, 0, i);
		this->acol[i]->set_up(this->acol[i]);
	}
}

void ListNodoBarco::agregarBarco(Barco* barco, int fila, int col){
	//creacion del nodo
	NodoBarco* nuevoBarco = new NodoBarco(barco, fila, col);
	//auxiliares por fila y columna (HEADS)
	NodoBarco* currentF = this->arrow[fila];
	NodoBarco* currentC = this->acol[col];
	//ingreso por fila
	while (currentF->get_left()->get_col() > col){
		currentF = currentF->get_left();
	}
	nuevoBarco->set_left(currentF->get_left());
	currentF->set_left(nuevoBarco);
	//ingreso por columna
	while (currentC->get_up()->get_fila() > fila){
		currentC = currentC->get_up();
	}
	nuevoBarco->set_up(currentC->get_up());
	currentC->set_up(nuevoBarco);
}

void ListNodoBarco::mostrarMatriz(){
	cout << "     ";
	for (int i = 1; i <= this->col; i++) {
		cout << "Y" + to_string(i) + " ";
	}
	cout << endl;
	for (int i = 1; i <= this->filas; i++) {
		cout << "X" + to_string(i);
		if (i < 10) {
			cout << " ";
		}
		for (int j = 1; j <= this->col; j++) {
			NodoBarco* current = &*this->arrow[i]->get_left();
			while (current != this->arrow[i]) {
				if (current->get_fila() == i && current->get_col() == j) {
					if (i < 10) {
						cout << "  ";
					}
					else {
						cout << "  ";
					}
					cout << current->get_barco()->get_id();
					break;
				}
				current = current->get_left();
			}
			if (current == this->arrow[i]) {
				cout << "  \372";
			}
		}
		cout << endl;
	}
}

void ListNodoBarco::printBarcos(){
	cout << "##############  BARCOS  ##############\n";
	for (int i = 1; i <= this->filas; i++){
		NodoBarco* actual = this->arrow[i]->get_left();
		while (actual->get_col() != 0){
			cout << actual->get_barco()->get_nombre() + "<" + actual->get_barco()->get_id() + ">" + "\t\t*HP " + to_string(actual->get_barco()->get_vida()) + " * P: " + to_string(actual->get_barco()->get_blindaje()) + "\n";
			actual = actual->get_left();
		}
	}
}


void ListNodoBarco::eliminarBarco(int x, int y){
	NodoBarco* actualF = &*this->arrow[x];
	NodoBarco* actualC = &*this->acol[y];
	//Busqueda
	while (actualF->get_left()->get_col() != y){
		actualF = actualF->get_left();
	}
	while (actualC->get_up()->get_fila() != x){
		actualC = actualC->get_up();
	}
	//reasignacion por fila
	actualF->set_left(actualF->get_left()->get_left());
	//reasignacion por col
	actualC->set_up(actualC->get_up()->get_up());
}

void ListNodoBarco::dañarBarco(int x, int y, int dano, Jugador* jugador, Misil* misil){
	int nuevoDano = 0;
	NodoBarco* actual = this->arrow[x]->get_left();
	while (actual->get_col() != 0){
		if (actual->get_col() == y){
			if ((actual->get_barco()->get_vida() + actual->get_barco()->get_blindaje()) > dano){
				nuevoDano = dano - actual->get_barco()->get_blindaje();
				if (actual->get_barco()->get_id() == 'S' && this->atkSiri == 0){
					this->atkSiri++;
					cout << "[!] SIRI SKILL:  BLOQUEO DE DA\245O!\n";
					return;
				}
				cout << "[!] DA\245O A: " + actual->get_barco()->get_nombre() + " CON " + to_string(nuevoDano) + "PTS DE DA\245O\n";
				actual->get_barco()->set_vida((actual->get_barco()->get_vida() - nuevoDano));
				actual->get_barco()->set_blindaje(0);
				if ((actual->get_barco()->get_id() == 'N') || (actual->get_barco()->get_id() == 'M')) {
					skill(actual->get_barco());
				}
				else if (actual->get_barco()->get_id() == 'H') {
					this->atkHp++;
					if (this->atkHp == 3) {
						skill(actual->get_barco());
					}
				}
				jugador->set_danoTotal(nuevoDano);
				jugador->cargaUsados(misil);
				return;
			}
			else{
				if (actual->get_barco()->get_id() == 'L') {
					skill(actual->get_barco());
				}
				else if (actual->get_barco()->get_id() == 'Z') {
					skill(actual->get_barco());
				}
				nuevoDano = actual->get_barco()->get_vida() + actual->get_barco()->get_blindaje();
				jugador->set_danoTotal(nuevoDano);
				jugador->cargaUsados(misil);
				jugador->cargaDestruidos(actual->get_barco());
				cout << "[!] DA\245O A: " + actual->get_barco()->get_nombre() + " CON " + to_string(nuevoDano) + "PTS DE DA\245O\n";
				eliminarBarco(actual->get_fila(), actual->get_col());
				cout << "[!] " + actual->get_barco()->get_nombre() + " HA SIDO DESTRUIDO!\n";
				if (buscar('C')){
					skill(buscar('C')->get_barco());
				}
				
				return;
			}
		}
		actual = actual->get_left();
	}
}

int ListNodoBarco::movimiento(){
	int contar = 0;
	for (int i = 19; i > 0; i--){
		NodoBarco* actual = arrow[i]->get_left();
		while (actual->get_col() != 0){
			contar++;
			actual->set_fila((actual->get_fila() + 1));
			actual = actual->get_left();
		}
		arrow[(i + 1)] = actual;
	}
	arrow[1] = arrow[20];
	return contar;
}

bool ListNodoBarco::derrota()
{
	NodoBarco* actual = arrow[20]->get_left();
	if (actual != arrow[20]){
		return true;
	}
	return false;
}

void ListNodoBarco::skill(Barco* barco){
	if (barco->get_id() == 'N') {//NOUGAT
		barco->set_vida((barco->get_vida() + 10));
		barco->set_blindaje((barco->get_blindaje() + 5));
		cout << "[!] NOUGAT HABILIDAD:  HP+10   P+5\n";
	}
	else if (barco->get_id() == 'C') {//CORTANA
		barco->set_vida((barco->get_vida() + 5));
		cout << "[!] CORTANA HABILIDAD:  HP+5\n";
	}
	else if (barco->get_id() == 'V') {//VAIO
		barco->set_blindaje((barco->get_blindaje() + 1));
		cout << "[!] VAIO HABILIDAD:  P+1\n";
	}
	else if (barco->get_id() == 'L') {//LOLLIPOP
		for (int i = 1; i <= this->filas; i++){
			NodoBarco* actual = this->arrow[i]->get_left();
			while (actual->get_col() != 0){
				actual->get_barco()->set_vida(actual->get_barco()->get_vida() + 10);
				actual = actual->get_left();
			}
		}
		cout << "[!] LOLLIPOP HABILIDAD:  HP+10 A TODOS LOS BARCOS\n";
	}
	else if (barco->get_id() == 'P') {//POJO
		barco->set_vida((barco->get_vida() + 5));
		cout << "[!] POJO HABILIDAD:  HP+5\n";
	}
	else if (barco->get_id() == 'G') {//GDG
		barco->set_vida((barco->get_vida() + 1));
		cout << "[!] GDG HABILIDAD:  HP+1\n";
	}
	else if (barco->get_id() == 'H') {//HP
		barco->set_blindaje((barco->get_blindaje() + 300));
		cout << "[!] HP HABILIDAD:  P+300\n";
	}
	else if (barco->get_id() == 'M') {//MACOX
		barco->set_blindaje((barco->get_blindaje() + 10));
		cout << "[!] MACOX HABILIDAD:  SHIELD+10\n";
	}
	else if (barco->get_id() == 'Z') {//ZMART
		movimiento();
		cout << "[!] ZMART HABILIDAD:  TODOS LOS BARCOS SE MUEVEN\n";
	}
}

NodoBarco* ListNodoBarco::buscar(char id){
	for (int i = 1; i <= this->filas; i++){
		NodoBarco* actual = this->arrow[i]->get_left();
		while (actual->get_col() != 0){
			if (actual->get_barco()->get_id() == id){
				return actual;
			}

			actual = actual->get_left();
		}
	}
	return nullptr;
}

ListNodoBarco::~ListNodoBarco()
{
}
