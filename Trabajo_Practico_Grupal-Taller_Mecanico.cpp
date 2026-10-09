#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 3
#define placaN 8

 //Paso 0. Definir estructura.
typedef struct{
	char placa[placaN];
	char marca;
	int horas;
	float precio;
}e_reparaciones;


 //Paso 1,a. Pedir datos (Parte 1).
	e_reparaciones cargarauto(){

		e_reparaciones AUX;
		fflush(stdin);
		printf("Ingrese el numero de placa del auto: ");
		fgets(AUX.placa, placaN, stdin);
			for(int j=0; AUX.placa[j]!='\0'; j++) AUX.placa[j] = toupper(AUX.placa[j]);
		fflush(stdin);
		do{	printf("Ingrese la marca del auto: ");
			scanf("%c", &AUX.marca);}
			while(isalpha(AUX.marca)==false);
		do{ printf("Ingrese la cantidad de horas necesarias para arreglarlo: ");
			scanf("%d", &AUX.horas);}
			while(AUX.horas<=0);
		do{ printf("Ingrese el precio del arreglo: ");
			scanf("%f", &AUX.precio);}
			while(AUX.precio<=0);

	return AUX;}

 //Paso 1,a. Pedir datos (Parte 2).
void pedirdatos(e_reparaciones lista[]){

	for(int i=0; i<N; i++) lista[i] = cargarauto();

return;}


 //Paso ?. Mostrar lista.
void mostrarlista(e_reparaciones lista[]){

	printf("PLACA:\tMARCA:\tHORAS:\tPRECIO:");
	for(int i=0; i<N; i++){
		for(int j=0; lista[i].placa[j]!='\0'; j++) printf("%c", lista[i].placa[j]);
			printf("\t");
		printf("%c\t", lista[i].marca);
		printf("%d\t", lista[i].horas);
		printf("%.2f\n", lista[i].precio);}

return;}


int main(){

 //Paso 1,b. Pedir datos.
	e_reparaciones lista[N];
	pedirdatos(lista);

 //Paso 2,?. Mostrar lista.
	int menu=-1;
	while(menu!=0){
		printf("Elija una opcion:\n Opcion 1: MOSTRAR DATOS.\n Opcion 2:");
		scanf("%d", &menu);
		switch(menu){

		case 1:{mostrarlista(lista); break;}}}

return 0;}
