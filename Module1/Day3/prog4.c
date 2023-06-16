#include <stdio.h>
#include<math.h>
void smallestlargest(int n) {
    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        int smallest = 9; 
        int largest = 0; 
        int count=0;
        int temp = num;

        
        while (temp > 0) {
            int digit = temp % 10;

            if (digit < smallest) {
                smallest = digit;
            }
            if (digit > largest) {
                largest = digit;
            }

            temp /= 10;
        }
        count=(num==0)?1:log10(num)+1; 
        if (count == 1) {
            printf("Number %d is not valid\n", i + 1);
        } else {
            printf("Smallest digit is %d\n", i + 1, smallest);
            printf("Largest digit is %d\n", i + 1, largest);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    smallestlargest(n);

    return 0;
}

