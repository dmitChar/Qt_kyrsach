#ifndef POLKS_H
#define POLKS_H

#include <QMessageBox>
#include <QTimer>
#include "polkAdd.h"
#include "polksData.h"

namespace Ui {
class Polks;
}

class Polks : public QWidget
{
    Q_OBJECT

public:
    explicit Polks(QWidget *parent = nullptr);
    ~Polks();
     QList<polksData *> mass;

signals:
    void cl();
    void sayDelPolk(QString);


public slots:
    void back();
    void add();
    void delete_polk();
    void addlist(QString name, QString size, QString locat);
    void fill_table();
    void check_del_button();
    bool checkOnUnique(QString polkName);

private slots:
    void on_delete_input_textChanged(const QString &arg1);

private:
    polkAdd *c;
    Ui::Polks *ui;
};

#endif // POLKS_H
