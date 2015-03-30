#ifndef Base64Decode_h
#define Base64Decode_h

//Decodes Base64
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>

int calcDecodeLength(const char* b64input);
int Base64Decode(char* b64message, char** buffer);

#endif
