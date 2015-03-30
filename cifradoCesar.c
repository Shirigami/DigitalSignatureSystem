#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
//prototipo de funciones.

void encriptar(char frase[MAX],int numero);
void desencriptar(char frase[MAX],int numero);

//Función para desencriptar Cifrado Cesar en C
void desencriptar(char frase[MAX],int numero)
{
    int i=0;
    while(frase[i]!='\0')
    {
        frase[i]=frase[i] - 5 ^(numero + 1 *65);
        i++;
    }
    printf("\nLa frase desencriptada es:\n%s\n",frase);
}

//Función para encriptar Cifrado Cesar en C
void encriptar(char frase[MAX],int numero)
{
    int i=0;
    char letra;
    while(frase[i]!='\0')
    {
        frase[i]=frase[i]+ 5 % (numero*65) ;
        i++;
    }
    printf("\nLa frase encriptado es:\n%s\n",frase);
}

int main()
{
    int x;
    char cadena[MAX];
    printf("introduce una cadena:     ");
    scanf("%3000[^\n]", cadena);
    while(getchar()!='\n');
    printf("introduce un numero : ");
    scanf("%d",&x);
    while(getchar()!='\n');
    encriptar(cadena, x);
    getchar();
    desencriptar(cadena, x);
    getchar();
    //Salimos
    return 0;
}

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
