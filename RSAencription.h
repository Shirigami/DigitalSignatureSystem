#ifndef RSAencription_h
#define RSAencription_h

/* OpenSSL headers */
//77
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdio.h>
//#include <string.h>

void RSA_keys(int bits, char **priKey, char **pubKey, RSA **keypair);

char *RSA_encrypt(char msg[],RSA *keypair);


#endif
