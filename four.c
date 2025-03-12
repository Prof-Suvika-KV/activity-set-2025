//4. Write a C program to add two numbers using **pass by reference**
#include<stdio.h>
void input(int *a, int *b);
void add(int a, int b, int *sum);
void res(int a, int b, int sum);
int main()
{
    int a, b, sum;
    input(&a, &b);
    add(a, b, &sum);
    res(a, b, sum);
    return 0;
}
void input(int *a, int *b)
{
    printf("Enter two numbers: ");
    scanf("%d%d",a,b);
}
void add(int a, int b, int *sum)
{
    *sum = a + b;
}
void res(int a, int b, int sum)
{
    printf("The sum of %d and %d is %d", a, b, sum);
}