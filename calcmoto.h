#ifndef CALCMOTO_H
#define CALCMOTO_H

#include <QObject>
#include "soldersData.h"

class calcMoto : public QObject
{
    Q_OBJECT
public:
    explicit calcMoto(QObject *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCMOTO_H
