#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

struct Student {
    int rollNumber;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
};

void calculateResult(struct Student *student) {
    student->total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        student->total += student->marks[i];
    }

    student->percentage = student->total / SUBJECTS;
}

char getGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage >= 50)
        return 'E';
    else
        return 'F';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter marks for %d subjects:\n", SUBJECTS);

        for (int j = 0; j < SUBJECTS; j++) {
            do {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);

                if (students[i].marks[j] < 0 ||
                    students[i].marks[j] > 100) {
                    printf("Marks must be between 0 and 100.\n");
                }

            } while (students[i].marks[j] < 0 ||
                     students[i].marks[j] > 100);
        }

        calculateResult(&students[i]);
    }

    printf("\n================ STUDENT RESULTS ================\n");

    printf("%-8s %-20s %-10s %-12s %-8s\n",
           "Roll", "Name", "Total", "Percentage", "Grade");

    for (int i = 0; i < n; i++) {
        printf("%-8d %-20s %-10.2f %-12.2f %-8c\n",
               students[i].rollNumber,
               students[i].name,
               students[i].total,
               students[i].percentage,
               getGrade(students[i].percentage));
    }

    return 0;
}
