#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define placaN 9

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
int CANT(int autos){

	printf("Ingrese cuantos autos/clientes se cargaran: ");
	scanf("%d", &autos);
		while(autos<=0){
			puts("La cantidad asignada debe ser un numero entero positivo. Por favor, intente nuevamente.");
			printf("Ingrese cuantos autos/clientes se cargaran: ");
			scanf("%d", &autos);}

return autos;}


	e_reparaciones cargarauto(){
		e_reparaciones AUX;

	//Placa.
		fflush(stdin);
        printf("Ingrese el numero de placa del auto (7 caracteres): ");
		fgets(AUX.placa, placaN, stdin);
			for(int j=0; AUX.placa[j]!='\0'; j++){
				AUX.placa[j] = toupper(AUX.placa[j]);
				if(AUX.placa[j+1]=='\0') AUX.placa[j]='\0';}
	//Marca.
		fflush(stdin);
	    printf("Ingrese la marca del auto a partir de las siguientes opciones:\n T: Toyota.\n R: Ram.\n P: Peugeot.\n B: Byd.\n F: Ford.\n V: Volkswagen.\n");
		scanf("%c", &AUX.marca); AUX.marca = toupper(AUX.marca);
			while(AUX.marca!='T' && AUX.marca!='R' && AUX.marca!='P' && AUX.marca!='B' && AUX.marca!='F' && AUX.marca!='V'){
				fflush(stdin);
		    	puts("El caracter no coincide con las opciones brindadas. Por favor, intente nuevamente.");
		    	printf("Ingrese la marca del auto a partir de las siguientes opciones:\n T: Toyota.\n R: Ram.\n P: Peugeot.\n B: Byd.\n F: Ford.\n V: Volkswagen.\n");
				scanf("%c", &AUX.marca); AUX.marca = toupper(AUX.marca);}
	//Horas.
		printf("Ingrese la cantidad de horas necesarias para repararlo: ");
		scanf("%d", &AUX.horas);
			while(AUX.horas<=0){
            	puts("La cantidad de horas cargadas debe ser un numero entero positivo. Por favor, intente nuevamente.");
				printf("Ingrese la cantidad de horas necesarias para repararlo: ");
				scanf("%d", &AUX.horas);}
	//Precio.
		printf("Ingrese el precio del arreglo: ");
		scanf("%f", &AUX.precio);
			while(AUX.precio<=0){
				puts("El precio debe ser un valor positivo. Por favor, intente nuevamente.");
				printf("Ingrese el precio del arreglo: ");
				scanf("%f", &AUX.precio);}
	//Pago + Pendiente.
		printf("Ingrese la cantidad de dinero ya abonado por el cliente: ");
		scanf("%f", &AUX.pago);
			while(AUX.pago<0 || AUX.pago > AUX.precio){
				if(AUX.pago<0) puts("El abono cargado debe ser un numero positivo. Por favor, intente nuevamente.");
				else if(AUX.pago > AUX.precio) puts("El abono cargado debe ser menor o igual al precio de arreglo. Por favor, intente nuevamente.");
				printf("Ingrese la cantidad de dinero ya abonado por el cliente: ");
				scanf("%f", &AUX.pago);}
		if(AUX.pago < AUX.precio) AUX.pendiente = false;						
		else AUX.pendiente = true;

	return AUX;}


char continuar(char seguir, int autos, int i){ //Continuar o no la carga de datos

	if(i+1<autos){
		fflush(stdin);
	 	printf("Desea continuar agregando autos/clientes a la lista? Responda con un caracter, siendo S: Si y N: No: ");
	 	scanf("%c", &seguir); seguir = toupper(seguir);
		while(seguir!='S' && seguir!='N'){
	 		fflush(stdin);
	 		puts("Caracter invalido. Por favor, intente nuevamente.");
	 		printf("Desea continuar agregando autos/clientes a la lista? Responda con un caracter, siendo S: Si y N: No: ");
	    	scanf("%c", &seguir); seguir = toupper(seguir);}
			}
return seguir;}


 //Paso 1,a. Pedir datos (Parte 2).
