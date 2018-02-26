#ifndef _TDASOLUCION_H_
#define _TDASOLUCION_H_

#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class ViajanteComercio {
	private:
		struct nodo {
			double coste;
			vector<unsigned int> recorrido;
			
			bool operator<(const nodo &n) const;
		}
		
	public:
		ViajanteComercio(const string &rt);
		~ViajanteComercio();
		
		void mostrarMatrices() const;

		



	private: 
		double **matriz_distancias;
		double **ciudades;
		unsigned int dim;
		
		vector<unsigned int> solucion;
	
	
		void escribirMatriz(const string &rt);
		inline unsigned int distanciaEuclidea(const double &x1, const double &y1, const double &x2, const double &y2) const;
		double distanciaRecorrida() const;
		double costoPosible(const nodo &n);	
						

};

#endif
