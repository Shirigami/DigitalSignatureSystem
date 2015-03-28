#include "Hash.h"
#include "RSAencription.h"

int main(int argc, char const *argv[]){

	printf("__________________________________________________________ \n");
	printf("               DigitalSignatureSystem \n");
  printf("__________________________________________________________ \n \n");
  printf("Seleccione la operación que desea realizar\n\n");
  printf("1- Crear firma digital\n");
  printf("2- Revocar Cerficado\n");
  printf("3- Consultar Certificados\n");
  printf("4- Firma documento\n");
  printf("5- Validar documento\n");

  int option;
  scanf("%d",&option);
  while (option != 1 && option != 2 && option != 3 &&
    option != 4 && option != 5){
      printf("Opcion inválida \n");
      printf("Seleccione la operación que desea realizar \n");
      scanf("%d",&option);
  }
	 switch(option)
	  {
		case 1:printf("OPICION1\n");
			break;
		case 2:printf("OPICION2\n");
			break;
		case 3:printf("OPICION3\n");
			break;
		case 4:printf("OPICION4\n");
			break;
    case 5:printf("OPICION5\n");
  		break;
		}
/*
	char *privateKey, *publicKey;

	RSA *keyPair;

	char *msgEncryp = (char*)malloc(2048);
	char *msgDecrypted = (char*)malloc(2048);
	char msg[] = {"hola"};
	//char msg2[] = {"ffcd442253517b2d58f76e369b5c0481516215bf"};
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
	free(privateKey);

	// char nomArchivo[] = "profe";
	// int cantidad = readCh(nomArchivo);
	// char *ptrArchivo = readFile(cantidad,nomArchivo);
	// printf("%s\n",summary(ptrArchivo));
	// free(ptrArchivo);
*/
	return 0;
}
