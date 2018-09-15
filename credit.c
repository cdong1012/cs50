#include <stdio.h>
#include <cs50.h>
#include <math.h>

int createLs(int len, int list);
int main(void){
    long credNum = get_long_long("Number: "); // get the card number
    int nDigits = floor(log10(labs(credNum))) + 1; // get the total digits of the card number
    if(nDigits < 13){
        printf("INVALID\n");
        return 0;
    }

    long arr[nDigits]; // create an array named arr of the card numbers for easier manipulation
    int counter = 0;
    long list = credNum;
    for(int i = nDigits;i > 0;i--){
        long num = list/(long)(pow(10,i-1));
        arr[counter] = num;
        list = list-(long)(num*pow(10,i-1));
        counter++;
    }
    string name;

    //first check(type of card)
    long type = arr[0]*10 + arr[1];
    if(type == 34 || type == 37){
        if(nDigits == 15){
            name = "AMEX";
        } else {
            printf("INVALID\n");
            return 0;
        }
    } else if(type == 51 || type == 52 || type == 53 || type == 54 || type == 55){
        if(nDigits == 16){
            name = "MASTERCARD";
        } else {
            printf("INVALID\n");
            return 0;
        }
    } else if(arr[0] == 4) {
        if(nDigits == 13 || nDigits == 14 || nDigits == 15 || nDigits == 16){
            name = "VISA";
        } else {
            printf("INVALID\n");
            return 0;
        }
    } else {
        printf("INVALID\n");
        return 0;
    }
    long sum;
    //Math test 1: every other digit in arr2
    long arr2[nDigits/2];
    if(nDigits%2 != 0){
        int counter2 = 1;
        for(int i = 0;i < nDigits/2;i++){
            arr2[i] = arr[counter2]*2;
            counter2 = counter2 + 2;
        }
    } else {
        int counter2 = 0;
        for(int i = 0;i < nDigits/2;i++){
            arr2[i] = arr[counter2]*2;
            counter2 = counter2 + 2;
        }
    }

    //Math test 2: sum of every other digits
    sum = 0;
    for(int i = 0;i < nDigits/2;i++){
        if(arr2[i] >= 10){
            sum += arr2[i]%10 + 1;
        } else {
            sum += arr2[i];
        }
    }

    // Math test 3: add sum to every digits not in arr2
    if(nDigits%2 != 0){
        for(int i = 0;i < nDigits;i = i + 2){
            sum += arr[i];
        }
    } else {
        for(int i = 1;i < nDigits;i = i + 2){
            sum += arr[i];
        }
    }

    if(sum%10 == 0){
        printf("%s\n",name);
        return 0;
    } else {
        printf("INVALID\n");
        return 0;
    }
}
