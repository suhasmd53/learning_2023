/*By taking students details as example*/

#include <stdio.h>
#include<string.h>
struct Student {
    int rollNumber;
    char name[50];
};

void swapFields(struct Student* student1, struct Student* student2) {
    struct Student temp;

    
    temp.rollNumber = student1->rollNumber;
    student1->rollNumber = student2->rollNumber;
    student2->rollNumber = temp.rollNumber;

    
    strcpy(temp.name, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, temp.name);
}

int main() {
    struct Student student1, student2;

    printf("Enter details for Student 1:\n");
    printf("Roll Number: ");
    scanf("%d", &student1.rollNumber);
    printf("Name: ");
    scanf("%s", student1.name);

    printf("\nEnter details for Student 2:\n");
    printf("Roll Number: ");
    scanf("%d", &student2.rollNumber);
    printf("Name: ");
    scanf("%s", student2.name);

    printf("\nBefore Swapping:\n");
    printf("Student 1: Roll Number = %d, Name = %s\n", student1.rollNumber, student1.name);
    printf("Student 2: Roll Number = %d, Name = %s\n", student2.rollNumber, student2.name);

    swapStudentFields(&student1, &student2);

    printf("\nAfter Swapping:\n");
    printf("Student 1: Roll Number = %d, Name = %s\n", student1.rollNumber, student1.name);
    printf("Student 2: Roll Number = %d, Name = %s\n", student2.rollNumber, student2.name);

    return 0;
}
