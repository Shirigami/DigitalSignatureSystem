#ifndef Almacenar_h
#define Hash_h
#include <stdio.h>//  Realizado por: Wayner Valverde
#include <string.h>
#include <stdlib.h>

typedef struct _Usuario{
  char *id;
  char *nombre;
  char *pin;
  char *largo;
  char *pkey;
  char *prkey;
} Usuario;
void AlmacenarDatos(Usuario user);
void ObtenerCertificado(char *doc, char *docf);
void RevocarCertificado(char *doc, char *puk, char*prk);
void FirmarDoc(char *doc, char *firma, char *id);
char *GetPin(char *doc);
char *GetPublic(char *name);
char *GetPrivate(char *name);


#endif
