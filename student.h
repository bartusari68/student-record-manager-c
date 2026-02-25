#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

void addStudent(Student students[], int *count);
void listStudents(Student students[], int count);
void searchStudentById(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

#endif
