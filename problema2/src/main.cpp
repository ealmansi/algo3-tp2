#include "problema2.h"

using namespace Problema2;

int main(){
	Entrada e = leerEntrada();
	Salida s = resolver(e);
	imprimoSalida(s);
	return 0;
}
