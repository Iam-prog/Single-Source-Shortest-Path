#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "cityinfo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_CreateMap_clicked();
    void on_Exit_clicked();
private:
    Ui::MainWindow *ui;
    Cityinfo *cityinfo;
};
#endif // MAINWINDOW_H
