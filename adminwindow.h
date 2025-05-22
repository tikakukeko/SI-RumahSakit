#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include "patientlist.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    void refreshTable();

private slots:
    void onAddClicked();
    void onUpdateClicked();
    void onDeleteClicked();
    void onLogoutClicked();

private:
    Ui::AdminWindow *ui;
    PatientList *patientList;
};

#endif // ADMINWINDOW_H
