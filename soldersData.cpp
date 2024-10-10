#include "soldersData.h"



soldersData::soldersData(QString fio, QString date, QString spec, QString zvan, QString categ, QString sostoy)
{
    this->fio = fio;
    this->date = date;
    this->spec = spec;
    this->zvan = zvan;
    this->categ = categ;
    this->sostoy=sostoy;

}

QString soldersData::get_fio()
{
    return this->fio;
}

QString soldersData::get_date()
{
    return this->date;
}

QString soldersData::get_zvan()
{
    return this->zvan;
}

QString soldersData::get_categ()
{
    return this->categ;
}

QString soldersData::get_spec()
{
    return this->spec;
}

void soldersData::set_sostoy(QString sostoy)
{
    this->sostoy = sostoy;
}

QString soldersData::get_sostoy()
{
    return this->sostoy;
}

bool soldersData::get_exist()
{
    return this->exist;
}

void soldersData::change_exist()
{
    this->exist = !(this->exist);
}
