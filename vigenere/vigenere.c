#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2) // if the user does not type in 2 words at the command line, print error and return 1, exiting program
    {
        printf("ERROR: User must type in just two command-line arguments, with the second being alphabetical characters\n");
        return 1;
    }

    string k = argv[1];
    // int kLength = strlen(k) - 1;
    int kIndex = 0;
    int upperASCII;
    int lowerASCII;
    int upperConvert;
    int lowerConvert;
    int upperK;
    int lowerK;
    int kLength = strlen(k);
    char upperCipher;
    char lowerCipher;

    for (int num = 0; num < strlen(k); num++) // for loop check if all letters of key are alphabetical
    {
        if (!isalpha(k[num]))
        {
            printf("ERROR: You must enter all alphabetical characters in command line\n");
            return 1;
        }
    }

    string plainText = get_string("plaintext: "); // prompts user for plaintext to be ciphered
    int strLen = strlen(plainText); // stores length of plaintext in variable
    printf("ciphertext: "); // prints out result

    for (int i = 0; i < strLen; i++) // for loop to iterate thru entire length of plaintext input
    {
        if (!isalpha(plainText[i])) // if the index of plaintext is NOT an alphabetic char, print it as is
        {
            printf("%c", plainText[i]);
        }

        else if (isupper(plainText[i])) // else if index of plaintext is uppercase
        {
            upperASCII = (plainText[i] - 65); // take index of p's ascii value and minus 65
            upperK = (toupper(k[kIndex]) - 65); // change the user's key's ascii value to uppercase and minus 65
            upperConvert = (upperASCII + upperK) % 26; // mod by 26
            upperCipher = upperConvert + 65; // add 65 to get ciphered letter
            kIndex++; // moves index of k up one
            kIndex = kIndex % kLength; // mod kIndex by length of k to account for wrap around

            // if (q == (kLength)) // if user's key is equal to kLength (which is kLength - 1)
            // {
            //     q = 0; // then set q to 0. this accounts for wraparound of user's key
            // }
            // else
            // {
            //     q++; // else, move up one index of key
            // }

            printf("%c", upperCipher); // print final ciphered text
        }

        else if (islower(plainText[i])) // same as above else if but accounts for lower case plain text
        {
            lowerASCII = (plainText[i] - 97);
            lowerK = (toupper(k[kIndex]) - 65);
            lowerConvert = (lowerASCII + lowerK) % 26;
            lowerCipher = lowerConvert + 97;
            kIndex++;
            kIndex = kIndex % kLength;

            // if (q == (kLength))
            // {
            //     q = 0;
            // }
            // else
            // {
            //     q++;
            // }

            printf("%c", lowerCipher);
        }
    } // ends for loop for i

    printf("\n"); // prints new line
    return 0; // this line is not needed but it is good clarity
}