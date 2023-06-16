#include <stdio.h>

void pattern(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        for (int k = 1; k <= 2 * (n - i); k++) {
            printf(" ");
        }
           for (int j = i; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    pattern(n);

    return 0;
}

