#include "problema1.h"
#include "utils.h"
#include <iostream>

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

Salida Problema1::resolver(const Entrada& e)
{
  Salida s;

  

  
  print("Antes del return", endl);
  die();
  return s;
}