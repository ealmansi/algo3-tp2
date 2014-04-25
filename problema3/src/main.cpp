#include "problema3.h"

using namespace Problema3;

int main(){
	Entrada e = leerEntrada();
	cout << "lei" << endl;
	Salida s = resolver(e);
	cout << "resolei" << endl;
	imprimoSalida(s);
	cout << "imprilei" << endl;
	return 0;
}
