#ifndef _CIUDAD_H_
#define _CIUDAD_H_

class Ciudad {
	private:
		unsigned int x,y;
		
	public:
		Ciudad();
		Ciudad(const unsigned int &x,const unsigned int &y);
		Ciudad(const Ciudad &c);
		
		Ciudad& operator(const Ciudad &c);
		
		unsigned int distancia(const Ciudad &c) const;
};

#endif
