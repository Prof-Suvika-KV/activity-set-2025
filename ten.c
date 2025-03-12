//10. Write a C program to compare two strings, character by character.
#include <stdio.h>
#include <string.h>
void input_two_strings(char *string1, char *string2);
int stringcompare(char *string1, char *string2);
void output(char *string1, char *string2, int result);
int main()
{
    char string1[100], string2[100];
    int result;
    input_two_strings(string1, string2);
    result = stringcompare(string1, string2);
    output(string1, string2, result);
    return 0;
}       
void input_two_strings(char *string1, char *string2)
{
    printf("Enter the first string: ");
    gets(string1);
    printf("Enter the second string: ");
    gets(string2);
}   
int stringcompare(char *string1, char *string2)
{
    return strcmp(string1, string2);
}
void output(char *string1, char *string2, int result)
{
    if (result == 0)
        printf("The strings are equal.");
    else if(result>0)
        printf("%s is greater than %s", string1, string2);
    else
        printf("%s is less than %s", string1, string2);    
}