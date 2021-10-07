#include "display.h"
#include "ui_display.h"
#include"error.h"
#include <QTextStream>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include<QDebug>
QString s2 = "s.txt";
QString ss = "ss.txt";
QString d2=  "dest.txt";
QString dist2=  "d.txt";
QString dd=  "dd.txt";
QString e2 = "e.txt";
QString c2=  "c.txt";
QString v2=  "v.txt";
int eg=0;
int *Eg=&eg;
int vg=0;
int *Vg=&vg;
QString c[50];
QString *City=c;
QString cs[50];
QString *Citys=cs;
QFont fr( "Calibri", 20, QFont::Bold);
class Edge
{
public:
    int src;
    int dest;
    int weight;
};
class Graph
{
public:
    int V;
    int E;
    Edge* edge;
};
Edge rda[50];
Edge *rdas = rda;
int cx(QString city)
{
    int found=-1;
    for(int i=0; i<*Vg; i++)
    {
        if(City[i]==city)
        {
            found=i;
            break;
        }
    }
    return found;
}
int cx1(QString city)
{
    int found=-1;
    for(int i=0; i<*Vg; i++)
    {
        if(City[i].compare(city)==0)
        {
            found=i;
            break;
        }
    }
    return found;
}
void createGraph(Graph *graph)
{
    QFile mFileS(s2);
    if(!mFileS.open(QFile::ReadOnly | QFile::Text))
    {
        return ;
    }
    QTextStream ins (&mFileS);
    QFile mFiled(d2);
    if(!mFiled.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QFile mFilew(dist2);
    QTextStream ind (&mFiled);
    if(!mFilew.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream inw (&mFilew);
    int n1,n2;
    graph->V = *Vg;
    graph->E = *Eg;
    graph->edge = new Edge[*Eg];
    for(int i=0; i<*Eg; i++)
    {
        QString rTexts = ins.readLine();
        n1=cx(rTexts);
        graph->edge[i].src = n1;
        QString rTextd = ind.readLine();
        n2=cx(rTextd);
        graph->edge[i].dest = n2;
        QString rTextw = inw.readLine();
        graph->edge[i].weight =rTextw.toInt();
    }
    mFileS.flush();
    mFileS.close();
    mFiled.flush();
    mFiled.close();
    mFilew.flush();
    mFilew.close();
}
int ap;
void p(int dist[])
{
    QFile mFiledd(dd);
    if(!mFiledd.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream indd (&mFiledd);
    QString rTextdd = indd.readLine();
    //qDebug()<<rTextdd;
    int n1=cx1(rTextdd);
    //qDebug()<<n1;
    mFiledd.flush();
    mFiledd.close();
    for (int i = 0; i < *Vg; i++)
    {
        if(n1==i)
        {
            ap= dist[i];
        }
    }
}
int fb=0;
void BellmanFord(Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            fb=1;
        }
    }
    p(dist);
    return;
}
Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    QFile mFilee(e2);
    if(!mFilee.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream ine (&mFilee);
    QString rTexte = ine.readAll();
    *Eg=rTexte.toInt();
    mFilee.flush();
    mFilee.close();
    QFile mFilev(v2);
    if(!mFilev.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream inv (&mFilev);
    QString rTextv = inv.readAll();
    *Vg=rTextv.toInt();
    mFilev.flush();
    mFilev.close();
    QFile mFilec(c2);
    if(!mFilec.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream inc (&mFilec);
    for(int i=0; i<*Vg; i++)
    {
        QString rTextc = inc.readLine();
        City[i]=rTextc;
    }
    mFilec.flush();
    mFilec.close();
    Graph *graph=new Graph;
    createGraph(graph);
    QFile mFiless(ss);
    if(!mFiless.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream incc (&mFiless);
    QString rTextss = incc.readLine();
    //qDebug()<<rTextss;
    int n1=cx1(rTextss);
    //qDebug()<<n1;
    mFiless.flush();
    mFiless.close();
    BellmanFord(graph,n1);
    if(fb==1)
    {
        QLabel* l1 = new QLabel;
        l1->setText("Can't Find!");
        l1->setParent(this);
        l1->setFont(fr);
        l1->setGeometry(1000,200,180,60);
        l1->show();
        hide();
        error = new Error(this);
        error->show();
    }
    else
    {
        QLabel* l1 = new QLabel;
        l1->setText(QVariant(ap).toString());
        l1->setParent(this);
        l1->setFont(fr);
        l1->setGeometry(1000,200,180,60);
        l1->show();
    }
}
Display::~Display()
{
    delete ui;
}
void Display::on_pushButton_exit_clicked()
{
    exit(0);
}
