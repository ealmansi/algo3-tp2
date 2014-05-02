#ifndef PROBLEMA_2_H
#define PROBLEMA_2_H

#include <list>
#include <utility>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace Problema2
{
	struct Pueblo{
		int id;
		pair <int, int> coord;
		Pueblo(){;} ///por el linker. Nosotros no lo usamos. Culpen al linker.
		Pueblo(int id ,int x ,int y)
			: id(id), coord(make_pair(x,y)){}
		
	};

	typedef pair < Pueblo, Pueblo >  Conexion;
	
	struct Entrada
	{
	  int cantCentrales;
	  list < Pueblo > pueblos;
	};

	struct Salida
	{
	  list < int > centrales;
	  list < Conexion > tuberias;
	};

	Entrada leerEntrada();

	Salida resolver(Entrada& e);

	void imprimoSalida(Salida& s);
}

#endif /* PROBLEMA_2_H */
