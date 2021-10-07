#include "cityinfo.h"
#include "ui_cityinfo.h"
#include "city.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
Cityinfo::Cityinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cityinfo)
{
    ui->setupUi(this);
}
Cityinfo::~Cityinfo()
{
    delete ui;
}
void Cityinfo::on_done_clicked()
{
    QString c = ui->city->text();
    QString e = ui->edge->text();
    int C = c.toInt();
    int E = e.toInt();
    int a = (C*(C-1))/2;
    if(c == NULL && e == NULL)
    {

        QMessageBox::warning(this, "WARNING", "Text Boxes are Empty.");
    }
    else if(e == NULL)
    {
        QMessageBox::warning(this, "WARNING", "Enter Number Of Edge.");
    }
    else if(c == NULL)
    {
        QMessageBox::warning(this, "WARNING", "Enter Number Of City.");
    }
    else if(E > a)
    {
        QMessageBox::warning(this, "Number Of Edge Outrun", QString("Can not have %1 edge for %2 cities.").arg(E).arg(C));
    }
    else
    {
        QString a = "e.txt";
        QString b = "v.txt";
        QFile mFile(a);
        if(!mFile.open(QFile::WriteOnly | QFile::Text))
        {
            return;
        }
        QTextStream out (&mFile);
        out << e;
        mFile.flush();
        mFile.close();
        QFile mFile1(b);
        if(!mFile1.open(QFile::WriteOnly | QFile::Text))
        {
            return;
        }
        QTextStream out1 (&mFile1);
        out1 << c;
        mFile1.flush();
        mFile1.close();
        hide();
        city = new City(this);
        city->show();
    }
}
void Cityinfo::on_back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}
