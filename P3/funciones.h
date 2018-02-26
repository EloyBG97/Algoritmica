#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

double uniforme();

template<int K=1>
double gananciaOptima(const double *clientes,  const unsigned short &n_clientes);

#include <funciones.hxx>
#endif
