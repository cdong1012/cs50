#define _XOPEN_SOURCE
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
char *crypt(const char *key, const char *salt);
#include <crypt.h>
char *crypt_r(const char *key, const char *salt, struct crypt_data *data);
bool compare_hash(string pass, string hash, string salty);
int main(int argc, string argv[]){

    // only 1 input
    while(argc != 2){
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hash2 = argv[1]; //the hash
    // getting the salt
    char salt2[30];
    int counter = 0;
    for(int i = 0; hash2[i] != '\0'; ++i){
        salt2[i] = hash2[i];
        counter++;
    }
    salt2[2] = '\0';

    char hash[13];
    int count = 0;
    for(int i = 0;hash2[i] != '\0';++i){
        hash[count] = hash2[i];
        count++;
    }
    printf("hash %s\n", hash);
    char salt[2] ={salt2[0],salt2[1]};
    printf("salt %s\n", salt);
    char password[7] = {'\0','\0','\0','\0','\0','\0','\0'};
    char alphabet[53] = {'Q', 'W', 'E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M','q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
    // 1 char
    for(int i = 0;i < 52;i++){
        password[0] = alphabet[i];
        printf("password: %s\n", password);
        if(compare_hash(password, hash2, salt)){
            printf("%s\n", password);
            return 0;
        }
    }

    // 2 char
    int a = 0;
    while(a < 52){
        for(int i = 0;i < 52;i++){
            password[0] = alphabet[a];
            password[1] = alphabet[i];
            printf("password: %s\n", password);
            if(compare_hash(password, hash2, salt)){
                printf("%s\n", password);
                return 0;
            }
        }
        a++;
    }

    // 3 char

    for(int b = 0;b < 52;b++) {
        int c = 0;
        while(c < 52){
            for(int i = 0;i < 52;i++){
                password[0] = alphabet[b];
                password[1] = alphabet[c];
                password[2] = alphabet[i];
                printf("password: %s\n", password);
                if(compare_hash(password, hash2, salt)){
                    printf("%s\n", password);
                    return 0;
                }
            }
            c++;
        }
    }

    //4 char
    a = 0;
    while(a < 52){
        int z = 0;
        while(z < 52){
            int c = 0;
            while(c < 52){
                for(int i = 0;i < 52;i++){
                    password[0] = alphabet[a];
                    password[1] = alphabet[z];
                    password[2] = alphabet[c];
                    password[3] = alphabet[i];
                    printf("password: %s\n", password);
                    if(compare_hash(password, hash2, salt)){
                        printf("%s\n", password);
                        return 0;
                    }
                }
                c++;
            }
            z++;
        }
        a++;
    }

    //5 char
    a = 0;
    while(a < 52){
        int p = 0;
        while(p < 52){
            int g = 0;
            while(g < 52){
                int d = 0;
                while(d < 52){
                    for(int i = 0;i < 52;i++){
                        password[0] = alphabet[a];
                        password[1] = alphabet[p];
                        password[2] = alphabet[g];
                        password[3] = alphabet[d];
                        password[4] = alphabet[i];
                        printf("password: %s\n", password);
                        if(compare_hash(password, hash, salt)){
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                    d++;
                }
                g++;
            }
            p++;
        }
        a++;
    }
}

bool compare_hash(string pass, string hash, string salty){
    string n = crypt(pass, salty);
    if(strcmp(n,hash) == 0) {
        return true;
    } else {
        return false;
    }
}
