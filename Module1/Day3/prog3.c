#include <stdio.h>

int deleteDigit(int num, int position) {
    int temp = num, multiplier = 1;

    for (int i = 0; i < position; i++) {
        multiplier *= 10;
        temp /= 10;
    }

   
    temp /= 10;
    temp = temp * multiplier + (num % multiplier);

    return temp;
}

int LargestNumber(int num) {
    int max = 0;
    int numLength = 0;
    int temp = num;

    
    while (temp != 0) {
        numLength++;
        temp /= 10;
    }

    for (int i = 0; i < numLength; i++) {
        temp = deleteDigit(num, i);

       
        if (temp > max)
            max = temp;
    }

    return max;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The largest number by deleting a single digit is: %d\n", LargestNumber(num));

    return 0;
}
