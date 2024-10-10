#ifndef CALCARTA_H
#define CALCARTA_H

#include <QObject>
#include "soldersData.h"

class calcArta : public QObject
{
    Q_OBJECT
public:
    explicit calcArta(QObject *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCARTA_H
