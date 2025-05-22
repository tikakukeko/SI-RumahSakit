#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "adminwindow.h"
#include "userwindow.h"
#include "aboutwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void onLoginClicked();
    void on_btnAbout_clicked();

private:
    Ui::LoginWindow *ui;
    AdminWindow *adminWindow;
    UserWindow *userWindow;
    AboutWindow *aboutWindow;
};

#endif // LOGINWINDOW_H
