#include <iostream>
#include <string>
#include "Piezas.h"

using namespace std;

Piezas::Piezas(string tipopieza,string letra,int tipo){
	this-> tipopieza = tipopieza;\
	this-> letra = letra;
	this-> tipo = tipo;

}

int Piezas::getTipo(){
	return tipo;
}

string Piezas::getLetra(){
	return letra;
}

string Piezas::getTipoPieza(){
	return tipopieza;
}

void Piezas::setLetra(string st){
	this-> letra = st;

}
