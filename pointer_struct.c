#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int roll_number;
    float marks;
};
int main() {
    struct Student student1 = {"John", 101, 85.5};
    struct Student *ptr_student;  // Pointer to struct
    ptr_student = &student1; // Assigning address of student1 to pointer
    printf("Using structure pointer:\n");
    printf("Name: %s\n", (*(&student1)).name); // Accessing members using pointer by member operator
    printf("Roll Number: %d\n", ptr_student->roll_number); // membership or arrow operator
    printf("Marks: %.2f\n", ptr_student->marks);
    ptr_student->marks = 92.5;
    printf("\nAfter modification:\n");
    printf("Updated marks: %.2f\n", student1.marks); // Accessing directly from the original structure by dot operator
    return 0;
}