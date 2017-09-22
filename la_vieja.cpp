#include <iostream>
using namespace std;
int verificarfilas(char *, int, int);
int verificarcolumnas(char *, int, int);
int diagonalprincipal(char *, int f, int c);
int diagonal_inferior(char *, int, int);
void mostrarvieja(char *, int, int);
void mostrarvieja(char *pm, int a, int b)
{
	cout<<"VIEJA HECHO POR WILLIAM PAEZ"<<endl;
	cout<<endl;
	cout<<"--------------------"<<endl;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			a++;
			cout<<"  "<<*(pm+i*3+j)<<"  ";
			if(a==1)
			{
				cout<<"| ";
				a=0;
			}
		}
		cout<<endl;
		b++;
		if(b==1)
		{
			cout<<"--------------------"<<endl;
			b=0;
		}
	}
}
int main()
{
	int f, c, w, x, y, z, empate;
	char vieja[3][3], *pv, jugador1[20], jugador2[20];
	bool continuar=true, continuar2=true, gameover=true;
	pv=&vieja[0][0];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			*(pv+i*3+j)=' ';
	}
	mostrarvieja(&vieja[0][0], 0, 0);
	cout<<"Nombre del primer jugador: ";
	cin>> jugador1;
	cout<<"Nombre del segundo jugador: ";
	cin>> jugador2;
	while(gameover)
	{
		mostrarvieja(&vieja[0][0], 0, 0);
		cout<<endl<<endl<<jugador1<<": (X)"<<"                          "<<jugador2<<": (O)"<<endl;
		while(continuar)
		{
			cout<<jugador1<<" :Especifique en que fila y que columna quiere poner la X: ";
			cin>> f, cin>> c;
			f=f-1; c=c-1;
			if((vieja[f][c]!='X')&&(vieja[f][c]!='O')&&(f>=0&&f<3)&&(c>=0&&c<3))
			{
				continuar=false;
				vieja[f][c]='X';
			}
		}
		x=verificarfilas(&vieja[0][0], f, c);
		y=verificarcolumnas(&vieja[0][0], f, c);
		z=diagonalprincipal(&vieja[0][0], f, c);
		w=diagonal_inferior(&vieja[0][0], f, c);
		if((x==1)||(y==1)||(z==1)||(w==1))
		{
			mostrarvieja(&vieja[0][0], 0, 0);
			cout<<endl<<"LAS X GANAN "<<endl;
			cout<<jugador1<<" es el GANADOR "<<endl;
			return 0;
		}
		empate=0;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
			{
				if(vieja[i][j]!=' ')
					empate++;
			}
		if(empate==9)
		{
			mostrarvieja(&vieja[0][0], 0, 0);
			cout<<"AMBOS JUGADORES EMPATAN "<<endl;
			return 0;
		}
		mostrarvieja(&vieja[0][0], 0, 0);
		while(continuar2)
		{
			cout<<jugador2<<" :Especifique en que fila y que columna quiere poner la O: ";
			cin>> f, cin>> c;
			f=f-1; c=c-1;
			if((vieja[f][c]!='X')&&(vieja[f][c]!='O')&&(f>=0&&f<3)&&(c>=0&&c<3))
			{
				continuar2=false;
				vieja[f][c]='O';
			}
		}
		x=verificarfilas(&vieja[0][0], f, c);
		y=verificarcolumnas(&vieja[0][0], f, c);
		z=diagonalprincipal(&vieja[0][0], f, c);
		w=diagonal_inferior(&vieja[0][0], f, c);
		if((x==1)||(y==1)||(z==1)||(w==1))
		{
			mostrarvieja(&vieja[0][0], 0, 0);
			cout<<"LAS O GANAN "<<endl;
			cout<<jugador2<<" es el GANADOR "<<endl;
			return 0;
		}	
		continuar=continuar2=true;
	}
}
int verificarfilas(char *pm, int f, int c)
{
	char *pf, *pf2;
	int band=0;
	pf=pf2=pm;
	for(int j=0; j<3; j++)
	{
		if(*(pf+f*3+j)==*(pf2+f*3+c))
			band++;
	}
	if(band==3)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int verificarcolumnas(char *pm, int f, int c)
{
	char *pf, *pf2;
	int band=0;
	pf=pf2=pm;
	for(int j=0; j<3; j++)
	{
		if(*(pf+j*3+c)==*(pf2+f*3+c))
			band++;
	}
	if(band==3)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int diagonalprincipal(char *pm, int f, int c)
{
	char *pf, *pf2;
	int band=0;
	pf=pf2=pm;
	for(int i=0; i<3; i++)
	{
		if(*(pf+i*3+i)==*(pf2+f*3+c))
			band++;
	}
	if(band==3)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
int diagonal_inferior(char *pm, int f, int c)
{
	char *pf, *pf2;
	int band=0;
	pf=pf2=pm;
	for(int i=3; i>0; i--)
	{
		if(*(pf+3*i-1-i+1)==*(pf2+f*3+c))
			band++;
	}
	if(band==3)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
