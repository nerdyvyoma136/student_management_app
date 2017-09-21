#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentdata.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Load sample students on start
    students = getSampleStudents();
    refreshTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::validateInput(QString &errMsg) {
    if (ui->nameLineEdit->text().trimmed().isEmpty()) {
        errMsg = "Name cannot be empty.";
        return false;
    }
    if (ui->rollLineEdit->text().trimmed().isEmpty()) {
        errMsg = "Roll Number cannot be empty.";
        return false;
    }
    auto checkMark = [&](QLineEdit *edit, const QString &subject) -> bool {
        bool ok;
        int val = edit->text().toInt(&ok);
        if (!ok || val < 0 || val > 100) {
            errMsg = subject + " marks must be an integer between 0 and 100.";
            return false;
        }
        return true;
    };

    if (!checkMark(ui->ansiCLineEdit, "ANSI C")) return false;
    if (!checkMark(ui->dsLineEdit, "Data Structures")) return false;
    if (!checkMark(ui->dbmsLineEdit, "DBMS")) return false;
    if (!checkMark(ui->osLineEdit, "Operating Systems")) return false;
    if (!checkMark(ui->oopCppLineEdit, "OOP with C++")) return false;
    if (!checkMark(ui->cnLineEdit, "Computer Networks")) return false;
    if (!checkMark(ui->coLineEdit, "Computer Organization")) return false;
    if (!checkMark(ui->adaLineEdit, "Algorithms")) return false;
    if (!checkMark(ui->seLineEdit, "Software Engineering")) return false;
    if (!checkMark(ui->netSecLineEdit, "Network Security")) return false;

    return true;
}

void MainWindow::refreshTable(const QVector<Student> &list) {
    const QVector<Student> &data = list.isEmpty() ? students : list;

    ui->studentTableWidget->setRowCount(0);

    for (int i = 0; i < data.size(); ++i) {
        ui->studentTableWidget->insertRow(i);
        ui->studentTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].name));
        ui->studentTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].roll));
        ui->studentTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].ansiC)));
        ui->studentTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].dataStructures)));
        ui->studentTableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(data[i].dbms)));
        ui->studentTableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(data[i].os)));
        ui->studentTableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(data[i].oopCpp)));
        ui->studentTableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(data[i].compNetworks)));
        ui->studentTableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(data[i].compOrg)));
        ui->studentTableWidget->setItem(i, 9, new QTableWidgetItem(QString::number(data[i].algorithms)));
        ui->studentTableWidget->setItem(i, 10, new QTableWidgetItem(QString::number(data[i].softwareEng)));
        ui->studentTableWidget->setItem(i, 11, new QTableWidgetItem(QString::number(data[i].netSecurity)));

        ui->studentTableWidget->setItem(i, 12, new QTableWidgetItem(QString::number(data[i].totalMarks())));
        ui->studentTableWidget->setItem(i, 13, new QTableWidgetItem(data[i].finalGrade()));
    }
}

void MainWindow::on_addButton_clicked() {
    QString errorMsg;
    if (!validateInput(errorMsg)) {
        QMessageBox::warning(this, "Input Error", errorMsg);
        return;
    }

    Student s(
        ui->nameLineEdit->text().trimmed(),
        ui->rollLineEdit->text().trimmed(),
        ui->ansiCLineEdit->text().toInt(),
        ui->dsLineEdit->text().toInt(),
        ui->dbmsLineEdit->text().toInt(),
        ui->osLineEdit->text().toInt(),
        ui->oopCppLineEdit->text().toInt(),
        ui->cnLineEdit->text().toInt(),
        ui->coLineEdit->text().toInt(),
        ui->adaLineEdit->text().toInt(),
        ui->seLineEdit->text().toInt(),
        ui->netSecLineEdit->text().toInt()
    );

    students.append(s);
    refreshTable();

    QMessageBox::information(this, "Success", "Student added successfully.");
}

void MainWindow::on_searchButton_clicked() {
    QString roll = ui->searchLineEdit->text().trimmed();
    if (roll.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter a roll number to search.");
        return;
    }

    QVector<Student> results;
    for (const Student &s : students) {
        if (s.roll == roll) {
            results.append(s);
        }
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "No Results", "No student found with roll number: " + roll);
        return;
    }

    refreshTable(results);
}

void MainWindow::on_sortButton_clicked() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.totalMarks() > b.totalMarks();
    });
    refreshTable();
}

void MainWindow::on_deleteButton_clicked() {
    QString roll = ui->searchLineEdit->text().trimmed();
    if (roll.isEmpty()) {
        QMessageBox::warning(this, "Delete Error", "Please enter a roll number to delete.");
        return;
    }

    bool removed = false;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].roll == roll) {
            students.removeAt(i);
            removed = true;
            break;
        }
    }

    if (removed) {
        refreshTable();
        QMessageBox::information(this, "Deleted", "Student with roll number " + roll + " deleted.");
    } else {
        QMessageBox::information(this, "Not Found", "No student found with roll number: " + roll);
    }
}

void MainWindow::on_exitButton_clicked() {
    close();
}
