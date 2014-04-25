#include "problema2.h"

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

Salida Problema2::resolver(const Entrada& e){
	Salida s;
	
	return s;
}


void Problema2::imprimoSalida(const Salida& s){
	cout << s.centrales.size() << " ";
	cout << s.tuberias.size() << endl;
	list< Pueblo >::iterator itCentr = s.centrales.begin();
	for(;itCentr != s.centrales.end(); ++itCentr){
		cout << itCentr->id << " ";
	}
	list< pair < Pueblo,Pueblo > >::iterator itTub = s.tuberias.begin();
	for(;itTub != s.centrales.end(); ++itTub){
		cout << itTub->first.id << " " << itTub->second.id << endl;
	}

}
