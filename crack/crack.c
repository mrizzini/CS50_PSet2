#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2) // if the user does not type in 2 words at the command line, print error and return 1, exiting program
    {
        printf("ERROR: User must type in just two command-line arguments, with the second being a hashed password\n");
        return 1;
    }

    string userHashed = argv[1]; // stores the user's hashed password
    string test; // initializes test string to be used to test later.
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char salt[2]; // initializes an array of length 2 to store salt of user's input
    salt[0] = userHashed[0]; // declares the first element of salt
    salt[1] = userHashed[1]; // declares second element of salt. now salt = [userHashed0, userHashed1]

    for (int i = 0; i < 52; i++) // first for loop to loop thru alphabet a-z and A-Z

    {
        char guess[2]; // initializes array for our guess. length of 2.
        guess[0] = alphabet[i]; // first element of guess is going to be a, b, c, d, etc.
        guess[1] = '\0'; // this represents the end of the string array. automatically added to every string. it is a nulll character. need single quotes b/c it is a character
        // guess will be our guess as to what the password will be. it will be a\0, b\0, c\0, etc. the \0 is added in automatically so this accounts for that
        test = crypt(guess, salt); // crypt will hash our password and store it into test.

        if (strcmp(userHashed, test) == 0) // this compares our test to the user's hashed password. if they match, it will = 0.
        {
            printf("%s\n", guess); // then we print out the guess b/c we know it is right
            return 0; // exits the program
        }
    }

    for (int j = 0; j < 52; j++) // loops thru a-z and A-Z
    {
        char guessTwo[3]; //initializes guessTwo as a 3 element array
        guessTwo[0] = alphabet[j]; // declares first letter of guessTwo as a to start then goes to next for loop

        for (int k = 0; k < 52; k++) // loops thru a-z and A-Z
        {
            guessTwo[1] = alphabet[k]; // at first, the second letter of guessTwo is a
            guessTwo[2] = '\0'; // adds \0 to finish the array
            test = crypt(guessTwo, salt); // first tests aa as test

            if (strcmp(userHashed, test) == 0) // if it matches, then we go to print it. if not, the aa becomes ab then we start over. then ac. eventually ba, bb, bc
            {
                printf("%s\n", guessTwo); // then we print out the guess b/c we know it is right
                return 0;
            }
        }
    }

    for (int l = 0; l < 52; l++) // next for loop checks as follows: aaa, aab, aac, etc. then aba, abb, abc, abd, etc. then baa, bab, bac, etc. then caa, cab, cac, etc.
    {
        char guessThree[4];
        guessThree[0] = alphabet[l];

        for (int m = 0; m < 52; m++)
        {
            guessThree[1] = alphabet[m];

            for (int n = 0; n < 52; n++)
            {
                guessThree[2] = alphabet[n];
                guessThree[3] = '\0';
                test = crypt(guessThree, salt);

                if (strcmp(userHashed, test) == 0)
                {
                    printf("%s\n", guessThree); // then we print out the guess b/c we know it is right
                    return 0;
                }
            }
        }
    }

    for (int o = 0; o < 52; o++)
    {
        char guessFour[5];
        guessFour[0] = alphabet[o];

        for (int p = 0; p < 52; p++)
        {
            guessFour[1] = alphabet[p];

            for (int q = 0; q < 52; q++)
            {
                guessFour[2] = alphabet[q];

                for (int r = 0; r < 52; r++)
                {
                    guessFour[3] = alphabet[r];
                    guessFour[4] = '\0';
                    test = crypt(guessFour, salt);

                    if (strcmp(userHashed, test) == 0)
                    {
                        printf("%s\n", guessFour); // then we print out the guess b/c we know it is right
                        return 0;
                    }
                }
            }
        }
    }

    for (int s = 0; s < 52; s++) // t u v w x
    {
        char guessFive[6];
        guessFive[0] = alphabet[s];

        for (int t = 0; t < 52; t++)
        {
            guessFive[1] = alphabet[t];

            for (int u = 0; u < 52; u++)
            {
                guessFive[2] = alphabet[u];

                for (int v = 0; v < 52; v++)
                {
                    guessFive[3] = alphabet[v];

                    for (int w = 0; w < 52; w++)
                    {

                        guessFive[4] = alphabet[w];
                        guessFive[5] = '\0';
                        test = crypt(guessFive, salt);

                        if (strcmp(userHashed, test) == 0)
                        {
                            printf("%s\n", guessFive); // then we print out the guess b/c we know it is right
                            return 0;
                        }
                    }
                }
            }
        }
    }

}

// PASSWORDS
// anushree:50xcIMJ0y.RXo - YES
// brian:50mjprEcqC/ts - CA
// bjbrown:50GApilQSG3E2 - UPenn
// lloyd:50n0AAUD.pL8g - lloyd
// malan:50CcfIk1QrPr6 - maybe
// maria:509nVI8B9VfuA - TF
// natmelo:50JIIyhDORqMU - nope
// rob:50JGnXUgaafgc - ROFL
// stelios:51u8F0dkeDSbY - NO
// zamyla:50cI2vYkF0YU2 - LOL