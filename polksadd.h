#ifndef POLKSADD_H
#define POLKSADD_H

#include <QWidget>


namespace Ui {
class polksAdd;
}

class polksAdd : public QWidget
{
    Q_OBJECT

public:
    explicit polksAdd(QWidget *parent = nullptr);
    ~polksAdd();

signals:
    void cldata(QString, QString, QString);
    void polksAddClose();

private slots:
    void add();
    void check();



    void on_polkName_textChanged(const QString &arg1);

    void on_pushBack_clicked();

private:
    Ui::polksAdd *ui;
};

#endif // POLKSADD_H
