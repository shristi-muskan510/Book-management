#ifndef ADDBOX_H
#define ADDBOX_H

#include <QDialog>

namespace Ui {
class addBox;
}

class addBox : public QDialog
{
    Q_OBJECT

public:
    explicit addBox(QWidget *parent = nullptr);
    ~addBox();

signals:
    void getVal(const QString &n, const QString &p);

private slots:
    void addBook();

private:
    Ui::addBox *ui;
};

#endif // ADDBOX_H
