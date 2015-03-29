#ifndef Almacenar_h
#define Almacenar_h
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
  char *keyPair;

} Usuario;
void AlmacenarDatos(Usuario user);
void ObtenerCertificado(char *doc, char *docf);
void RevocarCertificado(char *doc, char *puk, char*prk);
void FirmarDoc(char *doc, char *firma, char *id, char* fecha);
char *GetPin(char *doc);
char *GetPublic(char *name);
char *GetPrivate(char *name);
char *GetIDC(char *nom);
char *GetIDU(char *nombre);
int ComprobarCertificado(char *Texto);
char *Getlargo(char *name);
void ImprimirC(char *usu);
void RegistrarUsuario(char *usu);
void Desplegar();

#endif
