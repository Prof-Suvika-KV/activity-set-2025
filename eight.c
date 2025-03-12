//8. Write a C program to find sum of _n_ different numbers entered by the user.
#include <stdio.h>
int input_array_size();
void input_array(int n, int a[n]);
int sum_n_array(int n, int a[n]);
void output(int n, int a[n],int sum);
int main()
{
    int n, sum;
    n = input_array_size();
    int a[n];
    input_array(n, a);
    sum = sum_n_array(n, a);
    output(n, a, sum);
    return 0;
}
int input_array_size()
{
    int n;
    printf("Input array size: ");
    scanf("%d", &n);
    return n;
}
void input_array(int n, int a[n])
{
    printf("Input the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
int sum_n_array(int n, int a[n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
void output(int n, int a[n], int sum)
{
    printf("The sum of ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf("+");
    }
    printf(" is %d", sum);
}