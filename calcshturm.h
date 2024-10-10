#ifndef CALCSHTURM_H
#define CALCSHTURM_H

#include <QObject>
#include "soldersData.h"

class calcShturm : public QObject
{
    Q_OBJECT
public:
    explicit calcShturm(QObject *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCSHTURM_H
