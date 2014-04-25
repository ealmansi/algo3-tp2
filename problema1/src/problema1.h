#include <string>
#include <utility>
#include <vector>

struct Problema1 {

  struct Entrada {
    int cantCartas;
    std::vector<int> cartas;
  };

  struct Salida {
    int cantTurnos, puntajeJ1, puntajeJ2;
    std::vector<std::pair<std::string,int> > turnos;
  };

  Entrada leerEntrada();
  void escribirSalida(const Salida& s);
  Salida resolver(const Entrada& e);
};