/**
* @author Raimundo Pérez Rubio
* @date 24/3/2017
* @file BeneficioOptimo_It.cpp
* @brief El objetivo es desarrollar el programa que a primera vista parece el
  más sencillo de implementar para resolver el problema de inversión en bolsa,
  sin utilizar "divide y vencerás" ni ninguna otra técnica especial. Se recibe
  como entrada el tamaño del vector, cuyos índices representan los días de
  compra-venta, y que contiene el valor de las acciones en cada uno de ellos.
  A partir de estos datos se calcula entre qué dos días el beneficio es mayor
  y se devuelven dichos días (día de compra y de venta), la ganancia y el
  tiempo de ejecución del algoritmo.
*/

#include <iostream>
#include <utility>
#include <chrono>
#include <cassert>
#include <gen_vector.h>

using namespace std;
using namespace std::chrono;

#define PRINT_ALL
pair<int,int> mayorBeneficio(const int *v, const int &tam);

int main(int argc, char **argv) {
/*
	if (argc != 2)   {
   		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
	}
	
	else if (atoi(argv[1]) < 2) {
		cerr << "El numero elementos debe ser mayor que 1" << endl;
    	return -1;
    }
*/

	const unsigned int N = 13;

	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	pair<unsigned int,unsigned int> dias;
	int v[]={3, 7, 5, 2, 3, 8, 12, 13, 3, 5, 9, 15, 1};
	
	//generarVector<int>(v,N);
	assert(v);

	tantes = high_resolution_clock::now();
	dias = mayorBeneficio(v,N);
	tdespues = high_resolution_clock::now();

	transcurrido = duration_cast<duration<double>>(tdespues-tantes);

	#ifdef PRINT_ALL
		cout << "Mejor dia para comprar: " << dias.first+1 << endl;
		cout << "Mejor dia para vender: " << dias.second+1 << endl;
		cout << "Beneficio obtenido: " << v[dias.second] - v[dias.first] << endl;
		cout << "Tiempo transcurrido: " << transcurrido.count() << endl;
	#else
		cout << N << " " << transcurrido.count() << endl;
	#endif

	return 0;
}


/**
* @brief Función que recibe el vector de los días y su tamaño, compara el valor
  de la ganancia entre cada día y cada uno de los siguientes a él y devuelve el
  par de días que ofrecen la mayor ganancia.
* @param v Vector de los días.
* @param tam Tamaño del vector de los días.
* @return Par de días elegidos como día de compra y de venta.
*/
pair<int,int> mayorBeneficio(const int *v, const int &tam){
	int diaCompra = 0;
	int diaVenta = 1;
	int maxBet = v[1]-v[0];

	for (int i=1; i<tam; i++){
		for (int j=i+1; j<tam; j++){
			if (v[j]-v[i]>maxBet){
				maxBet = v[j]-v[i];
				diaCompra = i;
				diaVenta = j;
			}
		}
	}
	return pair<int,int>(diaCompra,diaVenta);
}
