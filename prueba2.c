#include <stdio.h>

int main(){
	char nombre[100];

	printf("Ingrese su nombre: \n");
	scanf("%s", nombre);

	fgetc(stdin);
	
	return 0;
}