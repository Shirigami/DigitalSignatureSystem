#include "userData.h"
#include "Almacenar.h"
#include "RSAencription.h"



int pin_size(int num){
  printf("%d",num);
  int size = 0;
  while (num !=0 ){
    num = num/10;
    size++;
  }
  return size;
}


int request_info_user(){

  printf("______________________________________________________________________ \n");
  printf("Ingrese los datos que se le solicitan\n\n");

  /*Solicitud del nombre del usuario*/
  char first_name[200];
  printf("Nombre: ");
  scanf ("%s",&first_name);

  /*Solicitud del numero de identificacion del usuario*/
  char id_user[20];
  printf("Numero de identificación: ");
  scanf ("%s",&id_user);


  /*Solicitud del pin del usuario*/
  char pin[20];
  printf("PIN:\n");
  scanf("%s",&pin);
  //aprintf("%s",pin);

  while (strlen(&pin) != 5){ /*Verificacion  del largo del pin*/
    printf("El pin debe ser de 5 dígitos, por favor ingreselo nuevamente: \n");
    scanf("%s",&pin);
  }

  /*Solicitud del tamaño de las llaves públicas y privadas*/
  int select_key_size;
  printf ("Seleccione el tamaño de la llave: \n");
  printf ("         1- 1024\n");
  printf ("         2- 2048\n");
  scanf ("%d",&select_key_size);
  //printf("estoyaqui");
  //printf("%d",select_key_size);
  while (select_key_size != 1 && select_key_size != 2){/*Verificacion de la opcion seleccionada*/
      printf("Opcion inválida \n");
      printf("Seleccione nuevamente el tamaño de la llave\n");
      scanf("%d",&select_key_size);
      getchar();
  }
  switch(select_key_size){
    case 1: /*En caso de que elija la opcion 1*/
      select_key_size = 1024;
      break;
    case 2: /*En caso de que elija la opcion 1*/
      select_key_size = 2048;
      break;

  }

  char *privateKey, *publicKey;
  RSA_keys(select_key_size, &privateKey, &publicKey);
	char size[5];

	sprintf(size,"%d",select_key_size);

  Usuario cliente;
  cliente.id = id_user;
  cliente.nombre = first_name;
  cliente.pin = pin;
  cliente.largo = size;
  cliente.pkey = publicKey;
  cliente.prkey = privateKey;


  AlmacenarDatos(cliente);
  return 0;
}


int revoked_certificate(){
  printf("______________________________________________________________________ \n");
  printf("Para revocar el certificado ingrese su número de identificación.\n\n");
  /*Solicitud del numero de identificacion*/
  char id_user[200];
  printf("Numero de identificación: ");
  scanf ("%s",&id_user);
  strcat(id_user,".txt");
  printf("%s",id_user);
  FILE* archivo = fopen(id_user, "r");
  if (archivo) {
    fclose(archivo);

    //RevocarCertificado(id_user,);
  }
  else {
      printf("\nEl archivo no existe\n");
      return 0;
  }
return 0;
}


int signing_document(){
  printf("______________________________________________________________________ \n");
  printf("FIRMAR DOCUMENTO\n\n");

  /*Solicitud de la ruta del documento que se desea firmar*/
  char *document_path;
  printf("Indique la ruta del documento que desea firmar: \n");
  scanf ("%s",document_path);

  /*Solicitud del numero de identificacion*/
  int id_user;
  printf("Numero de identificación: ");
  scanf ("%d",&id_user);

  /*Solicitud del pin del usuario*/
  int pin;
  printf("PIN: ");
  scanf("%d",&pin);
  return 0;
}


int validate_document(){
  printf("______________________________________________________________________ \n");
  printf("FIRMAR DOCUMENTO\n\n");

  /*Solicitud de la ruta del documento que se desea verificar*/
  char *document_path;
  printf("Indique la ruta del documento que desea firmar: \n");
  scanf("%s", document_path);
  return 0;
}
