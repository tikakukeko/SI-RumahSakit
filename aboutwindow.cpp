#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    // Set window properties
    setWindowTitle("About Hospital System");
    resize(500, 400);

    // Set content (assuming these UI elements exist)
    ui->labelTitle->setText("Hospital Information System");
    ui->labelVersion->setText("Version 1.0.0");
    ui->labelDescription->setText("Dibuat Oleh Kelompok 4 :");
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
