#ifndef SOLDER_H
#define SOLDER_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include "solderAdd.h"
#include "soldersData.h"



namespace Ui {
class Solder;
}

class Solder : public QWidget
{
    Q_OBJECT

public:
    explicit Solder(QWidget *parent = nullptr);
    ~Solder();
    solderAdd ka;
    QList<soldersData*> mass;

signals:
    void c();
    void delSolder(QString);

public slots:
    void back();
    void add();
    void addlist(QString fio, QString date, QString spec, QString zvan, QString cat, QString sost);
    void del_el();
    void check_del_button();
    void fill_table();
    bool checkOnUnique(QString soldName);

private slots:
    void on_delete_input_textChanged(const QString &arg1);

private:
    Ui::Solder *ui;
};

#endif // SOLDER_H
