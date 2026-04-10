#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;


void writeStudents(char *filename); /* Function to write students */
void readStudents(char *filename); /* Function to read students */

int main() {
	
    int choice;
    char filename[] = "students.txt";

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add students\n");
        printf("2. Show students\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeStudents(filename);
                break;

            case 2:
                readStudents(filename);
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

void writeStudents(char *filename) {
    
	FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    int n;
    Student s;

    printf("How many students? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d name: ", i + 1);
        scanf("%s", s.name);

        printf("Age: ");
        scanf("%d", &s.age);

        printf("Grade: ");
        scanf("%f", &s.grade);

        fprintf(f, "%s %d %.2f\n", s.name, s.age, s.grade);
    }

    fclose(f);
    printf("\nStudents saved successfully!\n");
}

/* Function to read students */
void readStudents(char *filename) {
    
	FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    Student s;

    printf("\n--- Student List ---\n");

    while (fscanf(f, "%s %d %f", s.name, &s.age, &s.grade) != EOF) {
        printf("Name: %s | Age: %d | Grade: %.2f\n", s.name, s.age, s.grade);
    }

    fclose(f);
}