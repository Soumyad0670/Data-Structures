#include <stdio.h>
#include <string.h>
#define MAX_SCORES 5  
struct Student {
    int rollNo;
    char name[50];
    int scores[MAX_SCORES];  // Array within structure
    float average;
};
void calculateAverage(struct Student student) {
    int sum = 0;
    for(int i = 0; i < MAX_SCORES; i++) {
        sum += student.scores[i];
    }
    student.average = (float)sum / MAX_SCORES;
    printf("\nAverage Score: %.2f\n", student.average);
}
void displayStudent(struct Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.rollNo);
    printf("Test Scores: ");
    for(int i = 0; i < MAX_SCORES; i++) {
        printf("%d ", student.scores[i]);
    }
}
int main() {
    struct Student student = {24051355, "Soumyadeep Dutta", {0}, 4.0};
    for(int i = 0; i < MAX_SCORES; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &student.scores[i]);
    }
    displayStudent(student);
    calculateAverage(student);
    return 0;
}