#include "polksData.h"

polksData::polksData(QWidget *parent)
    : QWidget{parent}
{

}

polksData::polksData(QString name, QString location, QString size)
{
    this->name = name;
    this->size = size;
    this->location = location;
}


QString polksData::get_size()
{
    return this->size;
}

QString polksData::get_name()
{
    return this->name;
}

void polksData::setSize(QString s)
{
    this->size = s;
}

QString polksData::get_location()
{
    return this->location;
}
