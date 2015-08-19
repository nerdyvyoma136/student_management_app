#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

void saveToFile() {
    ofstream file("students.txt");
    for (auto &s : students) {
        file << s.id << "," << s.name << "," << s.age << "," << s.course << endl;
    }
    file.close();
}

void loadFromFile() {
    students.clear();
    ifstream file("students.txt");
    Student s;
    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        pos = line.find(",");
        s.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(",");
        s.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        s.age = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        s.course = line;
        students.push_back(s);
    }
    file.close();
}

void addStudent() {
    Student s;
    cout << "Enter ID: "; cin >> s.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, s.name);
    cout << "Enter Age: "; cin >> s.age;
    cin.ignore();
    cout << "Enter Course: "; getline(cin, s.course);

    students.push_back(s);
    saveToFile();
    cout << "Student added successfully!\n";
}

void viewStudents() {
    for (auto &s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name
             << ", Age: " << s.age << ", Course: " << s.course << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "ID: " << s.id << ", Name: " << s.name
                 << ", Age: " << s.age << ", Course: " << s.course << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveToFile();
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n2. View Students\n3. Search Student\n4. Delete Student\n0. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
