#include <cs50.h>
#include <ctype.h> // gets isupper/isalpha function
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // gets strlen function

int main(void)
{

    string fullName = get_string(); // gets name from user;
    int strLength = strlen(fullName); // stores length of name
    char initials[4]; // initializes array of chars to store 3 initials. \0 is the 4th
    int counter = 0; // counter to keep track of index in initials array
    initials[0] = toupper(fullName[counter]); // stores first index of fullName to first index of initials array, as a capital char
    counter++; // sets counter int to 1

    for (int i = 1; i < strLength; i++) // for loop to iterate thru length of name. starts at 1 since we already accounted for 0 above
    {
        if (!isalpha(fullName[i])) // this checks for the first time a non alphabetical char hits (should be the space in the name)
        {
            initials[counter] = toupper(fullName[i + 1]); // adds in the char AFTER the first nonalpha. sets to initials array
            counter++; // increments counter only after a letter is stored in there
        }
    }

    initials[counter] = '\0'; // sets the end of the array. need to use couter b/c we don't know how many names user will input.
    printf("%s\n", initials); // prints initials array with new line

}