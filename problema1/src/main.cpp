#include "problema1.h"

using namespace Problema1;

int main(int argc, char const *argv[])
{
  Entrada e = leerEntrada();
  Salida s = resolver(e);
  escribirSalida(s);

  return 0;
}