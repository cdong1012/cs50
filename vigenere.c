#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
bool is_letter(char a);

int main(int argc, string argv[]){

    // only 1 input
    while(argc != 2){
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string k = argv[1]; // encrypt with k

    // make sure the encryption is only upper and lower case letter then convert it all to lower case
    for(int i = 0; i < strlen(k); i++){
        if(!is_letter(k[i])){
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        k[i] = toupper(k[i]);
    }

    //convert the encryptor to numbers from 0 foward
    int arr[strlen(k)];
    for(int i = 0; i < strlen(k);i++){
        arr[i] = k[i] - 'A';
    }

    string p = get_string("plain text: "); //user input for plain text

    //encryption
    int counter = 0;
    for(int i = 0; i < strlen(p); i++){
        char letter = p[i];
        if(is_letter(letter)){
            if(isupper(letter)){
                if(!isupper((char)((int)letter + arr[counter]))){
                    p[i] = (char)((int)letter + arr[counter] - 26);
                } else {
                    p[i] = (char)((int)letter + arr[counter]);
                }
            }
            if(islower(letter)){
                if(!islower((char)((int)letter + arr[counter]))){
                    p[i] = (char)((int)letter + arr[counter] - 26);
                } else {
                    p[i] = (char)((int)letter + arr[counter]);
                }
            }
            counter++;
        }
        if(counter == strlen(k)){
            counter = 0;
        }
    }
    printf("ciphertext: %s\n", p);
    return 0;
}

// check if the input character is a letter or not
bool is_letter(char a){
    if(!isupper(a)){
        if(!islower(a)){
            return false;
        }
    }
    return true;
}
