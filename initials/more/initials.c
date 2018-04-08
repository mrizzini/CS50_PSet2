#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    string fullName = get_string(); // gets name from user
    int strLength = strlen(fullName); // stores length of name
    char initials[4];
    int counter = 0;
    // initials[0] = fullName[counter];
    // counter++;

    if (isalpha(fullName[counter])) // checks if first char in string is alphabetical, if it is, it is printed
    {
        // printf("%c", toupper(fullName[0])); // prints upper case
        initials[counter] = toupper(fullName[counter]);
        counter++;
    }

    for (int i = 0; i < strLength; i++) // for loop to iterate thru length of name
    {

        if (!isalpha(fullName[i])) // checks for non-alphabetical characters. if it is a space, it
        {
            if (isalpha(fullName[i + 1])) // checks for character AFTER the space. if it is alphabetical, it prints
            {
                // printf("%c", toupper(fullName[i + 1])); // prints uppercase char after space if it is alphabetical
                initials[counter] = toupper(fullName[i + 1]);
                counter++;
            } // ends second IF
        } // ends first IF

    } // ends for loop

    initials[counter] = '\0';
    printf("%s\n", initials); // prints new line
}