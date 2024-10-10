#include "polkData.h"


polkData::polkData(QString name, QString size, QString location)
{
    this->name = name;
    this->size = size;
    this->location = location;
}


QString polkData::get_size()
{
    return this->size;
}

QString polkData::get_name()
{
    return this->name;
}

QString polkData::get_location()
{
    return this->location;
}
