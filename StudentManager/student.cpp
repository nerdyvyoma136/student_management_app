#include "student.h"

Student::Student(const QString &name, const QString &roll,
                 int ansiC, int dataStructures, int dbms, int os,
                 int oopCpp, int compNetworks, int compOrg, int algorithms,
                 int softwareEng, int netSecurity)
    : name(name), roll(roll),
      ansiC(ansiC), dataStructures(dataStructures), dbms(dbms), os(os),
      oopCpp(oopCpp), compNetworks(compNetworks), compOrg(compOrg), algorithms(algorithms),
      softwareEng(softwareEng), netSecurity(netSecurity) {}

int Student::totalMarks() const {
    return ansiC + dataStructures + dbms + os + oopCpp + compNetworks + compOrg + algorithms + softwareEng + netSecurity;
}

double Student::averageMarks() const {
    return totalMarks() / 10.0;
}

QString Student::finalGrade() const {
    double avg = averageMarks();
    if (avg >= 90)
        return "A+";
    else if (avg >= 80)
        return "A";
    else if (avg >= 70)
        return "B";
    else if (avg >= 60)
        return "C";
    else if (avg >= 50)
        return "D";
    else
        return "F";
}