void pedirdatos(e_reparaciones LISTA, int autos){

	char seguir='S'; FILE*archivo;
	archivo = fopen("reparaciones.txt", "a");
    if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{	
		for(int i=0; i<autos && seguir=='S'; i++){
			LISTA = cargarauto();
			fprintf(archivo, " %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);
			seguir = continuar(seguir, autos, i);}
			}
	fclose(archivo);
	return;}

 //Paso 2,a. Menu (Parte 1).

void opcion1(e_reparaciones LISTA, int autos){ //Agregar un registro al archivo.
 
	FILE*archivo;
	archivo = fopen("reparaciones.txt", "a");
   	if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{	
		for(int i=0; i<1; i++){
	 		LISTA = cargarauto();
	 		fprintf(archivo, " %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);
			}
			}
	fclose(archivo);

return;}


void opcion2(e_reparaciones LISTA, int autos){ //Listar por pantalla todo el archivo.

	FILE*archivo;
	archivo = fopen("reparaciones.txt","r");
    if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{
	   	printf("Placa||Marca||Horas||Precio||Abono||Pago pendiente (Siendo 0: Si y 1: No)\n");
		for(int i=0; fscanf(archivo, " %s %c %d %f %f %d", LISTA.placa, &LISTA.marca, &LISTA.horas, &LISTA.precio, &LISTA.pago, &LISTA.pendiente) != EOF; i++){
			printf(" %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);}
			}
	fclose(archivo);
return;}


void opcion3(e_reparaciones LISTA, int autos){ //Listar por pantalla solo los registros que cumplan alguna condicion. Condicion elegida: + de 8 horas de reparacion.
	int condicionHORAS=8; FILE*archivo;
	archivo = fopen("reparaciones.txt","r");
    if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{
		printf("Autos con mas de 8 horas de reparacion:\n");
		for(int i=0; fscanf(archivo, " %s %c %d %f %f %d", LISTA.placa, &LISTA.marca, &LISTA.horas, &LISTA.precio, &LISTA.pago, &LISTA.pendiente) != EOF; i++){
			if(LISTA.horas>=condicionHORAS) printf(" %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);}
			}
	fclose(archivo);
return;}


void opcion4(e_reparaciones LISTA, int autos){ //Busqueda especifica por alguno de los campos, preguntando al usuario que. Campo seleccionado: Marcas.

	char eleccionMARCA;
	fflush(stdin);
	printf("Ingrese la marca de auto a listar a partir de las siguientes opciones:\n T: Toyota.\n R: Ram.\n P: Peugeot.\n B: Byd.\n F: Ford.\n V: Volkswagen.\n");
	scanf("%c", &eleccionMARCA); eleccionMARCA = toupper(eleccionMARCA);
		while(eleccionMARCA!='T' && eleccionMARCA!='R' && eleccionMARCA!='P' && eleccionMARCA!='B' && eleccionMARCA!='F' && eleccionMARCA!='V'){
			fflush(stdin);
		    puts("El caracter no coincide con las opciones brindadas. Por favor, intente nuevamente.");
		    printf("Ingrese la marca de auto a listar a partir de las siguientes opciones:\n T: Toyota.\n R: Ram.\n P: Peugeot.\n B: Byd.\n F: Ford.\n V: Volkswagen.\n");
			scanf("%c", &eleccionMARCA); eleccionMARCA = toupper(eleccionMARCA);}
	FILE*archivo;
	archivo = fopen("reparaciones.txt","r");
    if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{
		printf("Marca seleccionada: %c.\n", eleccionMARCA);
		printf("Placa||Marca||Horas||Precio||Abono||Pago pendiente (Siendo 0: Si y 1: No)\n");
		for(int i=0; fscanf(archivo, " %s %c %d %f %f %d", LISTA.placa, &LISTA.marca, &LISTA.horas, &LISTA.precio, &LISTA.pago, &LISTA.pendiente) != EOF; i++){
			if(LISTA.marca==eleccionMARCA) printf(" %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);}
			}
	fclose(archivo);
return;}


void opcion5(e_reparaciones LISTA, int autos){ //Dividir la informacion del archivo de origen en dos archivos de texto nuevos. Campo seleccionado: Pendiente.

	FILE*archivo;
	archivo = fopen("reparaciones.txt","r");
    if(archivo==NULL) printf("Error al abrir el archivo.\n");
	else{
		 FILE*archivo2;
		 archivo2 = fopen("pendiente.txt","w");
    	 if(archivo2==NULL) printf("Error al abrir el archivo.\n");
		 else{
		 	  FILE*archivo3;
			  archivo3 = fopen("abonado.txt","w");
			  if(archivo3==NULL) printf("Error al abrir el archivo.\n");
			  else{
				   for(int i=0; fscanf(archivo, " %s %c %d %f %f %d", LISTA.placa, &LISTA.marca, &LISTA.horas, &LISTA.precio, &LISTA.pago, &LISTA.pendiente) != EOF; i++){
			if(LISTA.pendiente==0){
			fprintf(archivo2, " %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);}
			else if(LISTA.pendiente==1){
			fprintf(archivo3, " %s %c %d %.2f %.2f %d \n", LISTA.placa, LISTA.marca, LISTA.horas, LISTA.precio, LISTA.pago, LISTA.pendiente);}
					}	
			}
			fclose(archivo);
		}
		fclose(archivo);
	}
	fclose(archivo);
}
 //Paso 2,a. Menu (Parte 2).
void menu(e_reparaciones LISTA, int autos){

	int menu=-1;
	while(menu!=0){
		printf("Elija una opcion:\n Opcion 1: AGREGAR DATOS.\n Opcion 2: Mostrar datos.\n Opcion 3: Mostrar lista de autos con mas de 8 horas de reparacion.\n Opcion 4: Listar datos por marca a eleccion.\n Opcion 5: .\n Opcion 0: Salir del sistema.\n");
		scanf("%d", &menu);
		switch(menu){

			case 1:{ //Agregar un registro al archivo.
				opcion1(LISTA, autos); break;}

			case 2:{ //Listar por pantalla todo el archivo.
				opcion2(LISTA, autos); break;}

			case 3:{ //Listar por pantalla solo los registros que cumplan alguna condicion. Condicion elegida: + de 8 horas de reparacion.
				opcion3(LISTA, autos); break;}

			case 4:{ //Busqueda especifica por alguno de los campos, preguntando al usuario que. Campo seleccionado: Marcas.
				opcion4(LISTA, autos); break;}

			case 5:{ //Dividir la informacion del archivo de origen en dos archivos de texto nuevos. Campo seleccionado: Pendiente.
   				opcion5(LISTA, autos); break;}

			case 0:{ //Salir del sistema.
				puts("Se cerro el programa."); break;}
			default:{puts("Se ingreso una opcion invalida. Por favor, intente nuevamente."); break;}}}

return;}


int main(){

 //Paso 1,b. Pedir datos.
	int autos = CANT(autos);
	e_reparaciones LISTA;
	pedirdatos(LISTA, autos);

 //Paso 2,b. Menu.
	menu(LISTA, autos);

return 0;}
