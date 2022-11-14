#include <iostream>           //ANTHONY AVILA HERNANDEZ
#include <graphics.h>
#include "Grafica.h"

using namespace std;

Grafica plano;
int op, X, Y, tam, i; 
bool bandera = false;
main(int argc, char *argv[])
{
	initwindow(725,720);
	plano.pintarPlano();
	plano.limpiarVector();
	cout<<"***********Bienvenido***********"<<endl<<endl<<endl;
	do
	{
		cout<<"Seleccione una opcion"<<endl<<endl;
		cout<<"1->  Ingresar puntos "<<endl<<endl;
		cout<<"2->  Graficar puntos "<<endl<<endl;
		cout<<"3->  Cambiar distancia entre puntos"<<endl;
		cout<<"     (Para visualizar una línea solida o punteada)"<<endl<<endl;
		cout<<"4->  Trazado (Ver coordenadas de una posicion de la grafica)"<<endl<<endl;
		cout<<"5->  Eliminar todos los puntos "<<endl<<endl;
		cout<<"6->  Salir"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1:
				while(bandera == false)
				{
					system ("cls");
					cout<<"Ingrese la catidad de puntos que desea ingresar"<<endl;
					cin>>tam;
					if(tam>0 && tam<26)
					{
						bandera = true;
						cout<<"De click en las coordenadas que desee del plano"<<endl;
					}
				}
				i = 0;
				while(i<tam)
				{	
					X = 0; 
					Y = 0;
					delay(10);
					if(ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, X, Y);
						plano.ingresarPunto(X,Y);
						i++;
					}
				}
				plano.ordenarBurbuja();
				cout<<endl<<"***********Ingresados correctamente***********"<<endl;

				bandera = false;
				cleardevice();
				plano.pintarPlano();
				system ("pause");
				system ("cls");
				break;
				
			case 2:
				plano.pintarPunto();
				system ("pause");
				system ("cls");
				break;
			
			case 3:
				double dis;
				
				while(bandera == false)
				{
					system ("cls");
					cout<<"Ingrese la catidad de puntos que desea ingresar"<<endl;
					cout<<"El valor debe estar entre 0 y 3, se pueden decimales"<<endl;
					cout<<"Ejemplo: 1, 0.5, 2.5, 2"<<endl<<endl;
					cout<<"Ingresa: ";cin>>dis;
					
					if(dis>0 && dis<4)
					{
						bandera = true;
						plano.setDis(dis);
					}
				}
				bandera = false;
				cleardevice();
				plano.pintarPlano();
				system ("pause");
				system ("cls");
				break;
			
			case 4:
				bandera = false;
				cout<<endl<<"De click en la posición de la grafica de desea ver"<<endl;
				while(bandera == false)
				{	
					X = 0; 
					Y = 0;
					delay(10);
					if(ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, X, Y);
						plano.trazado(X);
						bandera = true;
					}
				}
				
				bandera = false;
				system ("pause");
				system ("cls");
				break;
			
			case 5:
				plano.limpiarVector();
				cout<<endl<<"***********Vector con las posiciones en '0' ***********"<<endl;
				cleardevice();
				plano.pintarPlano();
				system ("pause");
				system ("cls");
				break;
		}
	}while(op !=6);
	return 0;
}
