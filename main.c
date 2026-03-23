#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int size = 0;
    char abc_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char abc_lower[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%&*()-_+=[],.;:{}";

    // initialize the seed
    srand(time(NULL));

    // asks size of password, asks for another number if length is less than 8, creates string 'password' and guarantees there is at least one of each possible character
    printf("Enter the size of your desired password: \n");
    scanf("%d", &size);

    while (size < 8) {
        printf("Password shouldn't have less than 8 characters. Try again: \n");
        scanf("%d", &size);
    }

    char password[size + 1];

    password[0] = abc_upper[rand() % 26];
    password[1] = abc_lower[rand() % 26];
    password[2] = numbers[rand() % 10];
    password[3] = symbols[rand() % 21];

    // draw a number to generate each character of the password; after the loop, guarantees the password ends with '\0'
    for (int i = 4; i < size; i++) {
        int temp = rand() % 4;
        switch (temp)
        {
        case 0:
            password[i] = abc_upper[rand() % 26];
            break;
        case 1:
            password[i] = abc_lower[rand() % 26];
            break;
        case 2:
            password[i] = numbers[rand() % 10];
            break;
        case 3:
            password[i] = symbols[rand() % 21];
            break;
        default:
            break;
        }
    }
    password[size] = '\0';

    // change the order of the chosen characters
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        char aux = password[i];
        password[i] = password[j];
        password[j] = aux;
    }

    // prints final password
    printf("Your password is: %s\n", password);

    return 0;
}