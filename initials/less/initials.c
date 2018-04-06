#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    string fullName = get_string(); // gets name from user
    int strLength = strlen(fullName); // stores length of name

    printf("%c", toupper(fullName[0])); // prints out the first character of the name

    for (int i = 0; i < strLength; i++) // for loop to iterate thru length of name
    {
        if (!isalpha(fullName[i])) // this checks for the first time a non alphabetical char hits (should be the space in the name)
        {
            printf("%c", toupper(fullName[i + 1])); // prints the first char after the space
        }
    }

    printf("\n"); // prints new line

}