#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addbox.h"
#include "purchasebox.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addFun();
    void onADD(const QString &n, const QString &p);

    void purchaseFun();
    void onPUR(const QString &n, const QString &q);

private:
    Ui::MainWindow *ui;
    addBox *addbox;
    purchaseBox *purbox;
};
#endif // MAINWINDOW_H
