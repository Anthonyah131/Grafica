#ifndef GRAFICA_H
#define GRAFICA_H
#include <graphics.h>
#include "Punto.h"

class Grafica
{
	private:
		Punto x[25];
		Punto y[25];
		double dis;
		
	public:
		Grafica();
		~Grafica();
		void setDis(double);
		double getDis();
		void pintarPlano();
		void limpiarVector();
		void ingresarPunto(double, double);
		void pintarPunto();
		double laGrange(double, int);
		void ordenarBurbuja();
		void trazado(double);
};

#endif
