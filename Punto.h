#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;

class Punto
{
	private:
		double p;
	public:
		Punto();
		Punto(double);
		~Punto();
		void setP(double);
		double getP();
};

#endif
