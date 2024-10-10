#include "calculationfacade.h"

calculationFacade::calculationFacade(QWidget *parent)
    : QWidget{parent}
{

}

int calculationFacade::getCost(soldersData *value)//функция расчитывающая и возвращающая размер зп
{
    int cost = 0;
    QString temp = value->get_spec();

    if (temp == "Мотострелок")
        cost = calcMoto::getCost(value);
    if (temp == "Танкист")
        cost = calcTank::getCost(value);
    if (temp == "Артиллерист")
        cost = calcArta::getCost(value);
    if (temp == "Пулеметчик")
        cost = calcPulem::getCost(value);
    if (temp == "Штурмовик")
        cost = calcShturm::getCost(value);
    if (temp == "Водитель-маханик")
        cost = calcVodit::getCost(value);

    return cost;
}
