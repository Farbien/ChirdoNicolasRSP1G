/*
 ============================================================================
 Name        : cHIRDOrsp1g.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVehiculo;

eVehiculo newVehiculo();
eVehiculo newVehiculoParanetros(char* id, char* marca, char* tipo, float* peso);
void guardarBin(char* vehiculo)


int main(void) {
	eVehiculo* unVehiculo = newVehiculoParanetros(122, Honda, urbano, 5432.21);




	return EXIT_SUCCESS;
}


/**
 *  función constructora base
 */
eVehiculo newVehiculo(){
	return (eVehiculo*) malloc(sizeof(eVehiculo));
}

/**
 *  función constructora parametrizada
 */
eVehiculo newVehiculoParanetros(char* id, char* marca, char* tipo, float* peso){
	eVehiculo* vehiculo;

	vehiculo->id = atoi(id);
	strcpy(vehiculo->marca,marca);
	vehiculo->tipo = atoi(tipo);
	vehiculo->peso = atof(peso);

	return vehiculo;
}

void guardarBin(char* vehiculo){
	FILE* pArchivo;
	pArchivo = fopen("array.bin", "wb");
	if(pArchivo != NULL)
	{
		fwrite(vehiculo, sizeof(vehiculo), 1, pArchivo);
	}
	fclose(pArchivo);
}
