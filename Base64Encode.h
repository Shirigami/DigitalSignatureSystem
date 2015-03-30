#ifndef Base64Decode_h
#define Base64Decode_h

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int Base64Encode(const char* message, char** buffer);

#endif
