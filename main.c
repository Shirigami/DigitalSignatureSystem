#include "Hash.h"
#include "RSAencription.h"


int main(int argc, char const *argv[]){

	printf("______________________________________________________________________ \n");
	printf("               DigitalSignatureSystem \n");
	printf("______________________________________________________________________ \n");
  printf("Seleccione la operación que desea realizar\n\n");
  printf("1- Crear firma digital\n");
  printf("2- Revocar Cerficado\n");
  printf("3- Consultar Certificados\n");
  printf("4- Firma documento\n");
  printf("5- Validar documento\n\n");

	int option;
  scanf("%d",&option);

  while (option != 1 && option != 2 && option != 3 &&
    option != 4 && option != 5){
      printf("Opcion inválida \n");
      printf("Seleccione la operación que desea realizar \n");
			scanf("%d",&option);
			getchar();
  }
	 switch(option)
	  {
		case 1:request_info_user();
			break;
		case 2:revoked_certificate();
			break;
		case 3:request_certificate();
			break;
		case 4:signing_document();
			break;
    case 5:validate_document();
  		break;
		}
/*
	char *privateKey, *publicKey;


	RSA *keyPair;
	char *var;
	char msg[] = "hola";


	RSA_keys(1024, &publicKey, &privateKey, &keyPair);
	var = RSA_encrypt(msg,keyPair);
	printf("%s",publicKey);
	printf("%s",privateKey);

	printf("%s",var);
	free(var);

	free(keyPair);
	free(publicKey);

	free(privateKey);

	free(privateKey);*/
	//
	// char nomArchivo[max];
	// scanf("%128[^\n]",nomArchivo);
	// int cantidad =



	//char nomArchivo[] = "DocumentoDePrueba";
	//int cantidad = readCh(nomArchivo);
	//char *ptrArchivo = readFile(cantidad,nomArchivo);
	//printf("%s\n",summary(ptrArchivo));
	//free(ptrArchivo);
	return 0;
}
