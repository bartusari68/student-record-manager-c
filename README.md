# Student Record Manager in C

A menu-driven student record management system written in C with file operations.

## 📌 Purpose
This project is built to practice structured programming in C, including functions, structs, arrays, and file handling.

## ✨ Features
- Add student
- List all students
- Search student by ID
- Save records to file
- Load records from file

## 🧱 Project Structure
- `main.c` → Program entry and menu loop
- `student.h` → Struct and function declarations
- `student.c` → Student record operations
- `data.txt` → Saved student records (generated at runtime)

## 🚀 Build & Run
```bash
gcc main.c student.c -o student_manager
./student_manager
