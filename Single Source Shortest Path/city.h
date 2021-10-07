#ifndef CITY_H
#define CITY_H
#include <QDialog>
#include "sources.h"
namespace Ui {
class City;
}
class City : public QDialog
{
    Q_OBJECT
public:
    explicit City(QWidget *parent = nullptr);
    ~City();
private slots:
    void on_done_clicked();
    void on_back_clicked();
private:
    Ui::City *ui;
    Sources *sources;
};
#endif // CITY_H
