#ifndef POLKSDATA_H
#define POLKSDATA_H

#include <QWidget>

class polksData : public QWidget
{
    Q_OBJECT
public:
    explicit polksData(QWidget *parent = nullptr);
    polksData(QString name, QString size, QString location);
    QString get_name();
    QString get_size();
    QString get_location();
    void setSize(QString);

private:
    QString name;//поле для хранения названия полка
    QString size;//поле для хранения размера полка
    QString location;//поле для хранения командира полка
};

#endif // POLKSDATA_H
