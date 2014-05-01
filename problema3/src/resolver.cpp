#include "problema3.h"
#include <climits>
#include <queue>

using namespace std;
using namespace Problema3;

typedef vector< pair< Casillero, int > > Matriz; 
typedef vector< Matriz > Matriz2D; 
typedef vector< Matriz2D > Matriz3D; 

Entrada Problema3::leerEntrada(){
	Entrada e;
	cin >> e.n;
	int fo, co, fd, cd ,k;
	cin >> fo;
	cin >> co;
	cin >> fd;
	cin >> cd;
	cin >> k;
	e.origen = Casillero(fo,co,k);
	e.destino = Casillero(fd,cd,0);
	e.k_max = k;
	///hago tablero
	e.tablero.push_back(vector< int >(e.n+1));
	for(int i = 1; i <= e.n; ++i){
		e.tablero.push_back(vector< int >(e.n+1));
		e.tablero[i].push_back(-1);
		for(int j = 1; j <=e.n;++j){
			int temp;
			cin >> temp;
			e.tablero[i][j] = temp;
		}
	}
	
	return e;
}

/*
pair< Casillero, int >* damePos(const Casillero& c, const pair < Casillero, int> & yaPase[][][]){
	return &yaPase[c.f][c.c][c.k];	
}
*/


Salida Problema3::resolver(Entrada& e){
	Salida s;
	
	///inicializo matriz de 3 dimensiones. Cada celda tiene un casillero y un int que representa la distancia minima desde el origen
	///-1 significa que todavia no llegue
	Matriz3D yaPase(e.n+1, Matriz2D(e.n+1, Matriz(e.k_max+1, make_pair(Casillero(0,0,0), -1))));
	//	Matriz3D yaPase(e.k_max+1, Matriz2D(e.n+1, Matriz(e.n+1, make_pair(Casillero(0,0,0), -1))));
	///casilleros van de 1 a n.
	
	///BFS
	queue< Casillero > q;
	yaPase[e.origen.f][e.origen.c][e.origen.k].second = 0;
	int kFinal;
	q.push(e.origen);
	
	while(!q.empty()){
		Casillero c = q.front();
		q.pop();
		if(c.c == e.destino.c && c.f == e.destino.f){
			///llegamos a la que queriamos
			kFinal = c.k;
			break;
		}
		
		list< Casillero > adyacentes = losAdyacentes(e, c);
		list< Casillero >::iterator itAdy = adyacentes.begin();
		for(;itAdy != adyacentes.end(); ++itAdy){
			if(yaPase[itAdy->f][itAdy->c][itAdy->k].second == -1){
				yaPase[itAdy->f][itAdy->c][itAdy->k].first = c;
				yaPase[itAdy->f][itAdy->c][itAdy->k].second = yaPase[c.f][c.c][c.k].second + 1;
				q.push(*itAdy);
			}
		}
	}
	
	s.saltos = yaPase[e.destino.f][e.destino.c][kFinal].second;
	Casillero padre(e.destino.f, e.destino.c, kFinal);
	for(int i = 0; i <= s.saltos; ++i){
		s.caminoMinimo.push_front(padre);
		padre = yaPase[padre.f][padre.c][padre.k].first;
	}
	
	return s;
}

list< Casillero > Problema3::losAdyacentes(const Entrada& e, const Casillero& c){
	list< Casillero > ady;
	int potencia = e.tablero[c.f][c.c];
	///estos son sin usar los K del jugador
	for(int i = 1; i <= potencia && i <= n; ++i){
		///abajo
		if(c.f+i <= e.n){
			ady.push_back(Casillero(c.f+i, c.c, c.k));
		}
		///arriba
		if(c.f-i > 0){
			ady.push_back(Casillero(c.f-i, c.c, c.k));
		}
		///derecha
		if(c.c+i <= e.n){
			ady.push_back(Casillero(c.f, c.c+i, c.k));
		}
		///izquierda
		if(c.c-i > 0){
			ady.push_back(Casillero(c.f, c.c-i, c.k));
		}
	}
	///usando Kaes
	for(int i = 1; i <= c.k && i <= n; ++i){
		///abajo
		if(c.f+i+potencia <= e.n){
			ady.push_back(Casillero(c.f+i+potencia, c.c, c.k-i));
		}
		///arriba
		if(c.f-i-potencia > 0){
			ady.push_back(Casillero(c.f-i-potencia, c.c, c.k-i));
		}
		///derecha
		if(c.c+i+potencia <= e.n){
			ady.push_back(Casillero(c.f, c.c+i+potencia, c.k-i));
		}
		///izquierda
		if(c.c-i-potencia > 0){
			ady.push_back(Casillero(c.f, c.c-i-potencia, c.k-i));
		}
	}
	
	return ady; 
}


void Problema3::imprimoSalida(Salida& s){
	cout << s.saltos << endl;
	list< Casillero >::iterator itPadre = s.caminoMinimo.begin();
	list< Casillero >::iterator itCamino = s.caminoMinimo.begin();
	++itCamino;
	for(;itCamino != s.caminoMinimo.end(); ++itCamino){
		cout << itCamino->f << " " << itCamino->c << " " << itPadre->k - itCamino->k << endl;
		++itPadre;
	}
}
