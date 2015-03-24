#include "Hash.h"
#include "RSAencription.h"
//
int main(int argc, char const *argv[])
{

	char *publicKey, *privateKey;
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

	// char nomArchivo[] = "hola";
	// int cantidad = readCh(nomArchivo);
	// char *ptrArchivo = readFile(cantidad,nomArchivo);
	// summary(ptrArchivo);
	// free(ptrArchivo);

	//printf("%d\n",compareHash("95i","95"));
	return 0;
}
