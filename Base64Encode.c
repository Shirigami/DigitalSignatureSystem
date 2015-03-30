#include "Base64Encode.h"

/*Convierte una cadena de caracteres a base64*/

int Base64Encode(const char* message, char** buffer) {
  BIO *bio, *b64;
  FILE* stream;
  int encodedSize = 4*ceil((double)strlen(message)/3);
  *buffer = (char *)malloc(encodedSize+1);

  stream = fmemopen(*buffer, encodedSize+1, "w");
  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new_fp(stream, BIO_NOCLOSE);
  bio = BIO_push(b64, bio);
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
  BIO_write(bio, message, strlen(message));
  BIO_flush(bio);
  BIO_free_all(bio);
  fclose(stream);

  return (0);
}
