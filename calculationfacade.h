#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QWidget>
#include "soldersData.h"
#include "calcarta.h"
#include "calcmoto.h"
#include "calcpulem.h"
#include "calcshturm.h"
#include "calctank.h"
#include "calcvodit.h"

class calculationFacade : public QWidget
{
    Q_OBJECT
public:
    explicit calculationFacade(QWidget *parent = nullptr);
    static int getCost(soldersData *value);

signals:

};

#endif // CALCULATIONFACADE_H
