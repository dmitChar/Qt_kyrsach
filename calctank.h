#ifndef CALCTANK_H
#define CALCTANK_H

#include <QObject>
#include "soldersData.h"

class calcTank : public QObject
{
    Q_OBJECT
public:
    explicit calcTank(QObject *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCTANK_H
