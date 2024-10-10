#ifndef MOBILIZATION_H
#define MOBILIZATION_H

#include <QWidget>
#include "polks.h"
#include "solder.h"
#include "calculationfacade.h"
#include "mobData.h"
#include <QDoubleValidator>

namespace Ui {
class mobilization;
}

class mobilization : public QWidget
{
    Q_OBJECT

public:
    explicit mobilization(QWidget *parent = nullptr);
    ~mobilization();
    void setSolder(Solder *temp);//добавление нового солдата
    void setPolk(Polks *temp);//передача солдата полку
    void fillTable_Sold();//заполнение таблицы солдат
    void fillTable_Polk();//заполнение таблицы полков
    void fillTable_mob();//заполнение таблицы моблизации
    void addMob();//мобилизация солдата
    bool checkFio(QString);//проверка ФИО солдата
    bool checkPolk(QString);//проверка полка
    soldersData *getSolderByFio(QString fio);//получение данных солдата по ФИО
    bool checkOnStatus(soldersData *temp);//проверка статуса солдата
    bool checkOnSostoy(soldersData* temp);//проверка состояния солдата
    void changeStatus(soldersData* temp);//изменение статуса солдата
    void increacePolk(QString name);//увелечение численности полка
    void decreacePolk(QString name);//уменьшение численности полка
    bool checkOnIncreacePolk(QString name);//проверка на увеличение полка
    void delPolkFromMob(QString polkName);//удаление полка
    void demobil(mobData *);//демобилизация солдата
    QList <mobData * > data;

private slots:
    void back();//возврат на главное меню
    void getDelSolName(QString);//уменьшение численности полка по ФИО солдата
    void changeStatusByDel(QString);//изменение статуса солдата в случае удаления полка
    void on_pushButton_clicked();//слот для обработки нажития кнопки добавления мобилизации
    void check();//слот для проверки кнопки добавления мобилизованного
    void checkDemobil();//слот для проверка кнопки демобилизации
    void on_linePolk_textChanged(const QString &arg1);//слот для отслеживания данных в строке Polk
    void on_lineFio_textChanged(const QString &arg1);//слот для отслеживания данных в строке FIO
    void on_pushButton_2_clicked();//слот для обработки нажатия кнопки демобилизации
    void on_lineEdit_textChanged(const QString &arg1);//слот для отслеживания данных в строке lineEdit

signals:
    void closeMob();//сигнал для выхода из окна mobilization

private:
    Ui::mobilization *ui;
    Solder *sol;
    Polks *p;


};

#endif // MOBILIZATION_H
