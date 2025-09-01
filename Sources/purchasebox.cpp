#include "purchasebox.h"
#include "ui_purchasebox.h"
#include <QTableWidget>
#include <QTableWidgetItem>

purchaseBox::purchaseBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::purchaseBox)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &purchaseBox::purchaseBook);
}

purchaseBox::~purchaseBox()
{
    delete ui;
}

void purchaseBox::purchaseBook()
{
    QString bookName = ui->lineEdit->text();
    QString quant = ui->lineEdit_2->text();
    emit getPur(bookName, quant);
}

void purchaseBox::setBookList(const QStringList &names, const QStringList &prices)
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);

    QStringList headers;
    headers << "Book Name" << "Price";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < names.size(); ++i) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QTableWidgetItem *nameItem = new QTableWidgetItem(names[i]);
        QTableWidgetItem *priceItem = new QTableWidgetItem(prices[i]);

        // Make cells read-only
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);

        ui->tableWidget->setItem(row, 0, nameItem);
        ui->tableWidget->setItem(row, 1, priceItem);
    }
}

