#include <stdio.h>
#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    do {
        printf("\n=== Student Record Manager ===\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student by ID\n");
        printf("5. Delete Student by ID\n");
        printf("6. Save Records\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                listStudents(students, count);
                break;
            case 3:
                searchStudentById(students, count);
                break;
            case 4:
                updateStudentById(students, count);
                break;
            case 5:
                deleteStudentById(students, &count);
                break;
            case 6:
                saveToFile(students, count);
                break;
            case 7:
                saveToFile(students, count);
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
