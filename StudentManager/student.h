#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student {
public:
    QString name;
    QString roll;

    int ansiC;
    int dataStructures;
    int dbms;
    int os;
    int oopCpp;
    int compNetworks;
    int compOrg;
    int algorithms;
    int softwareEng;
    int netSecurity;

    Student() = default;

    Student(const QString &name, const QString &roll,
            int ansiC, int dataStructures, int dbms, int os,
            int oopCpp, int compNetworks, int compOrg, int algorithms,
            int softwareEng, int netSecurity);

    int totalMarks() const;
    double averageMarks() const;
    QString finalGrade() const;
};

#endif // STUDENT_H

