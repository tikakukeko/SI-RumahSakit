#include "patientlist.h"

PatientList::PatientList() : head(nullptr) {
    loadFromFile();
}

PatientList::~PatientList() {
    while(head) {
        PatientNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void PatientList::addPatient(QString name, int age) {
    PatientNode* newNode = new PatientNode(name, age);
    if(!head) {
        head = newNode;
    } else {
        PatientNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
    saveToFile();
}

void PatientList::updatePatient(QString oldName, QString newName, int newAge) {
    PatientNode* current = head;
    while(current) {
        if(current->name == oldName) {
            current->name = newName;
            current->age = newAge;
            saveToFile();
            return;
        }
        current = current->next;
    }
}

void PatientList::deletePatient(QString name) {
    if(!head) return;

    if(head->name == name) {
        PatientNode* temp = head;
        head = head->next;
        delete temp;
        saveToFile();
        return;
    }

    PatientNode* current = head;
    while(current->next) {
        if(current->next->name == name) {
            PatientNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            saveToFile();
            return;
        }
        current = current->next;
    }
}

PatientNode* PatientList::searchPatient(QString name) {
    PatientNode* current = head;
    while(current) {
        if(current->name == name) return current;
        current = current->next;
    }
    return nullptr;
}

void PatientList::loadFromFile() {
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if(parts.size() == 2) {
            addPatient(parts[0], parts[1].toInt());
        }
    }
    file.close();
}

void PatientList::saveToFile() {
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)) return;

    QTextStream out(&file);
    PatientNode* current = head;
    while(current) {
        out << current->name << "," << current->age << "\n";
        current = current->next;
    }
    file.close();
}
