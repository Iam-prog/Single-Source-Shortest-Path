#include "output.h"
#include "ui_output.h"
#include "display.h"
#include "sources.h"
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
QFont fo1( "Calibri", 12, QFont::Bold);
Output::Output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Output)
{
    ui->setupUi(this);
}
Output::~Output()
{
    delete ui;
}
void Output::on_SSST_clicked()
{
    QString aa = ui->a->text();
    QString bb = ui->edge->text();
    QString a = "ss.txt";
    QString b = "dd.txt";
    QFile mFile(a);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        return;
    }
    QTextStream out (&mFile);
    out << aa;
    mFile.flush();
    mFile.close();
    QFile mFile1(b);
    if(!mFile1.open(QFile::WriteOnly | QFile::Text))
    {
        return;
    }
    QTextStream out1 (&mFile1);
    out1 << bb;
    mFile1.flush();
    mFile1.close();
    hide();
    display = new Display(this);
    display->show();
}
void Output::on_Exit_clicked()
{
    exit(0);
}
void Output::on_Back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}
