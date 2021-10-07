#include "city.h"
#include "ui_city.h"
#include "sources.h"
#include "cityinfo.h"
#include <QLabel>
#include<QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QDebug>
QString city=  "c.txt";
QString Vertex = "v.txt";
QFont f( "Calibri", 15, QFont::Bold);
static int i = -1;
static int c = 0;
static int aa=0;
static int* a=&aa;
static QFile mFile1(city);
City::City(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::City)
{
    ui->setupUi(this);
    QFile mFile(Vertex);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream in (&mFile);
    QString rText = in.readAll();
    mFile.flush();
    mFile.close();
    *a = rText.toInt();
    if(mFile1.exists())
    {
        mFile1.remove();
    }
}
City::~City()
{
    delete ui;
}

void City::on_done_clicked()
{
    c++;
    i++;
    QLabel* l1 = new QLabel;
    l1->setText("Cities");
    l1->setParent(this);
    l1->setFont(f);
    l1->setGeometry(90,220,165,35);
    l1->show();
    QString name = ui->cityName->text();
    if(!mFile1.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }
    QTextStream out1 (&mFile1);
    out1<< ui->cityName->text() << "\n";
    ui->cityName->clear();
    QLabel* l2 = new QLabel;
    l2->setText(QString("%1").arg(name));
    l2->setFont(f);
    l2->setParent(this);
    l2->setGeometry(120,260+i*30,80,25);
    l2->show();
    mFile1.flush();
    mFile1.close();
    if(c==*a)
    {
        hide();
        sources = new Sources(this);
        sources->show();
    }
}
void City::on_back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}
