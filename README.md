# 🎓 Student Management System — Qt GUI (C++11)

A GUI-based application to manage college students' academic records with comprehensive subject-wise grading. This tool provides intuitive controls for **adding**, **searching**, **sorting**, and **deleting** student data — all in one place using Qt5 framework.

---

## 📷 Preview

| Operation        | Screenshot Snippet |
|------------------|--------------------|
| Add Student      | ![Add Student](screenshots/Student_Add.png) |
| Search Student   | ![Search Student](screenshots/Student_search.png) |
| Sort Students    | ![Sort](screenshots/Student_sort.png) |
| Delete Student   | ![Delete](screenshots/Student_Delete.png) |
| Student Report   | ![Table View](screenshots/Student_Table.png) |

> 📸 All screenshots are available in the `/screenshots` folder.

---

## ✨ Features

- 📝 **Add Student** — Insert full details including grades across key Computer Engineering subjects.
- 🔍 **Search** — Quickly find a student by Roll Number.
- 🔃 **Sort** — Arrange students by Total Marks.
- ❌ **Delete** — Remove any student entry using Roll Number.
- 📊 **Auto-Generated Report** — Total marks and final grade are auto-calculated.
- 🚪 **Exit Button** — Close the application gracefully.

---

## 📚 Subjects Included

| Subject                          | Short Name          |
|----------------------------------|---------------------|
| ANSI C                           | `ANSI C`            |
| Data Structures                  | `DS`                |
| DBMS                             | `DBMS`              |
| Operating Systems                | `OS`                |
| Object-Oriented Programming C++  | `OOP C++`           |
| Computer Networks                | `CN`                |
| Computer Organization            | `CO`                |
| Algorithms (ADA)                 | `Algorithms`        |
| Software Engineering             | `SE`                |
| Network Security                 | `Net Security`      |

Final report includes **Total Marks** and an overall **Grade (A/B/C)** based on percentage.

---

## 🛠️ Tech Stack

| Technology    | Description                          |
|---------------|--------------------------------------|
| **C++11**      | Core programming language            |
| **Qt 5**       | GUI framework                        |
| **Qt Creator** | IDE used to build & design UI        |
| **.ui XML**    | Interface built with Qt Designer     |
| **QTableWidget** | For dynamic student table display  |

---

## Files Added

- `mainwindow.ui`
- `mainwindow.cpp/.h`
- `student.cpp/.h`
- `studentdata.cpp/.h`
- `main.cpp`
- `screenshots/` (UI operations preview)

---

### 📦 Prerequisites

- Qt5 and `qtcreator` installed
- C++11 or higher support
- On Linux (WSL): X11 server (e.g. VcXsrv or X410)

### 🛠️ Steps

1. **Clone or Download** the repository:
   ```bash
   git clone https://github.com/nerdyvyoma136/student-management-app.git

## 🚀 How to Run

Build and run using Qt Creator or via:
```bash
qmake && make
./student_management_app


**Note**: Ignore two files **student_management.cpp** and **students.txt** as that was initial simple console based version of app which can normally be executed using any compiler followed by ./<object file generated>