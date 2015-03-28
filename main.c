#include "userData.h"
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
		case 3:printf("OPICION3\n");
			break;
		case 4:signing_document();
			break;
    case 5:validate_document();
  		break;
		}
/*
	char *privateKey, *publicKey;

	RSA *keyPair;

	char *msgEncryp = (char*)malloc(2048);
	char *msgDecrypted = (char*)malloc(2048);
	char msg[] = {"hola"};
	int msg_len = strlen(msg);

	int publicEncrypt;


	RSA_keys(2048, &publicKey, &privateKey, &keyPair);

	publicEncrypt = public_encrypt((unsigned char*)msg, msg_len,(unsigned char*)publicKey,(unsigned char*)msgEncryp,keyPair);

	private_decrypt((unsigned char*)msgEncryp,publicEncrypt,(unsigned char*)privateKey, (unsigned char*)msgDecrypted,keyPair);

	printf("mensaje\n");
	printf("%s\n",msg);
	printf("privateKey\n");
	printf("%s",privateKey);
	printf("publicKey\n");
	printf("%s",publicKey);
	printf("mensajeEncriptado\n");
	printf("%s\n",msgEncryp);
	printf("mensajeDesencriptado\n");
	printf("%s\n",msgDecrypted);

	free(msgEncryp);
	free(msgDecrypted);
	free(keyPair);
	free(publicKey);
	free(privateKey);*/

	// char nomArchivo[] = "profe";
	// int cantidad = readCh(nomArchivo);
	// char *ptrArchivo = readFile(cantidad,nomArchivo);
	// printf("%s\n",summary(ptrArchivo));
	// free(ptrArchivo);

	return 0;
}
