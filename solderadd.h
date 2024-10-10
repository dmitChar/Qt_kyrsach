#ifndef SOLDERADD_H
#define SOLDERADD_H

#include <QWidget>
#include "soldersData.h"
#include <QObject>

namespace Ui {
class solderAdd;
}

class solderAdd : public QWidget
{
    Q_OBJECT

public:
    explicit solderAdd(QWidget *parent = nullptr);
    ~solderAdd();

public slots:
    void add();//добавление нового солдата
    void check();//проверка на добавление солдата

signals:
    void cll(QString, QString, QString, QString, QString, QString);//сигнал, вызывающийся при добавлении нового солдата

private slots:
    void on_fio_textChanged(const QString &arg1);//слот, отслеживающий вводимые данных



private:
    Ui::solderAdd *ui;
};

#endif // SOLDERADD_H
