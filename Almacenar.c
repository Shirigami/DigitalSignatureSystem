/*Falta manejar los strings con el .txt, asignar un numero de certificado, encriptar llave privada*/
#include "Almacenar.h"


// int main (){
//
// 	/Usuario cliente={"2014.txt","Way","120", "1024","llavePublica","llavePrivada"};
// 	AlmacenarDatos(cliente);
// 	char *palabra="2014.txt";
// 	char *palabra2="student.txt";
// 	RevocarCertificado(palabra,"cochinada","tomelaaaa");
// 	FirmarDoc("ejemplo.txt","fiiiirmaaaaa",palabra);
// 	ObtenerCertificado(palabra,"archivo_firmado.txt");
// 	*GetPin(palabra);
// }



void AlmacenarDatos(Usuario user){// crea el txt cn la informacion del usuario
	// printf("%s\n",user.id);
  // printf("%s\n",user.nombre);
  // printf("%s\n",user.pin);
  // printf("%s\n",user.largo);
  // printf("%s\n",user.pkey);
  // printf("%s\n",user.prkey);

	FILE *f;
	int e = strlen(user.id) + 4;
	char temp[e];
	RegistrarUsuario(user.id);
	strcpy(temp,user.id);
	strcat(temp,".txt");



	f=fopen(temp,"w+");
 	fputs("-ID Usuario:",f);
	fputs(user.id,f);
	fputs("\n-Nombre:",f);
	fputs(user.nombre,f);
	fputs("\n",f);
	fputs("*Pin:",f);// alt+251
	fputs(user.pin,f);
	fputs("\n-Largo de llave:\n",f);
	fputs(user.largo,f);
	fputs("\n",f);
	fputs("\n@ID_certificado:1\n",f);
	fputs("$Public Key\n",f);
	fputs(user.pkey,f);
	fputs("\n*Private Key\n",f);
	fputs(user.prkey,f);
	fputs("!\n",f);


	fclose(f);
}

void ObtenerCertificado(char *doc, char *docf){// se obtiene el certificado del usuario y se agrega al doc firmaodo
	FILE *f, *d;
	f=fopen(doc,"r");
	d=fopen(docf,"a");
	int c=0, i=0;
	int lock=1;
	fputc('\n',d);
	fputs("Autoridad:Trusted Digital Signature System (TUDSS)\n",d);


		while ((c = getc(f)) != EOF){
			if(i==2){
				break;
			}

			if(c=='\n'){
				lock=1;
			}
			if(c=='*'){
				i++;
				//printf("\n");
				lock=0;
			}
			if(lock==1){
				fputc(c,d);
			}

		}
	fclose(f);
	fclose(d);
}

void RevocarCertificado(char *doc, char *puk, char*prk){// introduce las nuevas llaves al principio y revoca las viejas
	FILE *f, *d;
	char *pivot="pivot.txt";

	f = fopen(doc,"r");
	d = fopen(pivot,"w");
	int c = 0;



	while ((c = getc(f)) != EOF){// copia el user en el pivot
		  		fputc(c,d);
	}

	fclose(f);
	int numero;
	char *idCertificado = GetIDC(doc);
	numero = atoi(idCertificado);
	numero = numero + 1;
	sprintf(idCertificado,"%d",numero);
	remove(doc);
	fclose(d);
		//
	f = fopen(doc,"w");
	d = fopen(pivot,"r");
	c = 0;
	int boolean = 0;;

	while ((c = getc(d)) != EOF){// rellena cn llaves nuevas
		if(boolean == 0){
			if(c == '@'){
				boolean = 1;
			  fputs("@ID_Certificado:",f);
				fputs(idCertificado,f);
				fputs("\n",f);
			  fputs("$Public Key\n",f);
			  fputs(puk,f);
			  fputc('\n',f);
			  fputs("*Private Key\n",f);
			  fputs(prk,f);
			  fputs("\n!Llaves revocadas:\n",f);
			  }
		}
	fputc(c,f);
	}

	fclose(f);
	fclose(d);
	remove(pivot);



}

