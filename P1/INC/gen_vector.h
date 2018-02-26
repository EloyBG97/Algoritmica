#ifndef _GEN_VECTOR_H_
#define _GEN_VECTOR_H_

#include <ctime>
#include <cstdlib>
#include <climits>

/** @brief Generador de numeros aleatorios con distribucion de probabilidad
*		   uniforme.
*	@return Devuelve un numero aleatorio
*/
double uniforme();

/** @brief Genera un vector, @a v,  de @a TAM posiciones con valores   	
*		   aleatorios dentro del intervalo (0,500)
*	@param v Puntero a partir del cual se generará el vector
*	@param TAM Tamaño del vector
*	@return Devuelve por referencia el vector generado
*/
template <typename T>
void generarVector(T* &v, const unsigned int &TAM);

#include <GenVectores.hxx>
#endif
