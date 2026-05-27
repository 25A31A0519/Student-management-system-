#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

class StudentManagementSystem {
    string filename = "students.txt";

public:
    void addStudent() {
        Student s;
        cout << "Enter ID: "; cin >> s.id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, s.name);
        cout << "Enter Age: "; cin >> s.age;
        cin.ignore();
        cout << "Enter Course: "; getline(cin, s.course);

        ofstream file(filename, ios::app);
        file << s.id << "," << s.name << "," << s.age << "," << s.course << endl;
        file.close();

        cout << "Student added successfully.\n";
    }

    void displayStudents() {
        ifstream file(filename);
        string line;
        cout << "\nStudent Records:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Display Students\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.displayStudents(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
