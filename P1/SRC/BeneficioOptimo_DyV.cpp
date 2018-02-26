
/** 
* @author Eloy Bedia García
* @date 18/03/2017
* @file BeneficioOptimo_DyV.cpp
*/

#include <iostream>
#include <utility>
#include <chrono>
#include <cassert>
#include <gen_vector.h>

/** @define Si se define, la salida del programa será mas completa.
*/
#define PRINT_ALL

using namespace std::chrono;
using namespace std;


/*******************************************DEFINICION DE FUNCIONES*************************************************************************************/

/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio (Algoritmo DyV).
*	       Cada posicion de @a v representa un dia. Los dias van desde 0 a @a tam - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param tam: Es el tamaño del rango de dias.
*	@pre @a v no puede tener el valor NULL. 
*		 @a tam debe tener valores positivos (@a tam > 0).
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
inline pair<unsigned int,unsigned int> beneficioMax_dyv(const int* v, const unsigned int &tam);

/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio en una parte del vector.
*		   Posteriormente se unen todas las soluciones para dar solución al problema original. Cada posicion de @a v representa un dia. 
*		   Los dias van desde @a ini a @a fin - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param ini: La posición en la que emieza la parte del vector que se analiza.
*	@param fin: La posición en la que termina la parte del vector que se analiza.
*	@pre @a v no puede tener el valor NULL. 
*		 @a ini debe tener valores positivos (@a ini > 0). 
*		 @a fin debe tener valores positivos (@a fin > 0). 
*		 @a ini < @a fin.
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
pair<unsigned int,unsigned int> beneficioMax_lims(const int* v, const unsigned int &ini, const unsigned int &fin);

/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio (Algoritmo Iterativo).
*	       Cada posicion de @a v representa un dia. Los dias van desde 0 a @a tam - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param ini: La posición en la que emieza la parte del vector que se analiza.
*	@param fin: La posición en la que termina la parte del vector que se analiza.
*	@pre @a v no puede tener el valor NULL. 
*		 @a ini debe tener valores positivos (@a ini > 0). 
*		 @a fin debe tener valores positivos (@a fin > 0). 
*		 @a ini < @a fin.
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
pair<unsigned int,unsigned int> beneficioMax_it(const int* v, const unsigned int &ini, const unsigned int &fin);


/*******************************************PROGRAMA PRINCIPAL****************************************************************************************/


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
	int v[] = {3, 7, 5, 2, 3, 8, 12, 13, 3, 5, 9, 15, 1};
	
	//generarVector<int>(v,N);
	assert(v);


	tantes = high_resolution_clock::now();
	dias = beneficioMax_dyv(v,N);
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


/*******************************************IMPLEMENTACION DE FUNCIONES*********************************************************************************/


/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio (Algoritmo DyV).
*	       Cada posicion de @a v representa un dia. Los dias van desde 0 a @a tam - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param tam: Es el tamaño del rango de dias.
*	@pre @a v no puede tener el valor NULL.
*		 @a tam debe tener valores positivos (@a tam > 0)
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
inline pair<unsigned int,unsigned int> beneficioMax_dyv(const int* v, const unsigned int &tam) {
	return beneficioMax_lims(v,0,tam);
}

/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio en una parte del vector.
*		   Posteriormente se unen todas las soluciones para dar solución al problema original. Cada posicion de @a v representa un dia. 
*		   Los dias van desde @a ini a @a fin - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param ini: La posición en la que emieza la parte del vector que se analiza.
*	@param fin: La posición en la que termina la parte del vector que se analiza.
*	@pre @a v no puede tener el valor NULL. 
*		 @a ini debe tener valores positivos (@a ini > 0). 
*		 @a fin debe tener valores positivos (@a fin > 0). 
*		 @a ini < @a fin.
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
pair<unsigned int,unsigned int> beneficioMax_lims(const int* v, const unsigned int &ini, const unsigned int &fin) {
	const unsigned int UMBRAL = 3;

	if(fin-ini<UMBRAL)
		return beneficioMax_it(v,ini,fin);

	else {
		unsigned int med = (fin+ini)/2;

		pair<unsigned int,unsigned int> b1 = beneficioMax_lims(v,ini,med);
		pair<unsigned int,unsigned int> b2 = beneficioMax_lims(v,med,fin);

		pair<unsigned int,unsigned int> b_max;

		//BENEFICIO = V.VENTA-V.COMPRA
		/*b_max = (v[b1.second]-v[b1.first] < v[b2.second]-v[b2.first])?b2:b1;
		
		if(v[b2.second]-v[b1.first] > v[b_max.second]-v[b_max.first]) {
			b_max.first = b1.first;
			b_max.second = b2.second;
		}*/

		return b_max;
	}
}

/** @brief Calcula los dias en los que hay que vender y comprar acciones de forma que se obtenga el máximo beneficio (Algoritmo Iterativo).
*	       Cada posicion de @a v representa un dia. Los dias van desde 0 a @a tam - 1
*	@param v: Vector que representa un intervalo de dias, con sus respectivos valores de bolsa.
*	@param ini: La posición en la que emieza la parte del vector que se analiza.
*	@param fin: La posición en la que termina la parte del vector que se analiza.
*	@pre @a v no puede tener el valor NULL. 
*		 @a ini debe tener valores positivos (@a ini > 0). 
*		 @a fin debe tener valores positivos (@a fin > 0). 
*		 @a ini < @a fin. 
*	@post Siendo c el dia de compra y v el dia de venta. c < v
*	@return Devuelve una estructura de datos tipo 'pair'. El primer elemento del 'pair' es el dia de compra y el segundo elemento es el dia de la venta.
*/
pair<unsigned int,unsigned int> beneficioMax_it(const int* v, const unsigned int &ini, const unsigned int &fin) {
	unsigned int compra = ini;
	unsigned int venta = ini+1;
	
	for(unsigned int i=ini+1; i<fin;++i)
		for(unsigned int j=i+1; j<fin;++j)
			if(v[j]-v[i] > v[venta]-v[compra]) {
				venta = j;
				compra = i;
			}

	return pair<unsigned int,unsigned int>(compra,venta);
}


