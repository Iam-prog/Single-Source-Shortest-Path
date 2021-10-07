#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cityinfo.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_CreateMap_clicked()
{
    hide();
    cityinfo = new Cityinfo(this);
    cityinfo->show();
}
void MainWindow::on_Exit_clicked()
{
    exit(0);
}
