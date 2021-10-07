#ifndef OUTPUT_H
#define OUTPUT_H
#include <QDialog>
#include "display.h"
namespace Ui {
class Output;
}
class Output : public QDialog
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr);
    ~Output();
private slots:
    void on_SSST_clicked();
    void on_Back_clicked();
    void on_Exit_clicked();
private:
    Ui::Output *ui;
    Display *display;
};
#endif // OUTPUT_H
