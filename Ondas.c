#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*PUESTO QUE NO SUPE COMO SEPARAR LOS METODOS DE CADA PARTE LOS COMENTE, SI INTENTAS HACER LO MISMO COMENTANDO CADA PARTE TE FUNCIONARÁ. GRACIAS
/*PARTE 1 CUERDA FIJA EN AMBOS EXTREMOS*/

int main()
{
	//constantes
 	float L= 0.64;
 	float c= 250.0;
 	float dx= 0.0050;
 	int tamanodatos;
	tamanodatos = 129;
//variables phi= perturbacion
//puntero reserva el acceso a una cajita, osea se reserva lo que vamos a guardar
 	float *perturbacion= malloc(tamanodatos*sizeof(float));
 //float *perturbacionpasado= malloc(tamanodatos*sizeof(float));
 	float *perturbacionfutura= malloc(tamanodatos*sizeof(float));		
 	float *t= malloc(tamanodatos*sizeof(float));
// float *posicion = malloc(tamanodatos*sizeof(float));

//lea las lineas un float un espacio y otro float columna por columna, ambste... =guardelo ahi 
	int i;

	FILE *cargando_archivo;	
	char cargar_archivo[100] = "cond_ini_cuerda.dat";
	float *perturbacionpasado = malloc(tamanodatos*sizeof(float));
	float *x = malloc(tamanodatos*sizeof(float));
	cargando_archivo = fopen(cargar_archivo, "r");

	for (i=0; i<tamanodatos; i++)
	{
		//printf("%d ", i);
	
		fscanf(cargando_archivo, "%f %f\n", &x[i], &perturbacionpasado[i]); 
		printf(" %f",perturbacionpasado[i]);
	
	}	
	printf("\n");
	fclose(cargando_archivo);
//FUNCION 
//recuerde que cdt2 /dx es menor que uno
	float dt= (dx*0.7)/c;

	int r=0;
	float razon;
	razon= (pow(c,2)*pow(dt,2))/(pow(dx,2));

	int n=0;
	float inicializado;
	inicializado = 0;
	perturbacion[0]= perturbacionpasado[0];
	perturbacion[tamanodatos-1]= perturbacionpasado[tamanodatos-1];
	for (r=1; r<tamanodatos-1; ++r)
	{	
		inicializado= perturbacionpasado[r-1] -2*perturbacionpasado[r] + perturbacionpasado[r+1];
		perturbacion[r]= perturbacionpasado[r] + (razon/2)*inicializado;
		
		
	}
	//for para imprimir
	for(r=0; r<tamanodatos; r++)
	{
		printf(" %f", perturbacion[r]);
	}
	printf("\n");

	int nt=  1.+1./dt ;
	int l=2;
	int m=0;
	for(l=2; l<nt; ++l)
	{
		perturbacionfutura[0]= perturbacion[0];
		perturbacionfutura[tamanodatos-1]= perturbacion[tamanodatos-1];
			for(m=1; m<tamanodatos-1; ++m)
			{
				perturbacionfutura[m]= 2*perturbacion[m]- perturbacionpasado[m]+(razon*(perturbacion[m-1]-2*perturbacion[m]+perturbacion[m+1]));

			}
	for(int a=0; a<tamanodatos; ++a)
	{			
	printf(" %f", perturbacionfutura[a]);
	}
	printf ("\n");
		
	
	for(int j=0; j<tamanodatos; ++j)
	{
		perturbacionpasado[j]= perturbacion[j];
		perturbacion[j]= perturbacionfutura[j];
	}

	}
return 0;
}
/*PARTE 2 CUERDA SUJETA EN UN EXTREMO*/	
/*
int main()
{
	//constantes
 	float L= 0.64;
 	float c= 250.0;
 	float dx= 0.0050;
 	int tamanodatos;
	tamanodatos = 129;
 	float *perturbacionf= malloc(tamanodatos*sizeof(float));
	float *perturbacionpasadof= malloc(tamanodatos*sizeof(float));
 	float *perturbacionfuturof= malloc(tamanodatos*sizeof(float));
	float dt= (dx*0.7)/c;
	float razon;
	razon= (pow(c,2)*pow(dt,2))/(pow(dx,2));
	for (int i=0; i<tamanodatos; i++)
	{
		//printf("%d ", i);
	
		perturbacionpasadof[i]=0; 
		printf(" %f",perturbacionpasadof[i]);
	
	}
	printf("\n");	
	int n=0;
	float inicializado;
	inicializado = 0;
	#define PI 3.1416
	perturbacionf[0]= 0;
	perturbacionf[tamanodatos-1]= sin((2*PI*c)/L*dt);
	for (int r=1; r<tamanodatos-1; ++r)
	{	
		inicializado= perturbacionpasadof[r-1] -2*perturbacionpasadof[r] + perturbacionpasadof[r+1];
		perturbacionf[r]= perturbacionpasadof[r] + (razon/2)*inicializado;		
	}
	//for para imprimir
	for(int r=0; r<tamanodatos; r++)
	{
		printf(" %f", perturbacionf[r]);
	}
	printf("\n");

	int nt=  1.+1./dt ;
	int l=2;
	int m=0;
	for(int l=2; l<nt; ++l)
	{
		perturbacionfuturof[0]= perturbacionf[0];
		perturbacionfuturof[tamanodatos-1]= sin((2*PI*c)/L*dt*l);
			for(m=1; m<tamanodatos-1; ++m)
			{
				perturbacionfuturof[m]= 2*perturbacionf[m]- perturbacionpasadof[m]+(razon*(perturbacionf[m-1]-2*perturbacionf[m]+perturbacionf[m+1]));

			}
	for(int a=0; a<tamanodatos; ++a)
	{			
	printf(" %f", perturbacionfuturof[a]);
	}
	printf ("\n");
		
	
	for(int j=0; j<tamanodatos; ++j)
	{
		perturbacionpasadof[j]= perturbacionf[j];
		perturbacionf[j]= perturbacionfuturof[j];
	}
	}

}*/
/*PARTE 3 TAMBOR*/
/*int main()
{
	
	double vector0[101][101];
	double vector1[101][101];
	double vector2[101][101];

	for (int i=0; i<tamanodatos; i++)
	{
		for (int j=0; j<tamanodatos; j++)		
		//printf("%d ", i);
	
		fscanf(cargando_archivo, "%f %f\n", &x[i], &vector0[i][j]); 
		printf(" %f",vector0[i][j]);
	
	}	
	printf("\n");
	float c= 250.0
	float dx= 0.5/110; 
	float dt= (dx*0.7)/c;
	
	int r=0;
	float razon;
	razon= (pow(c,2)*pow(dt,2))/(pow(dx,2));

	int n=0;
	float inicializado;
	inicializado = 0;
	perturbacion[0,:]= perturbacionpasado[0,:];
	perturbacion[:,0]= perturbacionpasado[:,0];
	perturbacion[tamanodatos-1,:]= perturbacionpasado[tamanodatos-1;:];
	perturbacion[:,tamanodatos-1]= perturbacionpasado[:,tamanodatos-1];

	for (r=1; r<tamanodatos-1; ++r)
	{	int 
		for(int h=0; h<tamanodatos-1; ++h)
		{
		inicializado= perturbacionpasado[r-1][h] -4*perturbacionpasado[r][h] + perturbacionpasado[r+1][h]+ perturbacionpasado[r][h+1]+ perturbacionpasado[r][h-1];
		perturbacion[r][h]= perturbacionpasado[r][h] + (razon/2)*inicializado;
		}
		
	}
	//for para imprimir
	for(r=0; r<tamanodatos; r++)
	{	
		for(h=0; h<tamanodatos; h++)
		{
		printf(" %f", perturbacion[r][h]);
		}
	}

return 0;
}




