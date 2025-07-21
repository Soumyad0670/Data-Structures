#include <stdio.h>
#include <string.h> 
#define PASS_MARKS 40
struct info {
    char name[10];
    char gender;
    int roll_no;
    int marks;
};
int main() {
    int n;
    printf("Enter the number of students in KIIT University:\n");
    scanf("%d", &n);
    struct info s[n];
    for(int i = 0; i < n; i++) {
        printf("Enter the name of student:\n");
        scanf(" %s", s[i].name);
        printf("Enter gender(M or F):\n");
        scanf(" %c", &s[i].gender);
        printf("Enter the roll no. of student:\n");
        scanf("%d", &s[i].roll_no);
        printf("Enter the marks of student:\n");
        scanf("%d", &s[i].marks);
    }
    printf("\nStudents with marks >= 40:\n");
    for(int i = 0; i < n; i++) {
        if(s[i].marks >= PASS_MARKS) {
            printf("Name: %s\n", s[i].name);
            printf("Gender: %c\n", s[i].gender);
            printf("Roll No: %d\n", s[i].roll_no);
            printf("Marks: %d\n\n", s[i].marks);
        }
    }
    return 0;
}