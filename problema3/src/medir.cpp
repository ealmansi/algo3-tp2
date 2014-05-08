#include "problema3.h"
#include "utils.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;
using namespace Problema3;

#define CANT_MEDICIONES_POR_N 5

struct Medicion
{
  Medicion(int n, int tiempo) : n(n), tiempo(tiempo) {}
  int n;
  int tiempo;
};

/*    Funciones generadoras    *    *    *    *    *    *    *    *    *    *    *    *    *    */

template<int k>
Entrada generar_instancia_p_1_k_fijo(int n)
{
  Entrada e;
  int p = 1;
  e.n = n;
  e.origen = Casillero(1, 1, k);
  e.destino = Casillero(n, n, 0);
  e.k = k;
  e.tablero = vector< vector < int > >(e.n + 1, vector < int >(e.n + 1, p));

  return e;
}

template<int n>
Entrada generar_instancia_p_1_n_fijo(int k)
{
  Entrada e;
  int p = 1;
  e.n = n;
  e.origen = Casillero(1, 1, k);
  e.destino = Casillero(n, n, 0);
  e.k = k;
  e.tablero = vector< vector < int > >(e.n + 1, vector < int >(e.n + 1, p));

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
      mediciones_por_n[n - 1][i] = (fin.tv_sec - inicio.tv_sec) * 1e6 + (fin.tv_nsec - inicio.tv_nsec) * 1e-3;
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

void escribir_datos(vector<Medicion> &mediciones, string variable, string nombre_archivo_salida)
{
  string path_archivo_salida = "./csv/" + nombre_archivo_salida;
  ofstream archivo_salida;
  archivo_salida.open(path_archivo_salida.c_str());
  if(!archivo_salida) { cout << "No se pudo abrir el archivo: " << path_archivo_salida << endl; exit(-1); }

  archivo_salida << "\"" << variable << "\"" << "," << "\"tiempo (us)\"" << endl;
  for (vector<Medicion>::const_iterator i = mediciones.begin(); i != mediciones.end(); ++i)
    archivo_salida << i->n << "," << i->tiempo << endl;

  archivo_salida.close();
}

void imprimir_modo_de_uso(string path_al_ejecutable)
{
  cout << "Modo de uso: " << path_al_ejecutable << " <variable> <valor_max>" << endl;
  cout << "Ejemplos:" << endl;
  cout << "\t" << path_al_ejecutable << " n 50" << endl;
  cout << "\t" << path_al_ejecutable << " k 300" << endl;
}

int main(int argc, char const *argv[])
{
  if(argc != 3)
  {
    imprimir_modo_de_uso(argv[0]);
    return 0;
  }

  string variable = string(argv[1]);
  int valor_max = atoi(argv[2]);

  vector<Medicion> ms;
  if(variable == "n")
  {
    cout << "n_max " << valor_max << ", k " << 0 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_k_fijo<0>);
    escribir_datos(ms, variable, "instancia_p_1_k_0.csv");

    cout << "n_max " << valor_max << ", k " << 10 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_k_fijo<10>);
    escribir_datos(ms, variable, "instancia_p_1_k_10.csv");

    cout << "n_max " << valor_max << ", k " << 20 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_k_fijo<20>);
    escribir_datos(ms, variable, "instancia_p_1_k_20.csv");

    cout << "n_max " << valor_max << ", k " << 30 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_k_fijo<30>);
    escribir_datos(ms, variable, "instancia_p_1_k_30.csv");

    cout << "n_max " << valor_max << ", k " << 40 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_k_fijo<40>);
    escribir_datos(ms, variable, "instancia_p_1_k_40.csv");

  }
  else if(variable == "k")
  {
    cout << "k_max " << valor_max << ", n " << 5 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_n_fijo<5>);
    escribir_datos(ms, variable, "instancia_p_1_n_5.csv");

    cout << "k_max " << valor_max << ", n " << 10 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_n_fijo<10>);
    escribir_datos(ms, variable, "instancia_p_1_n_10.csv");

    cout << "k_max " << valor_max << ", n " << 15 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_n_fijo<15>);
    escribir_datos(ms, variable, "instancia_p_1_n_15.csv");

    cout << "k_max " << valor_max << ", n " << 20 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_n_fijo<20>);
    escribir_datos(ms, variable, "instancia_p_1_n_20.csv");

    cout << "k_max " << valor_max << ", n " << 25 << endl;
    ms = tomar_mediciones(valor_max, generar_instancia_p_1_n_fijo<25>);
    escribir_datos(ms, variable, "instancia_p_1_n_25.csv");
  }

  return 0;
}