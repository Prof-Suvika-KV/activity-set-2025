//6. Write a C program to compare three numbers using **pass by reference**
#include <stdio.h>
int input(int *a, int *b, int *c);
void compare(int a, int b, int c, int *largest);
void res(int a, int b, int c, int largest);
int main()
{
    int a, b, c, largest;
    input(&a, &b, &c);
    compare(a, b, c, &largest);
    res(a, b, c, largest);
    return 0;   
}
int input(int *a, int *b, int *c)
{
    printf("Enter three numbers: ");
    scanf("%d %d %d", a, b, c);
}   
void compare(int a, int b, int c, int *largest)
{
    if (a > b && a > c)
        *largest = a;
    else if (b > a && b > c)
        *largest = b;
    else
        *largest = c;
}   
void res(int a, int b, int c, int largest)
{
    printf("The largest number among %d, %d and %d is %d", a, b, c, largest);
}   