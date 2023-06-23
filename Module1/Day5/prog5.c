#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(const struct Student* students, int numStudents, const char* targetName) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", targetName);
    }
}

int main() {
    int numStudents;
    char targetName[20];
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the details for Student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        getchar();  

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar();  
    }

    printf("\nEnter the name of the student to search: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0'; 

    searchByName(students, numStudents, targetName);

    return 0;
}
