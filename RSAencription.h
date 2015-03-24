#ifndef RSAencription_h
#define RSAencription_h

/* OpenSSL headers */

#include <openssl/ssl.h>
#include "openssl/ssl.h"
#include "openssl/err.h"

void RSA_keys(int bits, char **priKey, char **pubKey);


#endif
