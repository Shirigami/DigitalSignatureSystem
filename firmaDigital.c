#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main(int argc, char const *argv[]) {
  const int kBits = 2048;
  const int kExp = 3;

  int keylen;
  char *pem_key;

  RSA *rsa = RSA_generate_key(kBits, kExp, 0, 0);

  /* To get the C-string PEM form: */
  BIO *bio = BIO_new(BIO_s_mem());
  PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);

  keylen = BIO_pending(bio);
  pem_key = calloc(keylen+1, 1); /* Null-terminate */
  BIO_read(bio, pem_key, keylen);

  printf("%s", pem_key);

  BIO_free_all(bio);
  RSA_free(rsa);
  free(pem_key); //

  return 0;
}
