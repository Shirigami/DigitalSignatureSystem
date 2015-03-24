#include "RSAencription.h"

// Recodar liberar free(pem_key)
void RSA_keys(int bits, char **priKey, char **pubKey, RSA **keyPair){
//https://shanetully.com/2012/04/simple-public-key-encryption-with-rsa-and-openssl/
  const int numExp = 3; // Exponente

  *keyPair = RSA_generate_key(bits, numExp, NULL, NULL);

  BIO *private = BIO_new(BIO_s_mem());
  BIO *public = BIO_new(BIO_s_mem());

  PEM_write_bio_RSAPrivateKey(private, *keyPair, NULL, NULL, 0, NULL, NULL);
  PEM_write_bio_RSAPublicKey(public, *keyPair);

  size_t privateLeng = BIO_pending(private);
  size_t publicLeng = BIO_pending(public);

  *priKey = malloc(privateLeng + 1);
  *pubKey = malloc(publicLeng + 1);

  BIO_read(private, *priKey, privateLeng);
  BIO_read(public, *pubKey, publicLeng);

  (*priKey)[privateLeng] = '\0';
  (*pubKey)[publicLeng] = '\0';

}

char *RSA_encrypt(char msg[],RSA *keypair){

  // Encrypt the message
  char *encrypt = malloc(RSA_size(keypair));
  RSA_public_encrypt(strlen(msg)+1,(unsigned char*) msg,
          (unsigned char*) encrypt, keypair, RSA_PKCS1_OAEP_PADDING);

  return encrypt;
}
