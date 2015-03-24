#include "RSAencription.h"

// Recodar liberar free(pem_key)
void RSA_keys(int bits, char **priKey, char **pubKey){

  const int numExp = 3; // Exponente

  RSA *keyPair = RSA_generate_key(bits, numExp, NULL, NULL);

  BIO *private = BIO_new(BIO_s_mem());
  BIO *public = BIO_new(BIO_s_mem());

  PEM_write_bio_RSAPrivateKey(private, keyPair, NULL, NULL, 0, NULL, NULL);
  PEM_write_bio_RSAPublicKey(public, keyPair);

  size_t privateLeng = BIO_pending(private);
  size_t publicLeng = BIO_pending(public);

  *priKey = malloc(privateLeng + 1);
  *pubKey = malloc(publicLeng + 1);

  BIO_read(private, *priKey, privateLeng);
  BIO_read(public, *pubKey, publicLeng);

  (*priKey)[privateLeng] = '\0';
  (*pubKey)[publicLeng] = '\0';

  // char *llavePrivada;
  //
  // RSA *rsa = RSA_generate_key(bits, numExpo, 0, 0);
  //
  // // Obtener la llave como un string
  //
  // BIO *bio = BIO_new(BIO_s_mem());
  //
  // PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
  //
  // tamLlave = BIO_pending(bio);
  //
  // llavePrivada = calloc(tamLlave+1, 1); /* Null-terminate */
  //
  // BIO_read(bio, llavePrivada, tamLlave);
  //
  // BIO_free_all(bio);
  // RSA_free(rsa);
  //
  // return llavePrivada;


}
//const int bits = 2048;
