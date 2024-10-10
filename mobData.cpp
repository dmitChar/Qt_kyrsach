#include "mobData.h"

mobData::mobData(QString name, QString fio, QString price)
{
    this->fio = fio;
    this->price = price;
    this->name = name;
}

QString mobData::getName()
{
    return this->name;
}

QString mobData::getFio()
{
    return this->fio;
}

QString mobData::getPrice()
{
    return this->price;
}
