#include "problema1.h"
#include "utils.h"
#include <iostream>
#include <climits>

using namespace Problema1;
using namespace std;

Entrada Problema1::leerEntrada()
{
  Entrada e;
  cin >> e.cantCartas;
  for (int i = 0; i < e.cantCartas; ++i)
  {
    int carta;
    cin >> carta;
    e.cartas.push_back(carta);
  }

  return e;
}

void Problema1::escribirSalida(const Salida& s)
{
  cout << s.cantTurnos << " ";
  cout << s.puntajeJ1 << " ";
  cout << s.puntajeJ2 << endl;
  vector<pair<string,int> >::const_iterator i;
  for (i = s.turnos.begin(); i != s.turnos.end(); ++i)
    cout << i->first << " " << i->second << endl;
}

struct Subproblema {
  Subproblema()
    : iSiguiente(-1), jSiguiente(-1), cantPuntos(-1) {}
  Subproblema(int iSiguiente, int jSiguiente, int cantPuntos)
    : iSiguiente(iSiguiente), jSiguiente(jSiguiente), cantPuntos(cantPuntos) {}

  int iSiguiente, jSiguiente, cantPuntos;
};

vector<int> computarSumasParciales(const Entrada& e)
{
  vector<int> sumasParciales(e.cantCartas);
  for (int i = 0; i < e.cantCartas; ++i)
    sumasParciales[i] = (i == 0) ? e.cartas[0] : sumasParciales[i - 1] + e.cartas[i];

  return sumasParciales;
}

Salida Problema1::resolver(const Entrada& e)
{
  vector<int> sumasParciales = computarSumasParciales(e);

  vector<vector<Subproblema> > msp(e.cantCartas, vector<Subproblema>(e.cantCartas));
  for (int j = 0; j < e.cantCartas; ++j)
  {
    msp[j][j].cantPuntos = e.cartas[j];

    for (int i = j - 1; 0 <= i; --i)
    {
      int iSiguiente, jSiguiente, minCantPuntos = INT_MAX;

      for (int k = 1; k <= j - i; ++k)
      {
        if(msp[i + k][j].cantPuntos < minCantPuntos)
        {
          iSiguiente = i + k;
          jSiguiente = j;
          minCantPuntos = msp[i + k][j].cantPuntos;
        }
        if(msp[i][j - k].cantPuntos < minCantPuntos)
        {
          iSiguiente = i;
          jSiguiente = j - k;
          minCantPuntos = msp[i][j - k].cantPuntos;
        }
      }

      int sumaRango = sumasParciales[j] - ((i == 0) ? 0 : sumasParciales[i - 1]);
      if(0 <= minCantPuntos)
        msp[i][j] = Subproblema(-1, -1, sumaRango);
      else
        msp[i][j] = Subproblema(iSiguiente, jSiguiente, sumaRango - minCantPuntos);
    }
  }

  Salida s;

  int i = 0, j = e.cantCartas - 1;
  Subproblema turno = msp[i][j];
  while(turno.iSiguiente != -1 and turno.jSiguiente != -1)
  {
    if(0 < turno.iSiguiente - i)
      s.turnos.push_back(make_pair("izq", turno.iSiguiente - i));
    else
      s.turnos.push_back(make_pair("der", j - turno.jSiguiente));

    i = turno.iSiguiente, j = turno.jSiguiente;
    turno = msp[i][j];
  }
  s.turnos.push_back(make_pair("izq", j - i + 1));

  s.cantTurnos = s.turnos.size();

  if (s.cantTurnos % 2 == 0)
  {
    s.puntajeJ1 = msp[0][e.cantCartas - 1].cantPuntos;
    s.puntajeJ2 = sumasParciales[e.cantCartas - 1] - s.puntajeJ1;
  }
  else
  {
    s.puntajeJ2 = msp[0][e.cantCartas - 1].cantPuntos;
    s.puntajeJ1 = sumasParciales[e.cantCartas - 1] - s.puntajeJ2;
  }

  return s;
}
