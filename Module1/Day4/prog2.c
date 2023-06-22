#include <stdio.h>

typedef struct {
    double real;
    double imaginary;
} ComplexNumber;


void readComplexNumber(ComplexNumber* num) {
    printf("Enter the real part: ");
    scanf("%lf", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%lf", &(num->imaginary));
}


void writeComplexNumber(const ComplexNumber* num) {
    printf("Complex Number: %.2f + %.2fi\n", num->real, num->imaginary);
}


ComplexNumber addComplexNumbers(const ComplexNumber* num1, const ComplexNumber* num2) {
    ComplexNumber sum;
    sum.real = num1->real + num2->real;
    sum.imaginary = num1->imaginary + num2->imaginary;
    return sum;
}


ComplexNumber multiplyComplexNumbers(const ComplexNumber* num1, const ComplexNumber* num2) {
    ComplexNumber product;
    product.real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    product.imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
    return product;
}

int main() {
    ComplexNumber num1, num2;

    printf("Enter the first complex number:\n");
    readComplexNumber(&num1);

    printf("Enter the second complex number:\n");
    readComplexNumber(&num2);


    printf("First Complex Number:\n");
    writeComplexNumber(&num1);

    printf("Second Complex Number:\n");
    writeComplexNumber(&num2);


    ComplexNumber sum = addComplexNumbers(&num1, &num2);
    printf("Sum of the complex numbers:\n");
    writeComplexNumber(&sum);

    ComplexNumber product = multiplyComplexNumbers(&num1, &num2);
    printf("Product of the complex numbers:\n");
    writeComplexNumber(&product);

    return 0;
}
