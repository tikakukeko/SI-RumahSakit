#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include <QString>
#include <QFile>
#include <QTextStream>

struct PatientNode {
    QString name;
    int age;
    PatientNode* next;

    PatientNode(QString n, int a) : name(n), age(a), next(nullptr) {}
};

class PatientList {
private:
    PatientNode* head;
    const QString filename = "data.txt";

public:
    PatientList();
    ~PatientList();

    void addPatient(QString name, int age);
    void updatePatient(QString oldName, QString newName, int newAge);
    void deletePatient(QString name);
    PatientNode* searchPatient(QString name);
    void loadFromFile();
    void saveToFile();
    PatientNode* getHead() { return head; }
};

#endif // PATIENTLIST_H
