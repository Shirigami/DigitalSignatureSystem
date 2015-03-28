#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pin_size(long num){
  int size = 0;
  while (num !=0 ){
    num = num/10;
    size++;
  }
  return size;
}


int request_info_user(){

  char info[6][50];

  char first_name[20];
  printf("Nombre: ");
  scanf ("%s",first_name);

  strcpy(info[0], first_name);
 //printf("%s",info[0]);
/*
  char last_name[20];
  printf("Apellido: ");
  scanf ("%s",last_name);
  strcpy(info[1], last_name);


  int id_user;
  char id = (char)id_user;
  printf("Numero de identificación: ");
  scanf ("%d",&id_user);

  int pin;

  printf("PIN: ");
  scanf("%d",&pin);
  while (pin_size(pin) != 5){
    printf("El pin debe ser de 5 dígitos, por favor ingreselo nuevamente: \n");
    scanf("%d",&pin);
  }
  convierte un int de base 10 una cadena de chars
  itoa(pin, info[3], 10);


  int select_key_size;
  char slct = (char)select_key_size;
  printf ("Seleccione el tamaño de la llave: \n");
  printf ("         1- 1024\n");
  printf ("         2- 2048\n");

  scanf ("%d",&select_key_size);

  while (select_key_size != 1 && select_key_size != 2){
      printf("Opcion inválida \n");
      printf("Seleccione nuevamente el tamaño de la llave\n");
      scanf("%d",&select_key_size);
  }

  switch(select_key_size){
		case 1:printf("Aun no hace nada\n");
		case 2:printf("Aun no hace nada\n");
  return 0;
  }
  strcpy(info[4], slct);
  */
}

/*
int main(){
  request_info_user();
}
*/
