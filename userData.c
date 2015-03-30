#include "userData.h"
#include "Almacenar.h"
#include "RSAencription.h"
#include "cifradoCesar.h"
#include "Hash.h"
#include "date.h"



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

  char *encriptado;
  encriptado = cifrado(publicKey,atoi(pin));

	sprintf(size,"%d",select_key_size);

  Usuario cliente;
  cliente.id = id_user;
  cliente.nombre = first_name;
  cliente.pin = pin;
  cliente.largo = size;
  cliente.pkey = privateKey;
  cliente.prkey = encriptado;
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

  FILE* archivo = fopen(id_user, "r");
  if (archivo) {
    fclose(archivo);

    char *privateKey, *publicKey;
    char *bits = Getlargo(id_user);
    char *keyPair;
    RSA_keys(atoi(bits),&privateKey,&publicKey);


    char *encriptado;
    encriptado = cifrado(publicKey,atoi(GetPin(id_user)));

    RevocarCertificado(id_user,privateKey,encriptado);
  }
  else {
      printf("\nEl usuario no existe\n");
      return main();
  }
return 0;
}


int signing_document(){
  printf("______________________________________________________________________ \n");
  printf("FIRMAR DOCUMENTO\n\n");

  char* fecha = date();

  /*Solicitud de la ruta del documento que se desea firmar*/
  char document_path[MAX];
  printf("Indique la ruta del documento que desea firmar: \n");
  scanf ("%s",document_path);

  FILE* archivo = fopen(document_path, "r");

  if(archivo){
    fclose(archivo);
    /*Solicitud del numero de identificacion*/
    char id_user[30];
    printf("Numero de identificación: ");
    scanf ("%s",&id_user);
    strcat(id_user,".txt");
    //printf("%s",id_user);
    FILE* archivoUser = fopen(id_user, "r");

    if(archivoUser){

      char pin[30];
      printf("PIN: ");
      scanf("%s",&pin);
      //printf("%s",id_user);
      char *pinDoc;
      pinDoc = GetPin(id_user);
      // printf("%s",&pin);
      // printf("%s",pinDoc);
      ///home/kenneth/Desktop/ejemplo.txt

      if(!strcmp(pinDoc,pin)){
      //
        int cantidad = readCh(document_path);
        char *ptrArchivo = readFile(cantidad,document_path);
        char *hash = summary(ptrArchivo);
        //printf("%s",hash);
        char *keyPrivate = GetPrivate(id_user);
        char *key = descifrado(keyPrivate,atoi(pin));
        char *hashEncrypted = (char*)malloc(2048);
        int msg_len = strlen(hash);
        int numero;
        numero = public_encrypt((unsigned char*)hash, msg_len,(unsigned char*)key,(unsigned char*)hashEncrypted);
        //FirmarDoc(document_path, hashEncrypted, id_user,fecha);
        // int bits = 1024;
        // RSA_keys2(bits);


       }
      else{

        printf("\nEl pin es incorrecto\n");
        //fclose(archivo);
        return main();
      }

    }
    else{
      printf("\nEl usuario no existe\n");
      //fclose(archivo);
      return main();
    }

  }
    /*Solicitud del pin del usuario*/
  else{
    printf("\nEl path no existe\n");
    fclose(archivo);
    //getchar();
    return main();
  }

  // agarro documento ---- hash ----- getPrivate (id) (desencripto con Pin)---- encriptp hash ---
  // firma digital --- firmarDoc(char *path, char *firmaDigital, char *id))

  fclose(archivo);
  return 0;


}


int validate_document(){

  /*Solicitud de la ruta del documento que se desea verificar*/
  char *document_path;
  printf("Indique la ruta del documento que desea firmar: \n");
  scanf("%s", document_path);
  return 0;
}

int request_certificate(){
  Desplegar();
  return 0;

}
