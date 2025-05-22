#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include "patientlist.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void onSearchClicked();
    void onLogoutClicked();

    // void on_tableResults_clicked(const QModelIndex &index);

private:
    Ui::UserWindow *ui;
    PatientList *patientList;
};

#endif // USERWINDOW_H
