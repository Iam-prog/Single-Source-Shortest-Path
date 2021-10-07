#ifndef DISPLAY_H
#define DISPLAY_H
#include <QDialog>
#include <QPainter>
#include<error.h>
namespace Ui {
class Display;
}
class Display : public QDialog
{
    Q_OBJECT
public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();
private slots:
    void on_pushButton_exit_clicked();
private:
    Ui::Display *ui;
    Error *error;
};
#endif // DISPLAY_H
