#ifndef PIEZAS_H
#define PIEZAS_H

using namespace std;

class Piezas{
	private:
		string tipopieza;
		string letra;
		int tipo;
	public:
		Piezas(string,string,int);
		//~Piezas();
		int getTipo();
		string getLetra();
		void setLetra(string);
		string getTipoPieza();

};
#endif
