/*Falta manejar los strings con el .txt, asignar un numero de certificado, encriptar llave privada*/
#include "Almacenar.h"

// int main (){
//
// 	Usuario cliente={"2014.txt","Way","120", "1024","llavePublica","llavePrivada"};
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
	fputs("\n@ID_certificado: 1\n",f);
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
	int c=0;



		  while ((c = getc(f)) != EOF){// copia el user en el pivot
		  		fputc(c,d);
		  }
		  fclose(f);
		  fclose(d);
		  f = fopen(doc,"r+");
		  d = fopen(doc,"r");
		  c = 0;
		   while ((c = getc(d)) != EOF){// rellena cn llaves nuevas
		   	if(c=='@'){
		   		fputs("\n@ID_Certificado:\n",f);
		   		fputs("$Public Key\n",f);
		   		fputs(puk,f);
		   		fputc('\n',f);
		   		fputs("*Private Key\n",f);
		   		fputs(prk,f);
		   		fputs("\n!Llaves revocadas:\n",f);
		// //
		   	}
		  		fputc(c,f);

		}
		fclose(f);
		fclose(d);
		remove(pivot);



}

void FirmarDoc(char *doc, char *firma, char *id){//crea el doc firmado
	FILE *f, *d;
	int c=0;
	//char *extension="_signed";
	//strcat(doc,extension);
	//printf("%s\n",doc );
	char *nombre="archivo_firmado.txt";
	f=fopen(nombre,"a");
	d=fopen(doc,"r");
	fputs("Texto original:\n",f);
	while ((c = getc(d)) != EOF){
		fputc(c,f);
	}
	fputc('\n',f);
	fputs("!Firma Digital:\n",f);
	fputs(firma,f);
	fputc('\n',f);
	fclose(f);
	//strcat(id,".txt");

}



char *GetPin(char *doc){// obtiene el pin del usuario
	FILE *f;
	char *pin;
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
	int lock=0, i=0, c=0, lock2=0, cont=0, cont2=0;
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
	int lock=0, i=0, c=0, lock2=0, cont=0;
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
	int lock=0, i=0, c=0, lock2=0, cont=0,cont2=0;
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
		if(c=='\n' && cont>7){
			break;
		}

		if(c=='\n'){
			cont++;
		}
		if(cont==7){
			cont2++;
		}

		if(cont==7 && cont2>=14){
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
	char *nom=GetIDU(Texto);
	char *idc=GetIDC(nom);
	char *idt=GetIDC(Texto);
	if(*idc==*idt){
		return 1;
	}
	else{return 0;}

}
