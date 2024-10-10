#ifndef CALCPULEM_H
#define CALCPULEM_H

#include <QObject>
#include "soldersData.h"

class calcPulem : public QObject
{
    Q_OBJECT
public:
    explicit calcPulem(QObject *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCPULEM_H
