#ifndef PURCHASEBOX_H
#define PURCHASEBOX_H

#include <QDialog>

namespace Ui {
class purchaseBox;
}

class purchaseBox : public QDialog
{
    Q_OBJECT

public:
    explicit purchaseBox(QWidget *parent = nullptr);
    ~purchaseBox();

    void setBookList(const QStringList &n, const QStringList &p);

signals:
    void getPur(const QString &n, const QString &q);

private slots:
    void purchaseBook();

private:
    Ui::purchaseBox *ui;
};

#endif // PURCHASEBOX_H
