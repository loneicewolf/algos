#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int *genKey(int len){
    srand(time(0));

    int *key = (int *)malloc(len * sizeof(int));

    for(int i = 0; i < len; i++){
        key[i] = rand() % len;
    }

    return key;
}

void vernamCrypt(char *message, int *key, size_t len, char *alphabet){

    for(int i = 0; i < len; i++){
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = alphabet[((message[i] - 'a') + key[i]) % 26];
        }
    }

}

void vernamDecrypt(char *message, int *key, size_t len, char *alphabet) {

    for(int i = 0; i < len; i++){
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = alphabet[((message[i] - 'a') - key[i] + 26) % 26];
        }
    }

}

int main(void) {

    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *message = (char *)malloc(sizeof(char) * 50);
    int *key = NULL;
    size_t len = 0;

    printf("Type the message you want to encrypt: ");
    scanf("%s", message);

    len = strlen(message);
    key = genKey(len);

    printf("Original message: %s", message);

    vernamCrypt(message, key, len, alphabet);
    printf("\nEncrypted: %s", message);

    vernamDecrypt(message, key, len, alphabet);
    printf("\nDecrypted: %s", message);

    free(key);

    return 0;
}
