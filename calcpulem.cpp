#include "calcpulem.h"

calcPulem::calcPulem(QObject *parent)
    : QObject{parent}
{

}

int calcPulem::getCost(soldersData *value)//функция расчета стоимости для эконом класса
{
    QString zvan = value->get_zvan();
    int price = 160000;

    if (zvan == "Рядовой")
        price *=1.1;
    if (zvan == "Старшина")
        price *= 1.3;
    if (zvan == "Прапорщик")
        price *= 1.5;
    if (zvan == "Лейтенант")
        price *= 1.7;
    if (zvan == "Капитан")
        price *= 2;
    if (zvan == "Майор")
        price *= 2.5;
    if (zvan == "Полковник")
        price *= 3;
    if (zvan == "Маршал")
        price *= 4;

    return price;
}
