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

RSA *createRSA(unsigned char *key,int public){
  RSA *rsa = NULL;
  BIO *keybio;
  keybio = BIO_new_mem_buf(key,-1);
  printf("entre");
  if(keybio == NULL){
    printf("Failed to create keyBIO");
  }
  if(public){
    rsa = PEM_read_bio_RSA_PUBKEY(keybio,&rsa,NULL,NULL);

  }
  else{
    rsa = PEM_read_bio_RSAPrivateKey(keybio,&rsa,NULL,NULL);

  }
  return rsa;
}

int public_encrypt(unsigned char *dato, int dato_len,
          unsigned char *publicKey, unsigned char *encrypted,RSA *rsa){

  int padding = RSA_PKCS1_PADDING;

  int result = RSA_public_encrypt(dato_len,dato,encrypted,rsa,padding);

  return result;
}

int private_decrypt(unsigned char *enc_dato, int data_len,
    unsigned char *privateKey, unsigned char *decrypted,RSA *rsa){

  int padding = RSA_PKCS1_PADDING;

  int result = RSA_private_decrypt(data_len,enc_dato,decrypted,rsa,padding);

  return result;
}

char *RSA_decrypt(char *encrypt,RSA *keypair,int *encrypt_len){

  char *decrypt = malloc(RSA_size(keypair));
  RSA_private_decrypt(*encrypt_len, (unsigned char*)encrypt, (unsigned char*)decrypt,
                       keypair, RSA_PKCS1_OAEP_PADDING);
   printf("Decrypted message: %s\n", decrypt);
   
   return decrypt;

}
