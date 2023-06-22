#include <stdio.h>
#include<stdlib.h>
int largestnumber(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);  
    int largest_num = 0;

    for (int i = 0; i < 4; i++) {
        char new_num_str[5];
        int index = 0;

        for (int j = 0; j < 4; j++) {
            if (j != i) {
                new_num_str[index] = num_str[j];
                index++;
            }
        }
        new_num_str[index] = '\0';

        int new_num = atoi(new_num_str); 

        if (new_num > largest_num) {
            largest_num = new_num;
        }
    }

    return largest_num;
}

int main() {
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    printf("Largest number by deleting a single digit from %d: %d\n", num, largestnumber(num));


    return 0;
}
