#include <algorithm>
vector <unsigned int> VecinoCercano(const unsigned int **m, const unsigned int &dim) {
	
	vector <unsigned int> ruta;
	unsigned int dis_min;
	unsigned int c;
	
	ruta.push_back(0); //Incluimos la ciudad de origen
	
	
	dis_min = MAX_INT<<1;
	
	for(unsigned int i = 0; i < dim ; ++i) {
		for(unsigned int j = ruta[ruta.size()-1] + 1; j<dim; ++j) {
			if(j > ruta[ruta.size()-1] && m[ruta[ruta.size()-1]][j] < dis_min && find(ruta.cbegin(),find.ruta.cend(),j) == ruta.cend()) {
				dis_min = m[ruta[ruta.size()-1]][j];
				c = i;
			}
		
			else if((j < ruta[ruta.size()-1] && m[j][ruta[ruta.size()-1]] < dis_min && find(ruta.cbegin(),find.ruta.cend(),j) == ruta.cend()) {
				dis_min = m[j][ruta[ruta.size()-1]];
				c = j;
			}
			
		}
	
		ruta.push_back(c);
	}
	
	ruta.push_back(0);
	
	return ruta;
}
		
