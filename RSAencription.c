#include "RSAencription.h"

/* Generacion de las llaves publica y privada
Los bits puede ser 1024 o 2048 segun que tan segura quiere la llave
Para obtener las llaves char *privateKey, *publicKey; y enviar la referencia &
*/
//openssl rsautl -encrypt -pubin -inkey public.pem -in myLargeFile.xml -out myLargeFile_encrypted.xml
RSA *createRSA(char* key,int public)
{
    //key = "-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCp2w+8HUdECo8V5yuKYrWJmUbL\ntD6nSyVifN543axXvNSFzQfWNOGVkMsCo6W4hpl5eHv1p9Hqdcf/ZYQDWCK726u6\nhsZA81AblAOOXKaUaxvFC+ZKRJf+MtUGnv0v7CrGoblm1mMC/OQI1JfSsYi68Epn\naOLepTZw+GLTnusQgwIDAQAB\n-----END PUBLIC KEY-----\n";
    RSA *rsa = NULL;
    BIO *keybio;
    keybio = BIO_new_mem_buf(key, -1);

    if (keybio==NULL)
    {
        printf( "Error al crear la llave BIO");
        return 0;
    }
    if(public)
    {
        rsa = PEM_read_bio_RSA_PUBKEY(keybio,&rsa,NULL, NULL);
    }
    else
    {
        rsa = PEM_read_bio_RSAPrivateKey(keybio,&rsa,NULL, NULL);
    }
    if(rsa == NULL){

      printf("Error al crear el rsa");
    }

    return rsa;
}

void RSA_keys2(int bits){

  if(bits == 1024){

      system("openssl genrsa -out private.pem 1024");

  }

  else{
    system("openssl genrsa -out private.pem 2048");
  }
  system("openssl rsa -in private.pem -out public.pem -outform PEM -pubout");
  //system("clear");
}


void RSA_keys(int bits, char **priKey, char **pubKey, RSA **keyPair){


  const int numExp = 3; // Exponentee

  *keyPair = RSA_generate_key(bits, numExp, NULL, NULL); // Creacion de la llave par

  BIO *private = BIO_new(BIO_s_mem());
  BIO *public = BIO_new(BIO_s_mem());

  //Generacion de las llaves publicas y privadas segun la llave par
  PEM_write_bio_RSAPrivateKey(private, *keyPair, NULL, NULL, 0, NULL, NULL);
  PEM_write_bio_RSAPublicKey(public, *keyPair);

  // Tamano de las llaves
  size_t privateLeng = BIO_pending(private);
  size_t publicLeng = BIO_pending(public);

  // Se le asigna memoria a las variables
  *priKey = malloc(privateLeng + 1);
  *pubKey = malloc(publicLeng + 1);

  BIO_read(private, *priKey, privateLeng);
  BIO_read(public, *pubKey, publicLeng);

  (*priKey)[privateLeng] = '\0';
  (*pubKey)[publicLeng] = '\0';

}

/* Encripta un char con la llave publica
Recibe como parametro el dato, se debe asignar un arreglo de char -- char msg[] = {"hola"};
Tamano del mensaje, --- int msg_len = strlen(msg);
La llave publica y una variable que almacene el dato encriptado -- char *msgEncryp = (char*)malloc(2048);
Estructura rsa, osea la llave par
*/
// Retorna un numero negativo si no logra encriptar el mensaje
int public_encrypt(unsigned char *dato, int dato_len, unsigned char *encrypted,char *publicKey){


  int padding = RSA_PKCS1_PADDING; // padding
  int result = 0;
  RSA *rsa =  createRSA(publicKey,1);

  result = RSA_public_encrypt(dato_len,dato,encrypted,rsa,padding);
  return result;
}
/* Desencripta un char con la llave privada
Recibe el dato  -- char *msgEncryp = (char*)malloc(2048);
el tamano del dato, que es lo que retorna la funcion public_encrypt
la llave privada y una variable para almacenar el mensaje desencriptado
char *msgDecrypted = (char*)malloc(2048);
ademas de una estructura rsa (llave par)
*/

int private_decrypt(unsigned char *enc_dato, int data_len,
    char *privateKey, unsigned char *decrypted){

  int padding = RSA_PKCS1_PADDING;
  int result = 0;
  RSA *rsa = createRSA(privateKey,0);

  result = RSA_private_decrypt(128,enc_dato,decrypted,rsa,padding);


  return result;
}
