#include "problema3.h"
#include "utils.h"

#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using namespace Problema3;

typedef vector< Casillero > Matriz1D;
typedef vector< Matriz1D > Matriz2D;
typedef vector< Matriz2D > Matriz3D;

Entrada Problema3::leerEntrada()
{
  Entrada e;
  
  int n, fo, co, fd, cd , k;
  cin >> n;
  cin >> fo;
  cin >> co;
  cin >> fd;
  cin >> cd;
  cin >> k;
  
  e.n = n;
  e.origen = Casillero(fo, co, k);
  e.destino = Casillero(fd, cd, 0);
  e.k = k;
  
  int tablero_ij;
  e.tablero = vector< vector< int > >(e.n + 1, vector< int >(e.n + 1, -1));
  for (int i = 1; i <= e.n; ++i)
  {
    for (int j = 1; j <= e.n; ++j)
    {
      cin >> tablero_ij;
      e.tablero[i][j] = tablero_ij;
    }
  }

  return e;
}

static const Casillero CASILLERO_INVALIDO(-1,-1,-1);
static list< Casillero > losAdyacentes(const Entrada &e, const Casillero &c);

Salida Problema3::resolver(Entrada &e)
{
  Salida s;

  ///BFS
  Matriz3D predecesor(e.n + 1, Matriz2D(e.n + 1, Matriz1D(e.k + 1, CASILLERO_INVALIDO)));

  queue< Casillero > q;
  q.push(e.origen);
  
  Casillero c;
  while (!q.empty())
  {
    c = q.front();
    q.pop();
    if (c.c == e.destino.c && c.f == e.destino.f)
      break;

    list< Casillero > adyacentes = losAdyacentes(e, c);
    list< Casillero >::const_iterator it = adyacentes.begin();
    for (; it != adyacentes.end(); ++it)
      if (predecesor[it->f][it->c][it->k] == CASILLERO_INVALIDO)
      {
        predecesor[it->f][it->c][it->k] = c;
        q.push(*it);
      }
  }

  for (; c!= e.origen; c = predecesor[c.f][c.c][c.k])
    s.caminoMinimo.push_front(c);
  s.caminoMinimo.push_front(e.origen);
  s.saltos = s.caminoMinimo.size() - 1;

  return s;
}

list< Casillero > losAdyacentes(const Entrada &e, const Casillero &c)
{
  list< Casillero > ady;
  int potencia = e.tablero[c.f][c.c];
  
  ///abajo
  for (int l = 1; (l <= potencia + c.k) && (c.f + l <= e.n); ++l)
    ady.push_back(Casillero(c.f + l, c.c, c.k - max(l - potencia, 0)));

  ///arriba
  for (int l = 1; (l <= potencia + c.k) && (c.f - l >= 1); ++l)
    ady.push_back(Casillero(c.f - l, c.c, c.k - max(l - potencia, 0)));

  ///derecha
  for (int l = 1; (l <= potencia + c.k) && (c.c + l <= e.n); ++l)
    ady.push_back(Casillero(c.f, c.c + l, c.k - max(l - potencia, 0)));

  ///izquierda
  for (int l = 1; (l <= potencia + c.k) && (c.c - l >= 1); ++l)
    ady.push_back(Casillero(c.f, c.c - l, c.k - max(l - potencia, 0)));

  return ady;
}

void Problema3::imprimoSalida(Salida &s)
{
  cout << s.saltos << endl;
  list< Casillero >::iterator itPadre = s.caminoMinimo.begin();
  list< Casillero >::iterator itCamino = s.caminoMinimo.begin();
  ++itCamino;
  for (; itCamino != s.caminoMinimo.end(); ++itCamino)
  {
    cout << itCamino->f << " " << itCamino->c << " " << itPadre->k - itCamino->k << endl;
    ++itPadre;
  }
}
