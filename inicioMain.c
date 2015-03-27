#include <stdio.h>
void main()
{
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
