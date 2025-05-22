#include "userwindow.h"
#include "ui_userwindow.h"
#include "loginwindow.h"

UserWindow::UserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWindow)
    , patientList(new PatientList())
{
    ui->setupUi(this);
    connect(ui->btnSearch, &QPushButton::clicked, this, &UserWindow::onSearchClicked);
    connect(ui->btnLogout, &QPushButton::clicked, this, &UserWindow::onLogoutClicked);
}

UserWindow::~UserWindow()
{
    delete ui;
    delete patientList;
}

void UserWindow::onSearchClicked()
{
    QString searchName = ui->txtSearch->text();
    ui->tableResults->setRowCount(0);

    PatientNode* current = patientList->getHead();
    int row = 0;

    while(current) {
        if(current->name.contains(searchName, Qt::CaseInsensitive)) {
            ui->tableResults->insertRow(row);
            ui->tableResults->setItem(row, 0, new QTableWidgetItem(current->name));
            ui->tableResults->setItem(row, 1, new QTableWidgetItem(QString::number(current->age)));
            row++;
        }
        current = current->next;
    }
}

void UserWindow::onLogoutClicked()
{
    this->close();
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}

// void UserWindow::on_tableResults_clicked(const QModelIndex &index)
// {

// }

