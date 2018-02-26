/** @brief Generador de numeros aleatorios con distribucion de probabilidad 
*		   uniforme.
*	@return Devuelve un numero aleatorio
*/
double uniforme() {
	int t = rand();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
}

/** @brief Genera un vector, @a v,  de @a TAM posiciones con valores   	
*		   aleatorios dentro del intervalo (0,500)
*	@param v Puntero a partir del cual se generará el vector
*	@param TAM Tamaño del vector
*	@return Devuelve por referencia el vector generado
*/
template <typename T>
void generarVector(T* &v, const unsigned int &TAM) {
		v = new T[TAM];
		srand(time(0));
	
	for (unsigned int j=0; j<TAM; j++) {
		double u=uniforme();
		v[j]= (T) (1+500*u);
	}

}
