#ifndef MOBDATA_H
#define MOBDATA_H

#include <QWidget>

class mobData : public QWidget
{
    Q_OBJECT
public:
    mobData(QString name, QString fio, QString price);
    QString getName();
    QString getPrice();
    QString getFio();

private:
    QString name;
    QString fio;
    QString price;

};

#endif // MOBDATA_H
