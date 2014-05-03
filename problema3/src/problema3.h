#ifndef PROBLEMA_3_H
#define PROBLEMA_3_H

#include <list>
#include <vector>

namespace Problema3
{
	struct Casillero
	{
	  int f;
	  int c;
	  int k;
	  Casillero() {}
	  Casillero(int f, int c, int k)
	    : f(f), c(c), k(k) {}
	};

	struct Entrada
	{
	  int n;
	  Casillero origen;
	  Casillero destino;
	  int k_max;
	  std::vector< std::vector < int > > tablero;
	};

	struct Salida
	{
	  int saltos;
	  std::list< Casillero > caminoMinimo;
	};

	Entrada leerEntrada();

	Salida resolver(Entrada &e);

	void imprimoSalida(Salida &s);
	std::list< Casillero > losAdyacentes(const Entrada &e, const Casillero &c);
}

#endif /* PROBLEMA_3_H */
