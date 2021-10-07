#ifndef SOURCES_H
#define SOURCES_H
#include <QDialog>
#include "output.h"
namespace Ui {
class Sources;
}
class Sources : public QDialog
{
    Q_OBJECT
public:
    explicit Sources(QWidget *parent = nullptr);
    ~Sources();
private slots:
    void on_done_clicked();
private:
    Ui::Sources *ui;
    Output * output;
};
#endif // SOURCES_H
