#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Age: ");
    scanf("%d", &students[*count].age);

    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);

    (*count)++;
    printf("Student added successfully.\n");
}

void listStudents(Student students[], int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | GPA: %.2f\n",
               students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
}

void searchStudentById(Student students[], int count) {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student found:\n");
            printf("ID: %d | Name: %s | Age: %d | GPA: %.2f\n",
                   students[i].id, students[i].name, students[i].age, students[i].gpa);
            return;
        }
    }

    printf("Student not found.\n");
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n",
                students[i].id, students[i].name, students[i].age, students[i].gpa);
    }

    fclose(file);
    printf("Records saved to file.\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        return;
    }

    *count = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n",
                  &students[*count].id,
                  students[*count].name,
                  &students[*count].age,
                  &students[*count].gpa) == 4) {
        (*count)++;
        if (*count >= MAX_STUDENTS) break;
    }

    fclose(file);
}
