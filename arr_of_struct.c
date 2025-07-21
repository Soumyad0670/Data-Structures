#include <stdio.h>
#include <string.h>
struct Student {
    int rollNo;
    char name[50];
    float marks;
};
void displayStudent(struct Student students[], int size) { 
    printf("--------------------\n");
    for(int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
}
int main() {
    printf("Student Information System\n");
    printf("Enter the number of students:\n");
    int n;
    scanf("%d", &n);
    struct Student students[n]; 
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Enter Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter Name: ");
        getchar();
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nStudent Details:\n");
    displayStudent(students, n);
    return 0;
}
