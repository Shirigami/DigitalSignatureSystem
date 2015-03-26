#include "Hash.h"

char *summary(char string[]){

	/* Extención del mensaje a la que se aplicara la funcion hash */
	int msg_len = strlen( string );

	/* Extención del hash sha1 - gcry_md_get_algo_dlen
	* devuelve el tamaño del resumen */
	int hash_len = gcry_md_get_algo_dlen( GCRY_MD_SHA1 );

	/* la salida del sha1 hash es en datos binarios  */
	unsigned char hash[ hash_len ];

	/* salida del sha1 hash - convetido en representacion hexadecimal
	* 2 digitos hexadecimales por cada byte + 1 para arrastrar \0 al final */
	char *out = (char *) malloc( sizeof(char) * ((hash_len*2)+1) );
	char *p = out;

	/* calculo del resumen sha1. Esto es un trozo de una funcion de acceso directo
	* la matoría de operaciones que realiza gcrypt requieren de la creación de un identificador */
	gcry_md_hash_buffer( GCRY_MD_SHA1, hash, string, msg_len );

	/* convierte cada byte a sus 2 digitos en ascii
	* la salida es en representacion hexadecimal */
	int i;
	for (  i = 0; i < hash_len; i++, p += 2 ) {
		snprintf ( p, 3, "%02x", hash[i] );
	}

	return out;
}

/*Funcion readCh retorna la cantidad de caracteres que contiene el documento, la cantidad será
utilizada para la creacion de la lista dinámica*/
int readCh(char nameFile[]) {
	FILE *file = NULL; /* puntero donde se guardara la direccion del archivo*/
	int count = 0;
	file = fopen (nameFile, "r"); /* abre y  lee el archivo*/

	while (feof(file) == 0){ /* Mientras el archivo no llegue al final*/
		fgetc(file); /* Recorre todo el documento*/
		count++; /* Contador de caracteres */
	}
  	fclose(file);/*cierra el archivo*/
	return count; /* retorna la cantidad de caracteres que contiene el archivo*/
}


/*Funcion readiFile recibe como parametro size que se utilizará para hacer una lista dinámica,
y el nombre del archivo que se leera para guardarlo dentro de la lista*/

char *readFile(int size , char nameFile[]){

	char *content; /*puntero que apunta a la lista dinámica*/
	content = (char*) malloc(size); /*solicitud de memoria para crear la lista dinámica*/
	FILE *file = NULL; /*guarda la dirección del archivo en memoria*/
	char ch; /*almacena los caracteres del archivo*/
	int count = 0; /* contador para almacenar los caracteres en la lista*/

	file = fopen(nameFile, "r"); /*abre y lee el archivo*/

	while (feof(file)==0){/*Mientras el archivo no llegue al final*/
		ch = fgetc(file); /*lee caracter por caracter*/
		content[count] = ch; /*almacena le caracter en la lista*/
		count++; /*aumenta el contador*/
	}

	fclose(file); /*cierra el archivo*/
	return content; /* retorna la lista*/
}


int compareHash(char hash1[], char hash2[]){
	char *h1 = hash1;
	char *h2 = hash2;
	int ret = 0;
	ret = strncmp(h1, h2, 6);
	if(ret != 0){ret = 1;}
	return ret;
}
