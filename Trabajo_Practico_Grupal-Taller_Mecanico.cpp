#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define placaN 8

 //Paso 0. Definir estructura.
typedef struct{
	char placa[placaN];
	char marca;
	int horas;
	float precio;
	float pago;
	bool pendiente;
}e_reparaciones;


 //Paso 1,a. Pedir datos (Parte 1).
	e_reparaciones cargarauto(){

		e_reparaciones AUX;
		fflush(stdin);
            printf("Ingrese el numero de placa del auto: ");
		    fgets(AUX.placa, placaN, stdin);
		for(int j=0; AUX.placa[j]!='\0'; j++){
			AUX.placa[j] = toupper(AUX.placa[j]);
			} 
		fflush(stdin);
	        printf("Ingrese la marca del auto que puede ser \n T si es un Toyota\n R si es una Ram \n P si es Peugeot \n B si es un Byd \n F si es una Ford \n V si es Volkswagen:");
			scanf("%c", &AUX.marca);
			AUX.marca = toupper(AUX.marca);
		while(isalpha(AUX.marca)==false){
		    printf("usted a ingresado mal algo fijese que puso\n");
		    printf("Ingrese la marca del auto que puede ser \n T si es un Toyota\n R si es una Ram \n P si es Peugeot \n B si es un Byd \n F si es una Ford \n V si es Volkswagen: ");
		    scanf("%c", &AUX.marca);
			AUX.marca = toupper(AUX.marca);
		}
		    printf("Ingrese la cantidad de horas necesarias para arreglarlo:");
			scanf("%d", &AUX.horas);
		while(AUX.horas<=0){
            printf("usted a ingresado horas negativas esto no es posible\n");
			printf("Ingrese la cantidad de horas necesarias para arreglarlo:");
			scanf("%d", &AUX.horas); 
		}
		 printf("Ingrese el precio del arreglo:");
			scanf("%f", &AUX.precio);
		while(AUX.precio<=0){
			printf("usted a ingresado precio negativas esto no es posible\n");
			printf("Ingrese el precio del arreglo:");
			scanf("%f", &AUX.precio);
		}
		printf("Ingrese la cantidad de plata que dio la persona:");
			scanf("%f", &AUX.pago);
		while(AUX.pago<0 or AUX.pago>AUX.precio){
			printf("usted a ingresado mal cuanta plata tiene que pagar la persona\n");
			printf("Ingrese la cantidad de plata que dio la persona:");
			scanf("%f", &AUX.pago);
		}
		if(AUX.pago<AUX.precio){
			AUX.pendiente=false;						
		}
		else{
			AUX.pendiente=true;
		}
	return AUX;}

 //Paso 1,a. Pedir datos (Parte 2).
void pedirdatos(e_reparaciones lista,int autos){
	char seguir='S';
	FILE*archivo;
	   archivo = fopen("empleados.txt","a");
       if (archivo == NULL){
	   printf("Error al abrir el archivo\n");
}
else{	
	for(int i=0; i<autos && seguir=='S'; i++){
	 lista = cargarauto();
	 
	 fprintf(archivo," %s %c %d %f %f %d ",lista.placa,lista.marca,lista.horas,lista.precio,lista.pago,lista.pendiente);
	 fflush(stdin);
	 if(i+1<autos){
	 printf("quiere continuar agregando autos ponga S para si o N para no:");
	 scanf("%c", &seguir);
	 fflush(stdin);
	 seguir=toupper(seguir);
	 while(seguir!='S' && seguir!='N'){
	 	fflush(stdin);
	 	printf("usted a ingresado una letra cualquiera\n");
	 	printf("quiere continuar agregando autos ponga S para si o N para no:");
	    scanf("%c", &seguir);
	    seguir=toupper(seguir);
	    fflush(stdin);
		}
	 }
	 }
	 }
	 fclose(archivo);
return;}


 //Paso ?. Mostrar lista.
void mostrarlista(e_reparaciones lista){

	printf("PLACA:\tMARCA:\tHORAS:\tPRECIO:");
	for(int i=0; i<'n'; i++){
		for(int j=0; lista.placa[j]!='\0'; j++) printf("%c", lista.placa[j]);
			printf("\t");
		printf("%c\t", lista.marca);
		printf("%d\t", lista.horas);
		printf("%.2f\n", lista.precio);}

return;}


int main(){
int autos;
	printf("porfavor ingrese cuantos autos va a ingresar:");
	scanf("%d", &autos);
 //Paso 1,b. Pedir datos.
	e_reparaciones lista;
	pedirdatos(lista, autos);

 //Paso 2,?. Mostrar lista.
	int menu=-1;
	while(menu!=0){
		printf("Elija una opcion:\n Opcion 1: MOSTRAR DATOS.\n Opcion 2:");
		scanf("%d", &menu);
		switch(menu){

		case 1:{mostrarlista(lista); break;}}}

return 0;}
