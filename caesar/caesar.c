#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2) // if the user does not type in 2 words at the command line, print error and return 1, exiting program
    {
        printf("ERROR: User must type in just two command-line arguements, with the second being a non-negative integer\n");
        return 1;
    }

    int k = atoi(argv[1]);
    int upperASCII;
    int lowerASCII;
    int upperConvert;
    int lowerConvert;
    char upperCipher;
    char lowerCipher;
    // int test = 'A';

    // if the user types in 2 words at the command line (0 is the file name, 1 is the next word. that == 2) then run rest of program
    // printf("Your key was, %i\n", k);
    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");
    // printf("Plaintext is %s", plainText);

    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        if (!isalpha(plainText[i]))
        {
            printf("%c", plainText[i]);
        }

        if (isupper(plainText[i]))
        {
            // printf("%c was uppercase\n", plainText[i]);
            upperASCII = (plainText[i] - 65);
            upperConvert = (upperASCII + k) % 26;
            upperCipher = upperConvert + 65;
            printf("%c", upperCipher);
            // printf("%c is upper cipher\n", upperCipher);
            // printf("%i is upper ASCII\n", upperASCII);
            // printf("%i is upper convert\n", upperConvert);
        }
        if (islower(plainText[i]))
        {
            lowerASCII = (plainText[i] - 97);
            lowerConvert = (lowerASCII + k) % 26;
            lowerCipher = lowerConvert + 97;
            printf("%c", lowerCipher);
            // printf("%i is lower ASCII\n", lowerASCII);
            // printf("%i is lower convert\n", lowerConvert);
            // printf("%c is lower cipher\n", lowerCipher);
            // printf("%c was lowercase\n", plainText[i]);
            // printf("%i\n", test);
        }
    }

    printf("\n");
    return 0; // this line is not needed but it is good clarity
    // type echo $? in command-line after program runs to see what exit code a program exited
}