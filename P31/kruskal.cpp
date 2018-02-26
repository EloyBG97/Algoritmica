#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

//Opciones de configuración.
//#define mostrarOrden
//#define escribirFichero

/**************************************************
**	Krustal (Grafo):
**		crear conjunto de seleccionados vacío
**		inicializar estructura union-find
**		ordenar las aristas del grafo por peso ascendente
**	
**		para cada arista a que une dos vertices
**			si los vertices no estan en la misma componente
**				agregar arista a seleccionados
**				unir ambas componentes
***************************************************/

struct arista{
	int nodo_orig;
	int nodo_dest;
	int costo;
	
	arista(){}
	
	arista(int o, int d, int c){
		nodo_orig = o;
		nodo_dest = d;
		costo = c;
	}
	
	bool operator<(const arista &a) const{
		return costo < a.costo;
	}
};

int *padres;

void escribirMatriz(const string &rt, double** &m, double** &mIni, const unsigned short int &dim);
inline int distanciaEuclidea(const double &x1, const double &y1, const double &x2, const double &y2);
double distanciaRecorrida(double** const &m, const vector<unsigned int> &v, const unsigned short int &dim);
int find(int n);
int unir(int n1, int n2);
vector<unsigned int> Kruskal(int v, vector<arista> &candidatas);

main(int argc, char** argv){
	
	if (argc != 2){
		cerr << "Uso: " << argv[0] << " ./ruta_al_fichero_de_ciudades" << endl;
		return -1;
	}
	
	string ruta, aux;
	ifstream leer;
	int dimension, distancia;
	vector<unsigned int> vectorResultado;
	double **distancias;
	double **ciudades;
	vector<arista> aristas;
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;
	int x1, y1, x2, y2;
	
	ruta = argv[1];
	
	leer.open(ruta);
	leer >> aux; 
	leer >> dimension;
	leer.close();
	
	distancias = new double *[dimension];
	ciudades = new double *[dimension];
	
	for (int i = 0 ; i < dimension ; i++){
		distancias[i] = new double[dimension];
		ciudades[i] = new double[3];
	}
	
	//leer ciudades del archivo
	escribirMatriz(ruta, distancias, ciudades, dimension);
	
	//calcular las distancias
	for (int i = 0 ; i < dimension ; i++){		
		for (int j = 0 ; j < dimension ; j++){
			x1 = ciudades[i][1]; y1 = ciudades[i][2];
			x2 = ciudades[j][1]; y2 = ciudades[j][2];
			
			distancias[i][j] = distanciaEuclidea(x1,y1,x2,y2);
		}
	}
	
	//crear aristas
	for (int i = 0 ; i < dimension ; i++){
		for (int j = i+1 ; j < dimension ; j++){
			arista aux(ciudades[i][0], ciudades[j][0], distancias[i][j]);
		
			aristas.push_back(aux);
		}
	}
	
	tantes = high_resolution_clock::now();
	
	vectorResultado = Kruskal(dimension,aristas);
	
	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues-tantes);
	
	distancia = distanciaRecorrida(distancias, vectorResultado, dimension);

	#ifdef escribirFichero
		ofstream escribirResultado;
		escribirResultado.open("salida.dat");
		for (int i=0; i<dimension; i++){
			escribirResultado << vectorResultado[i] << " ";
			escribirResultado << ciudades[vectorResultado[i]][1] << " ";
			escribirResultado << ciudades[vectorResultado[i]][2] << endl;
		}
		escribirResultado.close();
	#endif

	cout << "Distancia recorrida: " << distancia << "km." << endl;
	cout << "Tiempo empleado: " << transcurrido.count() << "s." << endl;
	
	#ifdef mostrarOrden
		for (int i = 0 ; i < dimension ; i++) 
			cout << "c[" << i+1 << "]=" << vectorResultado[i] << endl;
	#endif

	delete [] padres;
	
	for (int i = 0 ; i < dimension ; i++){
		delete [] ciudades[i];
		delete [] distancias[i];
	}
	
	delete [] ciudades;
	delete [] distancias;

	return 0;
}

void escribirMatriz(const string &rt, double** &m, double** &mIni, const unsigned short int &dim){
	ifstream fich; string aux;
	fich.open(rt);
	fich >> aux; fich >> aux;
	for (int i=0; i<dim; i++){
		for (int j=0; j<3; j++) fich >> mIni[i][j];
	}
	fich.close();

	for (int i=0; i<dim; i++){
		for (int j=i+1; j<dim; j++){
			m[i][j] = distanciaEuclidea(mIni[i][1], mIni[j][1], mIni[i][2], mIni[j][2]);
		}
	}
}

double distanciaRecorrida(double** const &m, const vector<unsigned int> &v, const unsigned short int &dim){
	double distancia = 0;
	for (int i=0; i<(dim-1); i++){
		distancia = distancia + m[v[i]][v[i+1]];
	}
	distancia = distancia + m[0][dim-1];
	return distancia;
}

inline int distanciaEuclidea(const double &x1, const double &y1, const double &x2, const double &y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int find(int n){
	if (padres[n] == n)
		return n;
	else
		return padres[n] = find(padres[n]);
}

int unir(int n1, int n2){
	int x1 = find(n1);
	int x2 = find(n2);
	
	padres[x1] = x2;
}

vector<unsigned int> Kruskal(int v, vector<arista> &candidatas){
	vector <unsigned int> ruta;
	arista seleccionadas[v];
	int origen, destino;
	int cont = 0;
	int n1, n2;
	
	padres = new int[v];
	for (int i = 0 ; i < v ; i++)
		padres[i] = i;
	
	sort(candidatas.begin(), candidatas.end());
	
	for (int i = 0 ; i < candidatas.size() ; i++){
		origen = candidatas[i].nodo_orig;
		destino = candidatas[i].nodo_dest;
		
		if ( find(n1) != find(n2) ){
			unir( origen, destino );
			seleccionadas[cont++] = candidatas[i];
		}
	}
	
	for (int i = 0 ; i < cont ; i++)
		ruta.push_back(seleccionadas[i].nodo_orig);
	
	return ruta;
}
