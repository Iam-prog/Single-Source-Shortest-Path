#include "sources.h"
#include "ui_sources.h"
#include <QFile>
#include "output.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
QString ci[100];
QString *city1=ci;
int o=0,P=0;
int *O=&o;
static int* p=&P;
QString dest=  "dest.txt";
QString source = "s.txt";
QString distance=  "d.txt";
QFont fo( "Calibri", 12, QFont::Bold);
static int count = 0;
QFile a(source);
QFile b(dest);
QFile c1(distance);
QString City1=  "c.txt";
QString Vertex1=  "v.txt";
Sources::Sources(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sources)
{
    ui->setupUi(this);
    QLabel* l1 = new QLabel;
    l1->setText("Edges");
    l1->setParent(this);
    l1->setFont(fo);
    l1->setGeometry(70,360,180,30);
    l1->show();
    QString Filename = "e.txt";
    QFile f(Filename);
    if(!f.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream o (&f);
    QString r = o.readAll();
    f.flush();
    f.close();
     *p = r.toInt();
    QFile v(Vertex1);
    if(!v.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream g (&v);
    QString gv = g.readAll();
    *O=gv.toInt();
    v.flush();
    v.close();
    QFile c(City1);
    if(!c.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream inc (&c);
    for(int i=0;i<*O;i++){
          QString rc = inc.readLine();
          city1[i]=rc;
    }
    c.flush();
    c.close();
    QList<QString> cities;
    for(int i = 0; i < *O; i++){
        cities.append(city1[i]);
    }
    ui->source->addItem("Select->");
    ui->source->addItems(cities);
    ui->destination->addItem("Select->");
    ui->destination->addItems(cities);
    if(a.exists())
        a.remove();
    if(b.exists())
        b.remove();
    if(c1.exists())
        c1.remove();
}
Sources::~Sources()
{
    delete ui;
}
bool check(QString source,QString dest){
    bool found=false;
    if(!a.open(QFile::ReadOnly | QFile::Text))
        return 0;
    QTextStream s (&a);
    if(!b.open(QFile::ReadOnly | QFile::Text))
        return 0;
    QTextStream d (&b);
    for(int i=0;i<a.size();i++){
          QString rs = s.readLine();
          QString rd = d.readLine();
          if((source==rs && dest==rd)||(dest==rs && source==rd))
              found=true;         
    }
    a.flush();
    a.close();
    b.flush();
    b.close();
    return found;
}
int i= -1;
void Sources::on_done_clicked()
{
    QString destination = ui->destination->currentText();
    QString source = ui->source->currentText();  
    bool exist=check(source,destination);
    if(!c1.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }
    QTextStream r2 (&c1);
    if(exist==false){
    if(!a.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }
    QTextStream r (&a);
    if(!b.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }
    QTextStream r1 (&b);
         QString s =source;
         QString d = destination;
         count++;
         i++;      
         QString dis = ui->distance->text();
         QLabel* l1 = new QLabel;
         l1->setText(d);
         l1->setParent(this);
         l1->setFont(fo);
         l1->setGeometry(310,450+i*40,90,22);
         l1->show();
         QLabel* l2 = new QLabel;
         l2->setText(s);
         l2->setParent(this);
         l2->setFont(fo);
         l2->setGeometry(70,450+i*40,90,22);
         l2->show();
         QLabel* l3 = new QLabel;
         l3->setText(dis);
         l3->setParent(this);
         l3->setFont(fo);
         l3->setGeometry(210,430+i*40,90,22);
         l3->show();
         QLabel* l4 = new QLabel;
         l4->setText("------------------------------------------------------------------");
         l4->setParent(this);
         l4->setFont(fo);
         l4->setGeometry(100,450+i*40,200,22);
         l4->show();
        r<< source<<"\n";
        r1<< destination<<"\n";
        r2<< ui->distance->text()<<"\n";
        a.flush();
        a.close();
        b.flush();
        b.close();
    }
    else{
         QMessageBox::warning(this, "WARNING", "Edge already exist.");
    }
     ui->distance->clear();
     c1.flush();
     c1.close();
    if(count==*p)
    {
        hide();
        output = new Output(this);
        output->show();
    }
}
