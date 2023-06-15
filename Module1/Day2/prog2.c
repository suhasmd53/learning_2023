#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *temp = (unsigned char *)malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

int main() {
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 3.14, y = 2.71828;
    printf("Before swap: x = %f, y = %f\n", x, y);

    swap(&x, &y, sizeof(double));
    printf("After swap: x = %f, y = %f\n", x, y);

    return 0;
}
