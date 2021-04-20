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

int pedirCantidad ();
Producto getProducto (int id);
void cargarProductos (Cliente cliente);
void cargarClientes (int n , Cliente * clientes);
float calcularTotalProducto (Producto producto);
float calcularTotalCliente (Cliente cliente);
void mostrarProducto (Producto producto);
void mostrarProductos (int cantidad, Producto * porductos);
void mostrarCliente (Cliente cliente);
void mostrarClientes (int cantidad, Cliente * clientes);
void freeMemoria (int n, Cliente * clientes);

/*************************FUNCIÓN PRINCIPAL*************************/

int main(int argc, char const *argv[])
{
	int cantClientes;
	Cliente * clientes;
	
	printf("\tSISTEMA DE GESTI�N DE DISTRIBUCION\n");
	printf("Ingrese la cantidad de clientes: (Entre 1 y 5) \n");
	cantClientes = pedirCantidad();
	printf("\n");
	
	clientes = (Cliente *) malloc(sizeof(Cliente) * cantClientes);
	cargarClientes(cantClientes, clientes);
	printf("\n");
	mostrarClientes(cantClientes, clientes);
	freeMemoria(cantClientes, clientes);

	return 0;
}

/*************************FUNCIONES SECUNDARIAS*************************/
int pedirCantidad ()
{
	unsigned int n;
	
	do{
		scanf("%u", &n);
		fflush(stdin);
		if (n < 1 || n > 5)
			printf("Error, ingrese nuevamente.\n");
	} while(n < 1 || n > 5);
	
	return n;
}

Producto getProducto (int id)
{
	Producto producto;

	producto.ProductoID = id;
	producto.Cantidad = 1 + rand() % 10;
	producto.TipoProducto = TiposProductos[rand() % 5];
	producto.PrecioUnitario = 10 + rand() % 91;
	return producto;
}

void cargarProductos (Cliente cliente) 
{
	for(int i = 0 ; i < cliente.CantidadProductosAPedir ; i++) {
		//Mando el id del producto a la funci�n en la iteracion
		cliente.Productos[i] = getProducto(i + 1);
	}
}

void cargarClientes (int n, Cliente * clientes)
{
	for (int i = 0 ; i < n ; i++)
	{
		clientes[i].ClienteID = i + 1;
		//Reservo memoria y pido el nombre del cliente
		clientes[i].NombreCliente = (char *) malloc(50);
		printf("Ingrese el nombre del cliente: \n");
		scanf("%[0-9a-zA-Z ]s", clientes[i].NombreCliente);
		fgetc(stdin);
		//Genero el resto de los atributos del cliente
		clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
		clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
		cargarProductos(clientes[i]);
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
	printf("\tPrecio Unitario: $%.2f\n", producto.PrecioUnitario);
	printf("\tPrecio Total: $%.2f\n", calcularTotalProducto(producto));
	printf("\n");
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
	printf("Total a pagar: $%.2f\n", calcularTotalCliente(cliente));
	printf("\n--------------------------------------------------------------------------\n\n");
}

void mostrarClientes (int n, Cliente * clientes)
{
	printf("\tLISTA DE CLIENTES\n");
	for (int i = 0 ; i < n ; i++)
		mostrarCliente(clientes[i]);
}

void freeMemoria (int n, Cliente * clientes) 
{
	for (int i = 0 ; i < n ; i++)
	{
		free(clientes[i].NombreCliente);
		free(clientes[i].Productos);	
	}
	
	free(clientes);
}
