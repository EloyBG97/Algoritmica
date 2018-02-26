#include <funciones.h>
#include <set>
#include <cstdlib>

using namespace std;

double uniforme() {
	int t = rand();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
}

template<int K=1>
double gananciaOptima(const double *clientes,  const unsigned short &n_clientes) {
	multiset<double,less<double>> tiempos;
	multiset<double,less<double>>::const_iterator it1;
	double ganancia = 0;
	double *aux;
	
	aux = new double[K];
	
	for(unsigned short i=0;i<n_clientes;++i)
		tiempos.insert(clientes[i]);

	it1=tiempos.begin();

	while(it1 != tiempos.end()){
		for (unsigned short i=0 ; i<K && it1 != tiempos.end() ; ++i){
			aux[i] += *it1;
			it1++;
			ganancia += 1/(aux[i]);
		}
	}

	return ganancia;
}
