#include "Hash.h"


int main(int argc, char const *argv[])
{
	char nomArchivo[] = "hola";
	int cantidad = readCh(nomArchivo);
	char *ptrArchivo = readFile(cantidad,nomArchivo);
	summary(ptrArchivo);
	free(ptrArchivo);

	return 0;
}
