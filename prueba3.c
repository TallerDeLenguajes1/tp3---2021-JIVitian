#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[20];

	printf( "Introduzca su nombre (20 letras máximo): " );
	fgets(s, 20, stdin);
	printf( "\nEl nombre que ha escrito es: %s\n",  s);

	return 0;
}