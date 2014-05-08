#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include "problema1.h"
#include "utils.h"

using namespace std;
using namespace Problema1;

#define CANT_MEDICIONES_POR_N 5

struct Medicion
{
  Medicion(int n, int tiempo) : n(n), tiempo(tiempo) {}
  int n;
  int tiempo;
};

/*    Funciones generadoras    *    *    *    *    *    *    *    *    *    *    *    *    *    */

Entrada generar_instancia_aleatoria(int n)
{
  Entrada e;
  e.cantCartas = n;
  for (int i = 0; i < n; ++i)
    e.cartas.push_back(rand() - rand());
  return e;
}

/*    main *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    */

vector<Medicion> tomar_mediciones(int n_max, Entrada (*generar_instancia)(int))
{
  timespec inicio, fin;
  vector<vector<int> > mediciones_por_n(n_max, vector<int>(CANT_MEDICIONES_POR_N, -1));

  for (int i = 0; i < CANT_MEDICIONES_POR_N; ++i)
  {
    srand(10);
    cout << (i + 1) << "/" << CANT_MEDICIONES_POR_N << endl;
    for (int n = 1; n <= n_max; ++n)
    {
      Entrada e = generar_instancia(n);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
      resolver(e);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);
      mediciones_por_n[n - 1][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
    }
  }

  int mediana;
  vector<Medicion> mediciones;
  for (int n = 1; n <= n_max; ++n)
  {
    sort(mediciones_por_n[n - 1].begin(), mediciones_por_n[n - 1].end());
    mediana = mediciones_por_n[n - 1][CANT_MEDICIONES_POR_N / 2];
    mediciones.push_back(Medicion(n, mediana));
  }

  return mediciones;
}

void escribir_datos(vector<Medicion> &mediciones, string nombre_archivo_salida)
{
  string path_archivo_salida = "./csv/" + nombre_archivo_salida;
  ofstream archivo_salida;
  archivo_salida.open(path_archivo_salida.c_str());
  if(!archivo_salida) { cout << "No se pudo abrir el archivo: " << path_archivo_salida << endl; exit(-1); }

  archivo_salida << "\"n\"" << "," << "\"tiempo (ns)\"" << endl;
  for (vector<Medicion>::const_iterator i = mediciones.begin(); i != mediciones.end(); ++i)
    archivo_salida << i->n << "," << i->tiempo << endl;

  archivo_salida.close();
}

void imprimir_modo_de_uso(string path_al_ejecutable)
{
  cout << "Modo de uso: " << path_al_ejecutable << " <valor_max>" << endl;
  cout << "Ejemplo:" << endl;
  cout << "\t" << path_al_ejecutable << " 200" << endl;
}

int main(int argc, char const *argv[])
{
  if(argc != 2)
  {
    imprimir_modo_de_uso(argv[0]);
    return 0;
  }

  int n = atoi(argv[1]);

  vector<Medicion> ms = tomar_mediciones(n, generar_instancia_aleatoria);
  escribir_datos(ms, "instancia_aleatoria.csv");

  return 0;
}