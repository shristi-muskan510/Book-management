#include "addbox.h"
#include "ui_addbox.h"

addBox::addBox(QWidget *parent): QDialog(parent), ui(new Ui::addBox)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &addBox::addBook);
}

addBox::~addBox()
{
    delete ui;
}

void addBox::addBook()
{
    QString name = ui->lineEdit->text();
    QString price = ui->lineEdit_2->text();
    emit getVal(name, price);
}

