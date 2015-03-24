#ifndef Hash_h
#define Hash_h

#include <stdio.h>
#include <stdlib.h>
#include <gcrypt.h>

int summary(char *string);

int readCh(char nameFile[]);

/*Funcion readiFile recibe como parametro size que se utilizará para hacer una lista dinámica, 
y el nombre del archivo que se leera para guardarlo dentro de la lista dinámica*/
char *readFile(int size , char nameFile[]);

#endif 