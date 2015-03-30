#include "cifradoCesar.h"

char *cifrado(char *prikey,int key){ 
     
    int i;
    int j; 
     
    for(i = 0; i < strlen(prikey); i++){ 
        for(j=0; j < key ; j++){

            if((prikey[i] >= 65 && prikey[i] < 90) || (prikey[i] >= 97 && prikey[i] < 122)){ 
                prikey[i]++;                
            } 

            else if(prikey[i] == 90) 
                prikey[i] = 65; 
            else if(prikey[i] == 122) 
                prikey[i] = 97; 
        } 
    } 
    return prikey; 
} 
 

char *descifrado(char *prikeyEncrypted,int key){ 
     
    int i;
    int j; 
     
    for( i=0 ; i < strlen(prikeyEncrypted); i++){ 
        for(j = 0;j < key;j++){ 
            if((prikeyEncrypted[i] > 65 && prikeyEncrypted[i] <= 90) || (prikeyEncrypted[i]> 97 && prikeyEncrypted[i] <= 122)){ 
                prikeyEncrypted[i]--;                
            } 
            else if(prikeyEncrypted[i] == 65) 

                prikeyEncrypted[i]=90;

            else if( prikeyEncrypted[i] == 97)

                prikeyEncrypted[i] =  122; 
        } 
    } 
    return prikeyEncrypted; 
} 


/*

int main(int argc, char const *argv[])
{
    char cifrar[]= "MIICXAIBAAKBgQCsvbA3hJPuJy2JBxjaCpTrnBxJS8hY+6FTRYLcMRx1za3Vfc26VpSaXysHmBxb8dWoyviRlnltCr1+5ySyQSQvK6mcnQkxDJYGdGDG5uKQX97aiqjMWzdBu8glSpmvY/AHHxyfAv/j/NvSd47Wf7P0CoN87zlVp/ryDeIvyOKHowIDAQABAoGANkE937IcZGiZvLgl7hX0wCvAFqVev9QIz4a9mzsxnS6EstFYlHYtJm9NrIzyG07RtLpLaC7C5KTC7+DZfcNIAaSuOny6YZemtJATFEMWPQ8Gjtw7vPMp+LhKMlTON7O4k0I/ebP/NDFYpFwf/ggYH42RSzSq29Vl5rME1QqoZsECQQDWLj9dJ2nHaxOZWSE2RaI3wheEL5RZK4UK7GZ+7kXeGlUf7tynswyiyqsl9Tf8IdTz8ydxeXyL0EYhHkYrhjmXAkEAzngXXhFbl3I75mBxLfH/GtWmPJD7ulLT2FJPeS59f0O/ypyMFryrxCrzha5jA9esM06oZUw6nJfEMK0gpEHr1QJAGioQJ4sXCvtzq3oN6plbFcCqKsW9M59zY0A5zSvCcT16RKpjXkErO//SJJLuQejIIP0FRoF2y4Wn64fNPqfpBQJBAMj+YYkijq5s92D669MVbQl7iRwW6+djsHU7E8DdgDA/DNs58KpFu1T5lx3BOQTJlQpRfV83iSteFxBnyYn93o0CQAQF4MUJK2rEh/mvk2xUNsk3eHlGrW/9Q0pMvoJnwjH5";
    int x = 16723;

    printf("Frase encriptada \n");
    printf("%s\n", cifrado(cifrar,x));

    printf("\n");

    printf("Frase desencriptada \n");
    printf("%s\n", descifrado(cifrar,x));

    return 0;
}

*/


//MIICXAIBAAKBgQCsvbA3hJPuJy2JBxjaCpTrnBxJS8hY+6FTRYLcMRx1za3Vfc26VpSaXysHmBxb8dWoyviRlnltCr1+5ySyQSQvK6mcnQkxDJYGdGDG5uKQX97aiqjMWzdBu8glSpmvY/AHHxyfAv/j/NvSd47Wf7P0CoN87zlVp/ryDeIvyOKHowIDAQABAoGANkE937IcZGiZvLgl7hX0wCvAFqVev9QIz4a9mzsxnS6EstFYlHYtJm9NrIzyG07RtLpLaC7C5KTC7+DZfcNIAaSuOny6YZemtJATFEMWPQ8Gjtw7vPMp+LhKMlTON7O4k0I/ebP/NDFYpFwf/ggYH42RSzSq29Vl5rME1QqoZsECQQDWLj9dJ2nHaxOZWSE2RaI3wheEL5RZK4UK7GZ+7kXeGlUf7tynswyiyqsl9Tf8IdTz8ydxeXyL0EYhHkYrhjmXAkEAzngXXhFbl3I75mBxLfH/GtWmPJD7ulLT2FJPeS59f0O/ypyMFryrxCrzha5jA9esM06oZUw6nJfEMK0gpEHr1QJAGioQJ4sXCvtzq3oN6plbFcCqKsW9M59zY0A5zSvCcT16RKpjXkErO//SJJLuQejIIP0FRoF2y4Wn64fNPqfpBQJBAMj+YYkijq5s92D669MVbQl7iRwW6+djsHU7E8DdgDA/DNs58KpFu1T5lx3BOQTJlQpRfV83iSteFxBnyYn93o0CQAQF4MUJK2rEh/mvk2xUNsk3eHlGrW/9Q0pMvoJnwjH5