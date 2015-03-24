#include "RSAencription.h"

// Recodar liberar free(pem_key)

char *llavePrivada(int tamano){
  const int kExp = 3;
  int keylen;
  char *pem_key;

  RSA *rsa = RSA_generate_key(tamano, kExp, 0, 0);

  /* To get the C-string PEM form: */
  BIO *bio = BIO_new(BIO_s_mem());
  PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);

  keylen = BIO_pending(bio);
  pem_key = calloc(keylen+1, 1); /* Null-terminate */
  BIO_read(bio, pem_key, keylen);

  BIO_free_all(bio);
  RSA_free(rsa);
  return pem_key;


}
//const int tamano = 2048;
