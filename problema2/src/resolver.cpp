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

vector < list < int > > losAdyacentes( list < Conexion > &conectados, int n){
	vector < list < int > > res(n+1);
	list < Conexion >::iterator it = conectados.begin();
	for (; it != conectados.end(); ++it){
		res[it->first.id].push_back(it->second.id);
		res[it->second.id].push_back(it->first.id);
	}
	return res;
}

Salida Problema2::resolver(Entrada& e){
	Salida s;
	///creamos conectados, y agregamos el primero a conectados
	int n = e.pueblos.size();
	list < pair < int , Conexion > > mejorConexionDe;
	list < pair < int , Conexion > >::iterator itConexion, itMejor ;

	///generamos AGM
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
	///las ordenamos de forma tal que las mas grandes queden al principio, para removerlas facilmente
	s.tuberias.sort(mayorDistancia);
	
	///ahora tenenmos un AGM, queremos un bosque generador minimo de a lo sumo k componentes conexas.
	for (int i = 1; i < e.cantCentrales && i < n; ++i){
		s.tuberias.pop_front();
	}
	
	vector < list < int > > adyacentes = losAdyacentes(s.tuberias,e.pueblos.size());
	
	///vemos donde poner las centrales.
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
				list< int > losAdyacentes = adyacentes[c];
				list< int >::iterator itAdy = losAdyacentes.begin();
				for(;itAdy != losAdyacentes.end(); ++itAdy){
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

	cout << s.centrales.size() << " ";
	cout << s.tuberias.size() << endl;

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
