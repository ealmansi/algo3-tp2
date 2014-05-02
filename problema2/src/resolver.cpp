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

bool mayorDistancia(const Conexion& a ,const Conexion& b){
	return distanciaCuadrada(a.first,a.second) > distanciaCuadrada(b.first,b.second); 
}

list < int > losAdyacentes(list < Conexion > &conectados , int c){
	list < int > res;
	list < Conexion >::iterator it = conectados.begin();
	for (; it != conectados.end(); ++it)	{
		if(it->first.id == c){
			res.push_back(it->second.id);
		}
		else if (it->second.id == c ){
			res.push_back(it->first.id);	
		}
	}
	return res;
}

Salida Problema2::resolver(Entrada& e){
	Salida s;
	///creo conectados, y agrego el primero a conectados
	int n = e.pueblos.size();
	list < pair < int , Conexion > > mejorConexionDe;
	list < pair < int , Conexion > >::iterator itConexion, itMejor ;

	list < Pueblo >::iterator itPueblos = e.pueblos.begin();
	Pueblo actual = e.pueblos.front();
	itPueblos++;
	for(;itPueblos != e.pueblos.end(); ++itPueblos){
		mejorConexionDe.push_back(make_pair(distanciaCuadrada(actual,(*itPueblos)),make_pair((*itPueblos),actual)));
	}
	for(int i = 0; i < n-1 ; ++i){
		itConexion = mejorConexionDe.begin();
		itMejor = mejorConexionDe.begin();
		for (; itConexion != mejorConexionDe.end(); ++itConexion){
			if(itConexion->first < itMejor->first){
				itMejor = itConexion;
			}
		}
		s.tuberias.push_back(itMejor->second);
		actual = itMejor->second.first;
		mejorConexionDe.erase(itMejor);

		itConexion = mejorConexionDe.begin();
		for (; itConexion != mejorConexionDe.end(); ++itConexion){
			int dist = distanciaCuadrada(actual,itConexion->second.first);
			if(dist < itConexion->first){
				itConexion->first = dist;
				itConexion->second.second = actual;
			}
		}
	}
	s.tuberias.sort(mayorDistancia);
	for (int i = 1; i < e.cantCentrales; ++i){
		s.tuberias.pop_front();
	}

	vector < bool > yaPase(e.pueblos.size()+1,false);
	queue< int > q;
	for ( int i = 1; i <= (int) e.pueblos.size(); ++i){
		if(!yaPase[i]){
			s.centrales.push_back(i);
			q.push(i);
			yaPase[i] = true;
			while(!q.empty()){
				int c = q.front();
				q.pop();				
				list< int > adyacentes = losAdyacentes(s.tuberias, c);
				list< int >::iterator itAdy = adyacentes.begin();
				for(;itAdy != adyacentes.end(); ++itAdy){
					if(!yaPase[*itAdy]){
						yaPase[*itAdy] = true;
						q.push(*itAdy);
					}
				}
			}
		}
	}
	
	
	return s;
}


void Problema2::imprimoSalida(Salida& s){
	cout << s.tuberias.size() << " ";
	cout << s.centrales.size() << endl;
	list< int >::iterator itCentr = s.centrales.begin();
	for(;itCentr != s.centrales.end(); ++itCentr){
		cout << (*itCentr) << " ";
	}
	cout << endl;
	list< pair < Pueblo,Pueblo > >::iterator itTub = s.tuberias.begin();
	for(;itTub != s.tuberias.end(); ++itTub){
		cout << itTub->first.id << " " << itTub->second.id << endl;
	}

}
