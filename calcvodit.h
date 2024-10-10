#ifndef CALCVODIT_H
#define CALCVODIT_H

#include <QObject>
#include "soldersData.h"

class calcVodit : public QObject
{
    Q_OBJECT
public:
    explicit calcVodit(QObject *parent = nullptr);
    static int getCost(soldersData *value);
signals:

};

#endif // CALCVODIT_H
