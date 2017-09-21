#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_searchButton_clicked();
    void on_sortButton_clicked();
    void on_deleteButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Student> students;

    void refreshTable(const QVector<Student> &list = {});
    bool validateInput(QString &errMsg);
};

#endif // MAINWINDOW_H
