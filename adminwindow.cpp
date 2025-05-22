#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "loginwindow.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminWindow)
    , patientList(new PatientList())
{
    ui->setupUi(this);
    refreshTable();

    connect(ui->btnAdd, &QPushButton::clicked, this, &AdminWindow::onAddClicked);
    connect(ui->btnUpdate, &QPushButton::clicked, this, &AdminWindow::onUpdateClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &AdminWindow::onDeleteClicked);
    connect(ui->btnLogout, &QPushButton::clicked, this, &AdminWindow::onLogoutClicked);
}

AdminWindow::~AdminWindow()
{
    delete ui;
    delete patientList;
}

void AdminWindow::refreshTable()
{
    ui->tablePatients->setRowCount(0);
    PatientNode* current = patientList->getHead();
    int row = 0;

    while(current) {
        ui->tablePatients->insertRow(row);
        ui->tablePatients->setItem(row, 0, new QTableWidgetItem(current->name));
        ui->tablePatients->setItem(row, 1, new QTableWidgetItem(QString::number(current->age)));
        current = current->next;
        row++;
    }
}

void AdminWindow::onAddClicked()
{
    QString name = ui->txtName->text();
    int age = ui->spinAge->value();

    if(!name.isEmpty()) {
        patientList->addPatient(name, age);
        refreshTable();
        ui->txtName->clear();
        ui->spinAge->setValue(0);
    }
}

void AdminWindow::onUpdateClicked()
{
    QList<QTableWidgetItem*> selected = ui->tablePatients->selectedItems();
    if(selected.isEmpty()) return;

    int row = selected.first()->row();
    QString oldName = ui->tablePatients->item(row, 0)->text();
    QString newName = ui->txtName->text();
    int newAge = ui->spinAge->value();

    if(!newName.isEmpty()) {
        patientList->updatePatient(oldName, newName, newAge);
        refreshTable();
    }
}

void AdminWindow::onDeleteClicked()
{
    QList<QTableWidgetItem*> selected = ui->tablePatients->selectedItems();
    if(selected.isEmpty()) return;

    int row = selected.first()->row();
    QString name = ui->tablePatients->item(row, 0)->text();
    patientList->deletePatient(name);
    refreshTable();
}

void AdminWindow::onLogoutClicked()
{
    this->close();
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}
