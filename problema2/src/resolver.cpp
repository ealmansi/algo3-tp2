#include "problema2.h"
#include <climits>

using namespace std;
using namespace Problema2;

Entrada Problema2::leerEntrada(){
	Entrada e;
	int n,x,y;
	cin >> n;
	cin >> e.cantCentrales;
	for(int i = 1; i<=n;++i){
		cin >> x;
		cin >> y;
		e.pueblos.push_back(Pueblo(i,x,y));
	}		
	return e;
}

int distanciaCuadrada(const Pueblo& a, const Pueblo& b){
	return (a.coord.first - b.coord.first) * (a.coord.first - b.coord.first)
		+ (a.coord.second - b.coord.second) * (a.coord.second - b.coord.second);
}

Salida Problema2::resolver(Entrada& e){
	Salida s;
	///creo conectados, y agrego el primero a conectados
	list< Pueblo > conectados;
	conectados.push_back(e.pueblos.front());
	e.pueblos.pop_front();
	int n = e.pueblos.size();
	int min;
	pair< Pueblo, Pueblo > conexion;
	list< Pueblo >::iterator itMejorPueblo;
	///usamos Prim
	for(int i = 1; i < n; ++i){
		min = INT_MAX;
		list< Pueblo >::iterator itPuebloConectados = conectados.begin();
		for(;itPuebloConectados != conectados.end(); ++itPuebloConectados){
			
			list< Pueblo >::iterator itPueblos = e.pueblos.begin();
			for(;itPueblos != e.pueblos.end(); ++itPueblos){
				if(distanciaCuadrada(*itPuebloConectados, *itPueblos) < min){
					min = distanciaCuadrada(*itPuebloConectados, *itPueblos);
					conexion = make_pair(*itPuebloConectados, *itPueblos);
					itMejorPueblo = itPueblos;
				}
			}
		}
		conectados.push_back(*itMejorPueblo);
		e.pueblos.erase(itMejorPueblo);
		s.tuberias.push_back(conexion);
	}
	///ahora ya estan todos conectados, vamos a sacar las conexiones 

	
	
	return s;
}


void Problema2::imprimoSalida(Salida& s){
	cout << s.centrales.size() << " ";
	cout << s.tuberias.size() << endl;
	list< Pueblo >::iterator itCentr = s.centrales.begin();
	for(;itCentr != s.centrales.end(); ++itCentr){
		cout << itCentr->id << " ";
	}
	list< pair < Pueblo,Pueblo > >::iterator itTub = s.tuberias.begin();
	for(;itTub != s.tuberias.end(); ++itTub){
		cout << itTub->first.id << " " << itTub->second.id << endl;
	}

}
