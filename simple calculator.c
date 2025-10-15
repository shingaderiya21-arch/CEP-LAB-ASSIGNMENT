#include <stdio.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int marks[3];
    int total;
    float average;
};

// Function to calculate total and average marks
void calculateGrades(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 3; i++) {
        s->total += s->marks[i];
    }
    s->average = s->total / 3.0;
}

// Function to display student information
void displayStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Marks: %d, %d, %d\n", s.marks[0], s.marks[1], s.marks[2]);
    printf("Total: %d\n", s.total);
    printf("Average: %.2f\n", s.average);
    printf("------------------------\n");
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);  // Read full line including spaces

        printf("Enter marks of 3 subjects for %s:\n", students[i].name);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].marks[j]);
        }

        // Calculate total and average
        calculateGrades(&students[i]);
    }

    // Display student data
    printf("\nStudent Grades:\n");
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    return 0;

}
