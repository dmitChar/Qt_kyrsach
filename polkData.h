#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include <QObject>

class polkData : public QObject
{
public:
    polkData(QString name, QString size, QString location);
    QString get_name();
    QString get_size();
    QString get_location();

private:
    QString name;
    QString size;
    QString location;
};

#endif // CLIENTDATA_H
