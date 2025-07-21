#include <stdio.h>
#include <string.h>
struct Date {
    int day, month, year;
};
struct Student {
    int rollNo;
    char name[50];
    struct Date birthDate, admissionDate;    
};
void displayStudent(struct Student s) // struct variable declared as parameter
{
    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", s.rollNo);
    printf("Name: %s\n", s.name);
    printf("Birth Date: %d/%d/%d\n", s.birthDate.day, s.birthDate.month, s.birthDate.year);
    printf("Admission Date: %d/%d/%d\n", s.admissionDate.day, s.admissionDate.month, s.admissionDate.year);
}
int main() {
    struct Student student = {55, "Soumyadeep", {31, 10, 2006}, {4, 8, 2024}};
    // printf("Enter Roll No: ");
    // scanf("%d", &student.rollNo);
    // printf("Enter Name: ");
    // getchar();  
    // fgets(student.name, 50, stdin);
    // student.name[strcspn(student.name, "\n")] = 0;
    // printf("Enter Birth Date (dd mm yyyy): ");
    // scanf("%d %d %d", &student.birthDate.day, &student.birthDate.month, &student.birthDate.year);
    // printf("Enter Admission Date (dd mm yyyy): ");
    // scanf("%d %d %d", &student.admissionDate.day, &student.admissionDate.month, &student.admissionDate.year);
    displayStudent(student);
    return 0;
}