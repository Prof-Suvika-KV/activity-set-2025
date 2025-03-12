//12. Write a C program to find the sum of _n_ complex numbers
#include <stdio.h>
#include <stdlib.h>
struct _complex {
	float real,imaginary;
};
typedef struct _complex Complex;
int get_n();
Complex input_complex();
void input_n_complex(int n, Complex c[n]);
Complex add(Complex a, Complex b);
Complex add_n_complex(int n, Complex c[n]);
void output(int n, Complex c[n], Complex result);
int main() {
    int n;
    n = get_n();
    Complex c[n], result;
    input_n_complex(n, c);
    result = add_n_complex(n, c);
    output(n, c, result);
    return 0;
}
int get_n() {
    int n;
    printf("Enter the number of complex numbers: ");
    scanf("%d", &n);
    return n;
}
Complex input_complex() {
    Complex c;
    printf("Enter the real part: ");
    scanf("%f", &c.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c.imaginary);
    return c;
}
void input_n_complex(int n, Complex c[n]) {
    for (int i = 0; i < n; i++) {
        printf("Enter the real and imaginary part of complex number %d:\n", i + 1);
        c[i] = input_complex();
    }
}
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}
Complex add_n_complex(int n, Complex c[n]) {
    Complex result = {0, 0};
    for (int i = 0; i < n; i++) {
        result = add(result, c[i]);
    }
    return result;
}
void output(int n, Complex c[n], Complex result) {
    printf("The sum of ");
    for (int i = 0; i < n; i++) {
        printf("%.2f + %.2fi", c[i].real, c[i].imaginary);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf(" is %.2f + %.2fi\n", result.real, result.imaginary);
}