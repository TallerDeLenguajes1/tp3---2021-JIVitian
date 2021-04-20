#include <stdio.h>
#include <stdlib.h>

char * TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
	int ProductoID; //Numerado en ciclo iterativo
	int Cantidad; // entre 1 y 10
	char *TipoProducto; // Algún valor del arreglo TiposProductos
	float PrecioUnitario; // entre 10 - 100
} Producto ;

typedef struct {
	int ClienteID; // Numerado en el ciclo iterativo
	char *NombreCliente; // Ingresado por usuario
	int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
	Producto *Productos; //El tamaño de este arreglo depende de la variable
						// "CantidadProductosAPedir"
} Cliente ;

Producto getProducto (int id)
{
	Producto producto;

	producto.ProductoID = id;
	producto.Cantidad = 1 + rand() % 10;
	producto.TipoProducto = TiposProductos[rand() % 5];
	producto.PrecioUnitario = 10 + rand() % 91;
	return producto;
}

void cargarClientes (int n, Cliente * clientes)
{
	char * nombre;

	for (int i = 0 ; i < n ; i++)
	{
		clientes[i].ClienteID = i + 1;

		printf("Ingrese el nombre del cliente: \n");
		scanf("%s", nombre);
		clientes[i].NombreCliente = nombre;
		clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
		clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
		clientes[i].Productos[i] = getProducto(i + 1);
	}
}

int main(){
	//Cliente * clientes = (Cliente *) malloc(sizeof(Cliente) * 2);
	char palabra[100];
	printf("Hola\n");
	scanf("%s", palabra);

	fgetc(stdin);

	return 0;
}