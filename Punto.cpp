#include "Punto.h"

Punto::Punto(){
	p = 0;
}
Punto::Punto(double _p){
	p = _p;
}
Punto::~Punto(){
}
	//set y get
void Punto::setP(double _p){
	p = _p;
}
double Punto::getP(){
	return p;
}
