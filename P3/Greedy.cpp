#include <iostream>
#include <cstdlib>
#include <funciones.h>

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));

	const int K  = 1;

	if(argc != 2) {
		cerr << "Uso: " << argv[0] << " <numero_clientes>" << endl;
		return EXIT_FAILURE;
	}

	unsigned short n_clientes = atoi(argv[1]);
	double *clientes = new double [n_clientes];
	double ganancia;

	for(unsigned short i=0; i<n_clientes; ++i) {
		clientes[i]=uniforme();
		cout << "Cliente " << i << ": " << clientes[i] << "s " << endl;
	}

	ganancia = gananciaOptima<K>(clientes,n_clientes);

	cout << "\nLa ganancia optima generada es: " << ganancia << endl;

	return EXIT_SUCCESS;
}