void FirmarDoc(char *doc, char *firma, char *id, char *fecha){//crea el doc firmado
	FILE *f, *d;
	int c=0;
	d=fopen(doc,"r");
	char *nombre = strcat(doc,"_signed.txt");
	//char *extension="_signed";
	//strcat(doc,extension);
	//printf("%s\n",doc );

	// arreglar el fichero con el txt
	// "nombre_signed.txt"

	//char *nombre="archivo_firmado.txt";
	f=fopen(nombre,"a");

	fputs("Texto original:\n",f);
	while ((c = getc(d)) != EOF){
		fputc(c,f);
	}

	fputs("!Firma Digital:\n",f);
	fputs(firma,f);
	fputc('\n',f);
	fputs("*Fecha:\n",f);
	fputs(fecha,f);
	fclose(f);
	ObtenerCertificado(id,nombre);

	//strcat(id,".txt");

}



char *GetPin(char *doc){// obtiene el pin del usuario
	FILE *f;
	char *pin = (char *) malloc(2048);
	int cont=0, i=0, c=0, cont2=0;
	f=fopen(doc,"r");
	while ((c = getc(f)) != EOF){
		if(cont>5 && c=='\n'){
			break;
		}
		if(i==1){
			cont++;
		}
		if(c=='*'){
			i=1;
		}

		if(cont>=5){
			//putchar(c);
			*pin=c;
			pin++;
			cont2++;

		}

	}// cierre while
	*pin='\0';
	pin=pin-(cont2);
	//printf("%s\n",pin);
	return pin;

}

char *GetPublic(char *name){// obtiene la llave publica del documento firmado
	FILE *f;
	char *puntero=(char *) malloc(2048);
	int lock=0, c=0, cont=0, cont2=0;
	f=fopen(name,"r");
	while ((c = getc(f)) != EOF){

		if(lock==1){
			cont++;
			//putchar('W');
		}
		if(c=='$'){
			lock=1;

		}

		if(cont>=11){
			*puntero=c;
			puntero++;
			cont2++;
			//putchar(c);
		}

	}// cierre while
	*puntero='\0';
	puntero=puntero-(cont2);
	//printf("%s\n",pk );
	return puntero;
}

char *GetPrivate(char *name){
	FILE *f;
	char *pri=(char *) malloc(2048);
	int lock=0, i=0, c=0, cont=0;
	f=fopen(name,"r");
	while ((c = getc(f)) != EOF){
		if(c=='!'){
			break;
		}
		if(c=='*'){
			i++;
		}
		if(i==2 && lock==1){
			//putchar('w');
			*pri=c;
			pri++;
			cont++;
		}
		if(i==2 && c=='\n'){
			lock=1;
		}
		//putchar(c);
	}// cierre while
	*pri='\0';
	pri=pri-(cont);
	return pri;

}

char *GetIDC(char *nom){// obtiene el id del certificado
	FILE *f;
	char *idc=(char *) malloc(2048);
	int lock=0, c=0, cont=0,cont2=0;
	f=fopen(nom,"r");
	while ((c = getc(f)) != EOF){
		if(lock==1 && c=='\n'){
			break;
		}

		if(lock==1){
			cont++;
			//putchar('W');
		}
		if(c=='@'){
			lock=1;

		}

		if(cont>=16){
			*idc=c;
			idc++;
			cont2++;
			//putchar(c);
		}

	}// cierre while
	*idc='\0';
	idc=idc-(cont2);
	return idc;

}

char *GetIDU(char *nombre){// obtiene el id de usuario en el text signed
	FILE *f;
	char *idu=(char *) malloc(2048);
	int  c=0, cont=0,cont2=0,cont3=0;
	f=fopen(nombre,"r");
	while ((c = getc(f)) != EOF){
		if(c=='\n' && cont==1){
			break;
		}

		if(c=='-'){
			cont=1;
		}
		if(cont==1){
			cont2++;
		}

		if(cont==1 && cont2>12){
			*idu=c;
			idu++;
			cont3++;
			//putchar(c);
		}

	}// cierre while
	*idu='\0';
	idu=idu-(cont3);
	return idu;


}

int ComprobarCertificado(char *Texto){// retorna 1 si el certificado en signed es valido
	char *nom = GetIDU(Texto);
	strcat(nom,".txt");
	char *idc = GetIDC(nom);
	char *idt = GetIDC(Texto);
	if(*idc == *idt){
		return 1;
	}
	return 0;
}

// sacar firma digital

