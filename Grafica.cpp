#include "Grafica.h"

Grafica::Grafica(){
	dis = 0.1;
}
Grafica::~Grafica(){
}

void Grafica::setDis(double _dis)
{
	dis = _dis;
}
double Grafica::getDis()
{
	return dis;
}
void Grafica::pintarPlano(){
	char texto[25];
	for(int i = 0, j = 700; i<=700; i = i+50, j = j-50)
	{
		sprintf(texto, "%i", i);
		outtextxy(i,700, texto);
		outtextxy(0,j, texto);
		line(i,0,i,700);
		line(0,j,700,j);
	}
}
void Grafica::limpiarVector(){
	for(int i=0; i<25; i++)
	x[i].setP(0);
	for(int i=0; i<25; i++)
	y[i].setP(0);
}
void Grafica::ingresarPunto(double _x, double _y){
	int i = 0;
	bool bandera = false;
	
	if(x[24].getP() != 0)
		cout<<endl<<"*****************Vector lleno, no es posible ingresarlo*****************"<<endl<<endl;
	else
	{
		while(i<25 && bandera != true)
		{
			
			if(x[i].getP() == 0 && y[i].getP() == 0)
			{
				x[i].setP(_x);
				y[i].setP(_y);
				bandera = true;
			}
			i++;
		}
	}
}
void Grafica::pintarPunto(){
	int actual, final, cont;
	bool bandera2 = false, bandera = false;
	double valor = 0;

	for(cont=0; cont<25 && bandera2 == false; cont++)//Este ciclo busca el ultimo punto del vector
	{
		if(x[cont].getP() == 0)
		{
			final = cont-1;
			bandera2 = true;
		}
	}
	for(double z=x[0].getP(); z<=x[final].getP(); z = z+dis)//Este es el valor de Z para la formula
	{
		valor = laGrange(z,final);
		circle(z, valor,1);
		bandera = false;// Se ponen al ambos valores en cero 
		valor = 0;//       para que no de error
	}
}
double Grafica::laGrange(double z, int final)
{
	double valor = 0,l;
	
	for(int i=0; i<=final ; i++) 
	{
		l=y[i].getP();
		for(int j=0; j<=final; j++) 
		{
			if(i!=j) 
			{
				l=(l*(z-x[j].getP()))/(x[i].getP()-x[j].getP());
			}
		}
		valor=valor+l;
	}
	return valor;
}
void Grafica::ordenarBurbuja(){
	double temporal;
	
	for (int i = 0;i < 25; i++)
	{
		for (int j = 0; j< 25; j++)
		{
			if (x[j].getP() > x[j+1].getP() && (x[j].getP() !=0 && x[j+1].getP() != 0))
			{ // Ordena el array de menor a mayor, cambiar el "<" a ">" para ordenar de menor a mayor
			//x
			temporal = x[j].getP(); 
			x[j].setP(x[j+1].getP()); 
			x[j+1].setP(temporal);
			//y
			temporal = y[j].getP(); 
			y[j].setP(y[j+1].getP()); 
			y[j+1].setP(temporal);
			}
		}
	}
}
void Grafica::trazado(double _X)//dibuja las coordenadas en el plano
{
	bool bandera2 = false;
	int final;
	double _Y, _y;
	
	for(int cont=0; cont<25 && bandera2 == false; cont++)//Este ciclo busca el ultimo punto del vector
	{
		if(x[cont].getP() == 0)
		{
			final = cont-1;
			bandera2 = true;
		}
	} 
	_Y = laGrange(_X,final);
	_y = 700-laGrange(_X,final);
	
	char texto[25], texto2[25];
	
	sprintf(texto, "X: %.2f", _X);
	outtextxy(_X+2,_Y, texto);
	
	sprintf(texto2, "Y: %.2f", _y);
	outtextxy(_X+2,_Y+15, texto2);
	
	circle(_X,_Y,5);
}
