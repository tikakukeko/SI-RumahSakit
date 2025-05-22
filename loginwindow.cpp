#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "aboutwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->btnAbout, &QPushButton::clicked, this, &LoginWindow::on_btnAbout_clicked);

    aboutWindow = new AboutWindow(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete aboutWindow;
}

void LoginWindow::on_btnAbout_clicked()
{
    aboutWindow->show(); // Tampilkan halaman About
    aboutWindow->raise(); // Bawa ke depan
    aboutWindow->activateWindow(); // Aktifkan window
}

void LoginWindow::onLoginClicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();
    QString userType = ui->cmbUserType->currentText();

    // Simple authentication (for demonstration)
    if(((userType == "Admin" && username == "admin" && password == "admin") ||
         (userType == "User" && username == "user" && password == "user"))) {

        this->hide();

        if(userType == "Admin") {
            adminWindow = new AdminWindow();
            adminWindow->show();
        } else {
            userWindow = new UserWindow();
            userWindow->show();
        }
    }
}
