void updateStudentById(Student students[], int count) {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Student updated successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudentById(Student students[], int *count) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}
