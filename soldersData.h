#ifndef KINODATA_H
#define KINODATA_H

#include <QObject>
#include <QDate>

class soldersData
{
public:
    soldersData(QString name, QString date, QString spec, QString zvan, QString categ, QString sostoy);
    QString get_fio();
    QString get_date();
    QString get_spec();
    QString get_zvan();
    QString get_categ();
    QString get_sostoy();
    void set_sostoy(QString);
    bool get_exist();
    void change_exist();

private:
    QString fio;//поле для хранения ФИО военнослужащего
    QString date;//поле для хранения даты рождения военнослужащего
    QString spec;//поле для хранения специальности военнослужащего
    QString zvan;//поле для хранения звания военнослужащего
    QString categ;//поле для хранения категории военнослжащего
    QString sostoy;//поле для хранения состояния военнослужащего
    bool exist = 1;
};

#endif
