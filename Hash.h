#ifndef Hash_h
#define Hash_h

#define MAX 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gcrypt.h>


char *summary(char string[]);

int readCh(char nameFile[]);

char *readFile(int size , char nameFile[]);

int compareHash(char hash1[], char has2[]);

#endif
