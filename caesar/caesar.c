#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc == 2) // if the user types in 2 words at the command line (0 is the file name, 1 is the next word. that == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else // if the user does not type in 2 words at the command line,
    {
        printf("ERROR: User must type in just two command-line arguements\n");
        return 1;
    }








}