#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************DEFINICIÓN DE VARIABLES Y ESTRUCTURAS*************************/
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

/*************************DEFINICIÓN DE FUNCIONES*************************/

Producto getProducto (int id);
void cargarClientes (int n , Cliente * clientes);
float calcularTotalProducto (Producto producto);
float calcularTotalCliente (Cliente cliente);
void mostrarProducto (Producto producto);
void mostrarProductos (int cantidad, Producto * porductos);
void mostrarCliente (Cliente cliente);
void mostrarClientes (int cantidad, Cliente * clientes);


/*************************FUNCIÓN PRINCIPAL*************************/

int main(int argc, char const *argv[])
{
	int cantClientes;
	Cliente * clientes;

	printf("Ingrese la cantidad de clientes: \n");
	scanf("%d", &cantClientes);

	clientes = (Cliente *) malloc(sizeof(Cliente) * cantClientes);

	cargarClientes(cantClientes, clientes);
	mostrarClientes(cantClientes, clientes);
	free(clientes);

	return 0;
}

/*************************FUNCIÓNES SECUNDARIAS*************************/

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
	char nombre[50];

	for (int i = 0 ; i < n ; i++)
	{
		clientes[i].ClienteID = i + 1;

		printf("Ingrese el nombre del cliente: \n");
		scanf("%s", nombre);
		fgetc(stdin);
		clientes[i].NombreCliente = (char *) malloc(50);
		strcpy(clientes[i].NombreCliente, nombre);
		clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
		clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
		clientes[i].Productos[i] = getProducto(i + 1);
	}
}

float calcularTotalProducto (Producto producto)
{
	return producto.Cantidad * producto.PrecioUnitario;
}

float calcularTotalCliente (Cliente cliente) 
{
	float total = 0;
	for (int i = 0 ; i < cliente.CantidadProductosAPedir ; i++)
	{
		total += calcularTotalProducto(cliente.Productos[i]);
	}

	return total;
}

void mostrarProducto (Producto producto)
{
	printf("\tID: %d\n", producto.ProductoID);
	printf("\tCantidad: %d\n", producto.Cantidad);
	printf("\tTipo: %s\n", producto.TipoProducto);
	printf("\tPrecio Unitario: %f\n", producto.PrecioUnitario);
	printf("\tPrecio Total: %f\n", calcularTotalProducto(producto));
	printf("\n\n");
}

void mostrarProductos (int cantidad, Producto * productos)
{
	for (int i = 0 ; i < cantidad ; i++)
		mostrarProducto(productos[i]);
}

void mostrarCliente (Cliente cliente)
{
	printf("ID: %d\n", cliente.ClienteID);
	printf("Nombre: %s\n", cliente.NombreCliente);
	printf("Cantidad de Productos a Pedir: %d\n", cliente.CantidadProductosAPedir);
	printf("Productos Pedidos:\n");
	mostrarProductos(cliente.CantidadProductosAPedir, cliente.Productos);
	printf("Total a pagar: %f\n", calcularTotalCliente(cliente));
	printf("\n");
}

void mostrarClientes (int n, Cliente * clientes)
{
	for (int i = 0 ; i < n ; i++)
		mostrarCliente(clientes[i]);
}