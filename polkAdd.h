#ifndef POLKADD_H
#define POLKADD_H

#include <QWidget>
#include <QDoubleValidator>

namespace Ui {
class polkAdd;
}

class polkAdd : public QWidget
{
    Q_OBJECT

public:
    explicit polkAdd(QWidget *parent = nullptr);
    ~polkAdd();

signals:
    void cldata(QString, QString, QString);//сигнал, вызывающийся при добавлении нового полка
    void polksAddClose();

public slots:
    void check();//слот для проверки вводимых данных

private slots:
    void add();//слот для добавления нового полка
    void clos();//слот выхода из текущего окна
    void on_polkName_textChanged();//слот для отслеживания вводымых данных в строке polkName
    void on_commanderName_textChanged();//слот для отслеживания вводимых данных в строке commanderName
    void on_locationOfPolk_textChanged();//слот для отслеживания вводимых данных в строке locationOfPolk

private:
    Ui::polkAdd *ui;
};

#endif // POLKADD_H
