#include "error.h"
#include "ui_error.h"
#include"display.h"

Error::Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
}

Error::~Error()
{
    delete ui;
}
void Error::on_exit_clicked()
{
    exit(0);
}
