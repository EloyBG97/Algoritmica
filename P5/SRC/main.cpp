#include "TDASolucion.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	if (argc < 2){
		cerr << "Uso " << argv[0] << "<ruta_archivo>";
		return 1;
	}
	
	ViajanteComercio vc(argv[1]);
}
