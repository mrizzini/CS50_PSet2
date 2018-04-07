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

    string userHashed = argv[1];
    string test;
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char salt[2];
    salt[0] = userHashed[0];
    salt[1] = userHashed[1];

    for (int i = 0; i < 52; i++)

    {
        char guess[2];
        guess[0] = alphabet[i];
        guess[1] = '\0';
        test = crypt(guess, salt);

        if (strcmp(userHashed, test) == 0)
        {
            printf("userHashed is %s and alpha is %s and crypt is %s\n", userHashed, guess, test);
            return 0;
        }
    }

    for (int j = 0; j < 52; j++)
    {
        char guessTwo[3];
        guessTwo[0] = alphabet[j];

        for (int k = 0; k < 52; k++)
        {
            guessTwo[1] = alphabet[k];
            guessTwo[2] = '\0';
            test = crypt(guessTwo, salt);

            if (strcmp(userHashed, test) == 0)
            {
                printf("userHashed is %s and alpha is %s and crypt is %s\n", userHashed, guessTwo, test);
                return 0;
            }
        }
    }

    for (int l = 0; l < 52; l++)
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
                    printf("userHashed is %s and alpha is %s and crypt is %s\n", userHashed, guessThree, test);
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
                        printf("userHashed is %s and alpha is %s and crypt is %s\n", userHashed, guessFour, test);
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
                            printf("userHashed is %s and alpha is %s and crypt is %s\n", userHashed, guessFive, test);
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