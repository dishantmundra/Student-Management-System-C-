
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    for (const Student& student : students) {
        if (student.rollNo == s.rollNo) {
            cout << "Roll number already exists!\n";
            return;
        }
    }

    cout << "Enter Student Name: ";
    getline(cin >> ws, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n----- Student Records -----\n";

    for (const Student& s : students) {
        cout << "Roll Number: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
        cout << "---------------------------\n";
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for (const Student& s : students) {
        if (s.rollNo == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << s.rollNo << endl;
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == roll) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
