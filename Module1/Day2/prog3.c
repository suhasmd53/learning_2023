#include <stdio.h>

int main() {
    int arr[10];
    for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }

    printf("Sum of alternate elements: %d\n", sum);

    return 0;
}

