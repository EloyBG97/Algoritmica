#include "TDASolucion.h"
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>
#include <iostream>



using namespace std;

bool ViajanteComercio::nodo::operator<(const nodo &n) const {
	if(coste > n.coste)
		return false;
		
	else if(coste == n.coste)
		return (recorrido.size() > n.recorrido.size());
		
	else
		return true;
}


//CONSTRUCTOR
ViajanteComercio::ViajanteComercio(const string &rt)
:solucion(0)
{
	escribirMatriz(rt);
}

//DESTRUCTOR
ViajanteComercio::~ViajanteComercio() {
	unsigned int i;
	
	for(i=0; i < dim; ++i)
		delete [] matriz_distancias[i];
		
	delete [] matriz_distancias;
	
	for(i=0; i < dim; ++i)
		delete [] ciudades[i];
		
	delete [] ciudades;
}

//INICIALIZAR MATRICES
void ViajanteComercio::escribirMatriz(const string &rt){
	unsigned int i,j;
	
	ifstream fich;
	string aux;
	
	fich.open(rt);
	
	fich >> aux; 
	fich >> dim;
	
	ciudades = new double *[dim];
	
	for (i = 0 ; i < dim ; ++i)
		ciudades[i] = new double[3];
		
		
	for (i=0; i<dim; ++i)
		for (j=0; j<3; ++j) 
			fich >> ciudades[i][j];
		
	fich.close();
	
	matriz_distancias = new double *[dim];
	
	for (i = 0 ; i < dim ; ++i)
		matriz_distancias[i] = new double[dim];

	for (i=0; i<dim; ++i)
		for (j=i+1; j<dim; ++j)
			matriz_distancias[i][j] = distanciaEuclidea(ciudades[i][1], ciudades[j][1], ciudades[i][2], ciudades[j][2]);

}

//DISTANCIA DE LA RUTA ESCOGIDA
double ViajanteComercio::distanciaRecorrida() const{
	unsigned int i;
	double distancia = 0;
	unsigned int dim = solucion.size();
	
	for (i = 0 ; i < dim-1 ; ++i)
		distancia += matriz_distancias[solucion[i]][solucion[i+1]];
	
	return distancia;
}

//DISTANCIA ENTRE CIUDADES
inline unsigned int ViajanteComercio::distanciaEuclidea(const double &x1, const double &y1, const double &x2, const double &y2) const{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

//CREA LAS RUTAS
void crearHijos(const nodo &n, priority_queue<nodo> &pq) {
	unsigned int i;
	
	
	for(i=0; i < dim; ++i) {
		if(find(ecorrido.begin(),recorrido.end(),i) == recorrido.end()) {
			nodo hijo
			hijo.recorrido = n.recorrido;
			hijo.recorrido.push_back(i);
			
			hijo.coste = costoPosible
			
			pq.push
		}
	}
		
		
	

//BRANCH & BOUND
void BranchBound();

//COSTE POSIBLE
double costoPosible(const nodo &n) {
	
}	
					
	
