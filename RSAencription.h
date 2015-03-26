#ifndef RSAencription_h
#define RSAencription_h

/* OpenSSL headers */
#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <string.h>

// Generacion de llaves
void RSA_keys(int bits, char **priKey, char **pubKey, RSA **keypair);
// Creacion de la estructura RSA, si es public enviar por parametro
// numero diferente a 0
RSA *createRSA(unsigned char *key,int public);
// Encriptando con public key
int public_encrypt(unsigned char *dato, int dato_len,
          unsigned char *publicKey, unsigned char *encryted,RSA *rsa);

// Desencriptando con private key
int private_decrypt(unsigned char *enc_dato, int data_len,
          unsigned char *key, unsigned char *decrypted,RSA *rsa);


char *RSA_decrypt(char *encrypt,RSA *keypair,int *encrypt_len);



#endif