char *Getlargo(char *name){// retorna el largo d la llave
	FILE *f;
	char *puntero=(char *) malloc(2048);
	int  i=0, c=0, cont=0, cont2=0,cont3=0;
	f=fopen(name,"r");
	while ((c = getc(f)) != EOF){
		if(c=='\n' && cont3>=4){
			break;
		}
		if(c=='\n'){
			cont3++;
		}

		if(c=='-'){
			cont++;

		}

		if(cont==3){
			i++;
		}

		if(cont3==4 && c!='\n'){
			*puntero=c;
			puntero++;
			cont2++;
			//putchar(c);
		}

	}// cierre while
	*puntero='\0';
	puntero=puntero-(cont2);
	//printf("%s\n",pk );
	return puntero;

}


void ImprimirC(char *usu){// imprime certificado:todo menos pin y private key
	FILE *f;
	f=fopen(usu,"r");
	int i=0,c=0;
	int lock=1;
	while ((c = getc(f)) != EOF){
		if(c=='!'){
				lock=1;
			}

			if(c == '\n' && i <= 1){
				lock=1;
			}
			if(c =='*'){
				i++;
				//printf("\n");
				lock=0;
			}
			if(lock==1){
				putchar(c);
			}

		}//cierre while
		printf("\n-------------------------------------\n");

}


void RegistrarUsuario(char *usu){// almacena todos los id de los usuarios
	FILE *f;
	f=fopen("Lista_Usuarios.txt","a");
	fputs(usu,f);
	fputc('\n',f);

}
void Desplegar(){// despliega todos los usuarios del sistema
	FILE *f;
	int c=0;
	f=fopen("Lista_Usuarios.txt","r");
	printf("Usuarios Disponibles en el sistema:\n");
	while ((c = getc(f)) != EOF){
		putchar(c);

	}
	char usuario[30];
	printf("\nIngrese el nombre del usuario que desea consultar:\n");
	scanf("%s",usuario);
	//printf("%s",usuario);
	strcat(usuario,".txt");
	//printf("%s",usuario);
	ImprimirC(usuario);
}

char *LeerLlavePublica(){//copia todo el contenido de un txt en este caso las llaves
		FILE *f;
		char *nombre = "public.pem";
		int cont=0, c=0;
	f=fopen(nombre,"r");
	char *puntero=(char *) malloc(2048);
	while ((c = getc(f)) != EOF){
			*puntero=c;
			puntero++;
			cont++;

			//putchar(c);
		}//cierre while

		*puntero='\0';
		puntero=puntero-(cont);
		remove(nombre);
		return puntero;

}
char *ObtenerOriginalTxt(char *nombre){
	FILE *f;

	int cont=0, c=0;
	f=fopen(nombre,"r");
	char *puntero=(char *) malloc(2048);
	while ((c = getc(f)) != EOF){
			*puntero=c;
			puntero++;
			cont++;

		//putchar(c);
	}//cierre while
	*puntero='\0';
	puntero=puntero-(cont);
	remove(nombre);
	return puntero;
}

char *ObtenerTexto(char *nombre){
	FILE *f;

	int cont = 0, c = 0, cont2 = 0;
	f = fopen(nombre,"r");

	char *puntero = (char *) malloc(2048);
	while ((c = getc(f)) != EOF){
		if(c=='!'){
			break;
		}
		if(cont2 >= 1){
			*puntero = c;
			puntero ++;
			cont ++;
		}
		if(c == '\n'){
			cont2 ++;
		}

	}
	puntero --;
	*puntero = '\0';
	puntero = puntero - (cont - 1);
	return puntero;
}
char *LeerLlavePrivada(){//copia todo el contenido de un txt en este caso las llaves
		FILE *f;
		char *nombre = "private.pem";
		int cont=0, c=0;
	f=fopen(nombre,"r");
	char *puntero=(char *) malloc(2048);
	while ((c = getc(f)) != EOF){
			*puntero=c;
			puntero++;
			cont++;

			//putchar(c);
		}//cierre while
		*puntero='\0';
		puntero=puntero-(cont);
		remove(nombre);
		return puntero;

}

char *GetFirma(char *nombre){
	FILE *f;
		int cont=0, c=0,lock=0, cont2 = 0;
	f=fopen(nombre,"r");
	char *puntero=(char *) malloc(2048);
	while ((c = getc(f)) != EOF){
		if(c=='*'){
			break;
		}
		if(c=='!'){
			lock=1;
		}
		if(lock==1 && cont2 == 1){
			*puntero=c;
			puntero++;
			cont++;
		}
		if(c =='\n' && lock == 1){
			cont2 =1;
		}

	}//cierre while
	puntero--;
	*puntero='\0';
	puntero=puntero-(cont-1);
	return puntero;
}
