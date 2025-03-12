//3. Write a C program to add two numbers using **pass by value**
#include <stdio.h>
int input();
int add(int a, int b);
void res(int a, int b, int sum);

int main()
{
    int a, b, sum;
    a = input();
    b = input();
    sum = add(a, b);
    res(a, b, sum);
    return 0;
}

int input()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

int add(int a, int b)
{
    return a + b;
}

void res(int a, int b, int sum)
{
    printf("The sum of %d and %d is %d", a, b, sum);
}