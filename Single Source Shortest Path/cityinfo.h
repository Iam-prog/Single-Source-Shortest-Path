#ifndef CITYINFO_H
#define CITYINFO_H
#include <QDialog>
#include "city.h"
namespace Ui {
class Cityinfo;
}
class Cityinfo : public QDialog
{
    Q_OBJECT
public:
    explicit Cityinfo(QWidget *parent = nullptr);
    ~Cityinfo();
private slots:
    void on_done_clicked();
    void on_back_clicked();
private:
    Ui::Cityinfo *ui;
    City *city;
};
#endif // CITYINFO_H
