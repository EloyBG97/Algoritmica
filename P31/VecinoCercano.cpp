#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cfloat>
using namespace std;
using namespace std::chrono;

//Opciones de configuración.
//#define mostrarOrden
//#define escribirFichero
#define grafica

void escribirMatriz(const string &rt, float** &m, float** &mIni, const unsigned short int &dim);
inline float distanciaEuclidea(const float &x1, const float &x2, const float &y1, const float &y2);
float distanciaRecorrida(float** const &m, const vector<unsigned int> &v, const unsigned short int &dim);
void borrarMatrizDinamica(float** &m, const unsigned short int &dim);
vector<unsigned int> VecinoCercano(float** const &m, const unsigned short &dim);

main(int argc, char** argv){
	if (argc != 2){
		cerr << "Necesario introducir solo la ruta del fichero." << endl;
		return -1;
	}
	string ruta = argv[1];
	ifstream leerDimension;
	leerDimension.open(ruta);
	unsigned short int dimension; string aux;
	leerDimension >> aux; leerDimension >> dimension;
	leerDimension.close();
	
	vector<unsigned int> vectorResultado;

	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	float **matrizDistancias = new float *[dimension];
	for (int i=0; i<dimension; i++) matrizDistancias[i] = new float[dimension];
	float **matrizDatosIniciales = new float *[dimension];
	for (int i=0; i<dimension; i++) matrizDatosIniciales[i] = new float[3];
	
	escribirMatriz(ruta, matrizDistancias, matrizDatosIniciales, dimension);
	

	tantes = high_resolution_clock::now();
	vectorResultado = VecinoCercano(matrizDistancias,dimension);
	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues-tantes);
	int disRec = distanciaRecorrida(matrizDistancias, vectorResultado, dimension);

	#ifdef escribirFichero
		ofstream escribirResultado;
		escribirResultado.open("salida.dat");
		for (int i=0; i<dimension; i++){
			escribirResultado << vectorResultado[i] << " ";
			escribirResultado << matrizDatosIniciales[vectorResultado[i]][1] << " ";
			escribirResultado << matrizDatosIniciales[vectorResultado[i]][2] << endl;
		}
		escribirResultado.close();
	#endif
	
	#ifdef mostrarOrden
		for (int i=0; i<dimension;i++) cout << "c[" << i+1 << "]=" << vectorResultado[i] << endl;
	#endif
	
	#ifdef grafica
		cout << dimension << " " << transcurrido.count()  << endl;
	#endif
	
	borrarMatrizDinamica(matrizDistancias, dimension);
	borrarMatrizDinamica(matrizDatosIniciales, dimension);

	return 0;
}

void escribirMatriz(const string &rt, float** &m, float** &mIni, const unsigned short int &dim){
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

inline float distanciaEuclidea(const float &x1, const float &x2, const float &y1, const float &y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

float distanciaRecorrida(float** const &m, const vector<unsigned int> &v, const unsigned short int &dim){
	float distancia = 0;
	for (int i=0; i<(dim-1); i++){
		distancia = distancia + m[v[i]][v[i+1]];
	}
	distancia = distancia + m[0][v[dim]];
	return distancia;
}

void borrarMatrizDinamica(float** &m, const unsigned short int &dim){
	for (int i=0; i<dim; i++) 
		delete [] m[i];
	delete m;
}

vector<unsigned int> VecinoCercano(float** const &m, const unsigned short &dim){
	vector <unsigned int> ruta;
	float dis_min;
	unsigned int c;
	
	ruta.push_back(0); //Incluimos la ciudad de origen
	
	for(unsigned int i = 1; i < dim ; ++i) {
		dis_min = FLT_MAX;
		for(unsigned int j = 1; j<dim; ++j) {
			if(j > ruta[ruta.size()-1] && m[ruta[ruta.size()-1]][j] < dis_min && find(ruta.crbegin(),ruta.crend(),j) == ruta.crend()) {
				dis_min = m[ruta[ruta.size()-1]][j];
				c = j;
			}
		
			else if(j < ruta[ruta.size()-1] && m[j][ruta[ruta.size()-1]] < dis_min && find(ruta.crbegin(),ruta.crend(),j) == ruta.crend()) {
				dis_min = m[j][ruta[ruta.size()-1]];
				c = j;
			}

		}
	
		ruta.push_back(c);
	}
	
	ruta.push_back(0);
	
	return ruta;
}
