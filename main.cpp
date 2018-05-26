#include <iostream>
#include <string>
#include "Piezas.h"

using namespace std;
void ImprimirTablero(Piezas***);
bool win(Piezas***,string,string);

int main(){
	bool end = false;
	string nombre1;
	string nombre2;
	cout << "Bienvenidos" << endl;
	cout << "Ingrese Nombre del Jugador 1: " << endl;
	cin  >> nombre1;
	cout << "Ingrese Nombre del Jugador 2: " << endl;
	cin  >> nombre2;
	Piezas*** tablero = new Piezas**[8];
	for(int i=0;i<8;i++){
		tablero[i] = new Piezas*[8];
		for(int j=0;j<8;j++){
			tablero[i][j] = NULL;
		}
	}
	tablero[5][0] = new Piezas("Marine","B",1);
	tablero[5][2] = new Piezas("Marine","B",1);
	tablero[5][4] = new Piezas("Marine","B",1);	
	tablero[5][6] = new Piezas("Marine","B",1);
	tablero[6][1] = new Piezas("Marine","B",1);
	tablero[6][3] = new Piezas("Marine","B",1);
	tablero[6][5] = new Piezas("Marine","B",1);
	tablero[6][7] = new Piezas("Marine","B",1);
	tablero[7][0] = new Piezas("Marine","B",1);
	tablero[7][2] = new Piezas("Marine","B",1);
	tablero[7][4] = new Piezas("Marine","B",1);
	tablero[7][6] = new Piezas("Marine","B",1);

	tablero[0][1] = new Piezas("Marine","N",2);
	tablero[0][3] = new Piezas("Marine","N",2);
	tablero[0][5] = new Piezas("Marine","N",2);
	tablero[0][7] = new Piezas("Marine","N",2);
	tablero[1][0] = new Piezas("Marine","N",2);
	tablero[1][2] = new Piezas("Marine","N",2);
	tablero[1][4] = new Piezas("Marine","N",2);
	tablero[1][6] = new Piezas("Marine","N",2);
	tablero[2][1] = new Piezas("Marine","N",2);
	tablero[2][3] = new Piezas("Marine","N",2);
	tablero[2][5] = new Piezas("Marine","N",2);
	tablero[2][7] = new Piezas("Marine","N",2);

			
	for(int i =0;i<8;i++){
		cout << i+1 << " |";
		for(int j=0;j<8;j++){
			if(tablero[i][j] != NULL){
				cout << tablero[i][j]->getLetra() << "|";
			}else{
				cout << " " << "|";
			}
		}
		cout << "" << endl;		
	}
	cout << endl;
	cout << "   1|2|3|4|5|6|7|8|" << endl;
		
	bool turno = false;
	while(end==false){
		if(turno == true){
			cout << "Turno de: " << nombre2 << endl;
			int x,y,x1,y1;
			cout << "Ingrese coordenada X de Pieza a mover: ";
			cin >> x;
			cout << "Ingrese coordenada Y de Pieza a mover: ";
			cin >> y;
			cout << "Ingrese coordenada X de espacio a mover la pieza: ";
			cin >> x1;
			cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
			cin >> y1;
			while(x>8 || x<1 || y>8 || y<1 || x1>8 || x1<1 || y1>8 || y1<1 ){
				cout << "Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
			while(tablero[x-1][y-1]== NULL){
				cout << "Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
			while(tablero[x-1][y-1]->getLetra() != "N"){
				cout << "2Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
				
			x--;y--;x1--;y1--;
			int g = x1 - x;
			int k = y1 - y;
			int s = y - y1;
			int cont = 0;
			if(g==k && g==1 && k==1){
				for(int i=x+1,j=y+1;i<=x1,j<=y1;i++,j++){
					cout << g << " " << endl;
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "B"){
							if(i+1 == x1 && j+1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;
				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = false;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[7][i] != NULL){
						if(tablero[7][i]-> getLetra() == "N"){
							cout << "Se convirtio a General" << endl;
							tablero[7][i]->setLetra("GN");
						}
					}
				}
				ImprimirTablero(tablero);
			}else if(g==s && g==1 && g==1){
				for(int i=x+1,j=y-1;i<=x1,j>=y1;i++,j--){
					cout << g << " " << endl;
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "B"){
							if(i+1 == x1 && j-1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;

				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = false;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[7][i] != NULL){
						if(tablero[7][i]-> getLetra() == "N"){
							cout << "Se convirtio a General" << endl;
							tablero[7][i]->setLetra("GN");
						}
					}
				}
				ImprimirTablero(tablero);

			}else if(g==k){
				for(int i=x+1,j=y+1;i<=x1,j<=y1;i++,j++){
					cout << g << " " << endl;
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "B"){
							if(i+1 == x1 && j+1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;
				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = false;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[7][i] != NULL){
						if(tablero[7][i]-> getLetra() == "N"){
							cout << "Se convirtio a General" << endl;
							tablero[7][i]->setLetra("GN");
						}
					}
				}	
				ImprimirTablero(tablero);

			}else if(g==s){
				for(int i=x+1,j=y-1;i<=x1,j>=y1;i++,j--){
					cout << g << " " << endl;
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "B"){
							if(i+1 == x1 && j-1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;

				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = false;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[7][i] != NULL){
						if(tablero[7][i]-> getLetra() == "N"){
							cout << "Se convirtio a General" << endl;
							tablero[7][i]->setLetra("GN");
						}
					}
				}
				ImprimirTablero(tablero);

			}else{
				cout << "Coordenadas Invalidas, INgreselas de nuevo" << endl;
			}
			win(tablero,nombre1,nombre2);
		}else if(turno == false){
			cout << "Turno de: " << nombre1 << endl;
			int x,y,x1,y1;
			cout << "Ingrese coordenada X de Pieza a mover: ";
			cin >> x;
			cout << "Ingrese coordenada Y de Pieza a mover: ";
			cin >> y;
			cout << "Ingrese coordenada X de espacio a mover la pieza: ";
			cin >> x1;
			cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
			cin >> y1;
			while(x>8 || x<1 || y>8 || y<1 || x1>8 || x1<1 || y1>8 || y1<1 ){
				cout << "Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
			while(tablero[x-1][y-1]== NULL){
				cout << "Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
			while(tablero[x-1][y-1]->getLetra() != "B"){
				cout << "2Coordenadas Incorrectas, Ingreselas de nuevo: "<< endl;
				cout << "Ingrese coordenada X de Pieza a mover: ";
				cin >> x;
				cout << "Ingrese coordenada Y de Pieza a mover: ";
				cin >> y;
				cout << "Ingrese coordenada X de espacio a mover la pieza: ";
				cin >> x1;
				cout << "Ingrese coordenada Y de espacio a mover la pieza: ";
				cin >> y1;

			}
				
			x--;y--;x1--;y1--;
			int g = x -x1;
			int k = y -y1;
			int s = y1 -y;
			int cont = 0;
			if(g==k && g==1 && k==1){
				for(int i=x-1,j=y-1;i>=x1,j>=y1;i--,j--){
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "N"){
							if(i-1 == x1 && j-1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;
				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = true;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[0][i] != NULL){
						if(tablero[0][i]-> getLetra() == "B"){
							cout << "Se convirtio a General" << endl;
							tablero[0][i]->setLetra("GB");
						}
					}
				}
				ImprimirTablero(tablero);
			}else if(g==s && g==1 && g==1){
				for(int i=x-1,j=y+1;i>=x1,j<=y1;i--,j++){
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "N"){
							if(i-1 == x1 && j+1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = false;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;

				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = true;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[0][i] != NULL){
						if(tablero[0][i]-> getLetra() == "B"){
							cout << "Se convirtio a General" << endl;
							tablero[0][i]->setLetra("GB");
						}
					}
				}
				ImprimirTablero(tablero);

			}else if(g==k){
				for(int i=x-1,j=y-1;i>=x1,j>=y1;i--,j--){
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "N"){
							if(i-1 == x1 && j-1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = true;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;
				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = true;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[0][i] != NULL){
						if(tablero[0][i]-> getLetra() == "B"){
							cout << "Se convirtio a General" << endl;
							tablero[0][i]->setLetra("GB");
						}
					}
				}
				ImprimirTablero(tablero);


			}else if(g==s){
				for(int i=x-1,j=y+1;i>=x1,j<=y1;i--,j++){
					if(tablero[i][j] != NULL){
						if(tablero[i][j]->getLetra() == "N"){
							if(i-1 == x1 && j+1  == y1){
								tablero[x1][y1] = tablero[x][y];
								tablero[x][y] = NULL;
								tablero[i][j] = NULL;
								cout << "Capturo" << endl;
								turno = true;
								cont=0;
								break;
							}
						}
					}
					if(tablero[i][j] != NULL){
						cout << "Ingreso coordenadas equivocadas" << endl;
						cout << "break" << endl;
						break;
					}
					cont++;

				}
				if(cont == g ){
					tablero[x1][y1] = tablero[x][y];
					tablero[x][y] = NULL;
					turno = true;
				}
				cont =0;
				for(int i =0;i<8;i++){
					if(tablero[0][i] != NULL){
						if(tablero[0][i]-> getLetra() == "B"){
							cout << "Se convirtio a General" << endl;
							tablero[0][i]->setLetra("GB");
						}
					}
				}
				ImprimirTablero(tablero);

			}else{
				cout << "Coordenadas Invalidas, INgreselas de nuevo" << endl;
			}
			win(tablero,nombre1,nombre2);

		}		
	}
}


void ImprimirTablero(Piezas*** tablero){
	for(int i =0;i<8;i++){
		cout << i+1 << " |";
		for(int j=0;j<8;j++){
			if(tablero[i][j] != NULL){
					cout << tablero[i][j]->getLetra() << "|";
			}else{
				cout << " " << "|";
			}
		}
		cout << "" << endl;		
	}
	cout << endl;
	cout << "   1|2|3|4|5|6|7|8|" << endl;

}


bool win(Piezas*** tablero,string nombre1,string nombre2){
	int contB =0;
	int contN =0;
	for(int i =0;i<8;i++){
		for(int j=0;j<8;j++){
			if(tablero[i][j] != NULL){
				if(tablero[i][j]->getLetra() == "N"){
					contN++;
				}else if(tablero[i][j]->getLetra() == "B"){
					contB++;
				}
			}
		}
	}
	if(contB == 0){
		cout << "Gana Jugador: "<< nombre2 << endl;
		return true;
	}else if(contN == 0){
		cout << "Gana Jugador: "<< nombre1 << endl;
		return true;
	}
	return false;

}
