#ifndef PROBLEMA_3_H
#define PROBLEMA_3_H

#include <list>
#include <vector>

namespace Problema3
{
  struct Casillero
  {
    Casillero() {}
    Casillero(int f, int c, int k)
      : f(f), c(c), k(k) {}
    bool operator==(const Casillero& otro)
    	{ return f == otro.f && c == otro.c && k == otro.k; }
    bool operator!=(const Casillero& otro)
    	{ return f != otro.f || c != otro.c || k != otro.k; }
    
    int f;
    int c;
    int k;
  };

  struct Entrada
  {
    int n;
    Casillero origen;
    Casillero destino;
    int k;
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
}

#endif /* PROBLEMA_3_H */