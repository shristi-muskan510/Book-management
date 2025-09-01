#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addbox.h"
#include "purchasebox.h"
#include <QStringList>
#include <QMessageBox>

QStringList nameList;
QStringList priceList;
bool found = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), addbox(new addBox(this)), purbox(new purchaseBox(this))
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addFun);
    connect(addbox, &addBox::getVal, this, &MainWindow::onADD);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::purchaseFun);
    connect(purbox, &purchaseBox::getPur, this, &MainWindow::onPUR);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addbox;
    delete purbox;
}

void MainWindow::addFun()
{
    addbox->show();
}

void MainWindow::onADD(const QString &n, const QString &p)
{
    nameList.append(n);
    priceList.append(p);

    QMessageBox::information(this, "success" ,"New Book added");
}

void MainWindow::purchaseFun()
{
    purbox->setBookList(nameList, priceList);
    purbox->show();
}

void MainWindow::onPUR(const QString &n, const QString &q)
{
    for(int i=0; i<nameList.length(); i++){
        if(n == nameList[i]){
            found = true;

            int quant_int = q.toInt();
            QString price = priceList[i];
            int price_int = price.toInt();

            int bill = price_int*quant_int;
            QString bill_str = QString::number(bill);
            QMessageBox::information(this, "success", "Total bill is" + bill_str);
        }
    }

    if(!found){
        QMessageBox::information(this, "Error", "Book not found");
    }
}

