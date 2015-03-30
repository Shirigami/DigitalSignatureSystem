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

RSA *createRSA(char* key,int public);
// Generacion de llaves
void RSA_keys(int bits, char **priKey, char **pubKey, RSA **keyPair);

// Encriptando con public key
int public_encrypt(unsigned char *dato, int dato_len, unsigned char *encrypted,char *publicKey);

// Desencriptando con private key
int private_decrypt(unsigned char *enc_dato, int data_len,
           char *key, unsigned char *decrypted);

void RSA_keys2(int bits);
#endif
