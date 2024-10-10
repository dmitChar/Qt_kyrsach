#include "mobilization.h"
#include "ui_mobilization.h"

mobilization::mobilization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mobilization)
{

    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(back()));
    ui->lineEdit->setValidator(new QDoubleValidator(0, 999999, 2, this));
    ui->pushButton_2->setEnabled(false);
}

mobilization::~mobilization()
{
    delete ui;
}

void mobilization::check()
{
    if (!ui->lineFio->text().isEmpty() && !ui->linePolk->text().isEmpty())
    {
        ui->pushButton->setEnabled(true);
    }
    else ui->pushButton->setEnabled(false);
}

void mobilization::checkDemobil()
{
    if (!ui->lineEdit->text().isEmpty() && !data.isEmpty())
        ui->pushButton_2->setEnabled(true);
    else ui->pushButton_2->setEnabled(false);
}

void mobilization::getDelSolName(QString text)
{
    decreacePolk(text);
}

void mobilization::setSolder(Solder *temp)
{
    this->sol = temp;
    fillTable_Sold();
}

void mobilization::setPolk(Polks *temp)
{
    this->p = temp;
    fillTable_Polk();
}

void mobilization::demobil(mobData *temp)
{
    for (int i = 0; i < sol->mass.size(); i ++)
    {
        if (sol->mass[i]->get_fio() == temp->getFio())
        {
            sol->mass[i]->set_sostoy("В запасе");
            decreacePolk(sol->mass[i]->get_fio());
            QMessageBox messageBox;
            messageBox.information(0, " ", "Военнослужащий успешно демобилизован!");
            messageBox.setFixedSize(500,200);
            fillTable_mob();
            fillTable_Sold();
            fillTable_Polk();
            ui->lineEdit->clear();
        }
    }
}

void mobilization::changeStatusByDel(QString polkName)
{
    if (!data.isEmpty())
    {

        QString soldName = "";
        for(int i = 0; i < data.size(); i++)
        {
            if (data[i]->getName() == polkName)
            {
                soldName = data[i]->getFio();

                for (int j = 0; j < sol->mass.size(); j++)
                {
                    if (soldName == sol->mass[j]->get_fio())
                        sol->mass[j]->set_sostoy("В запасе");
                }
            }
        }


        (polkName);
    fillTable_Polk();
    fillTable_Sold();
    fillTable_mob();
    }
}

void mobilization::delPolkFromMob(QString polkName)
{
    int s = data.size();
    for (int i = 0; i < s; i ++)
    {
        if (data[i]->getName() == polkName)
        {
            data.removeAt(i);
            i = -1;
            s = data.size();

        }
    }
}

void mobilization::fillTable_Sold()
{
    ui->tableWidget_2->clearContents();
    int n = 0;
    for (int i = 0; i < sol->mass.size(); i++)
    {
        soldersData * obj = sol->mass[i];
        n++;
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem *item;
            if (j == 0)  item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->get_fio());
            if (j == 2) item = new QTableWidgetItem((obj->get_date()));
            if (j == 3) item = new QTableWidgetItem(obj->get_spec());
            if (j == 4) item = new QTableWidgetItem(obj->get_zvan());
            if (j == 5) item = new QTableWidgetItem(obj->get_categ());
            if (j == 6) item = new QTableWidgetItem(obj->get_sostoy());
            ui->tableWidget_2->setItem(i, j, item);
        }
    }
}

void mobilization::fillTable_Polk()
{
    ui->tableWidget->clearContents();
    int n = 0;
    for (int i = 0; i < p->mass.size(); i++)
    {
        polksData* obj = p->mass[i];
        n++;
        for (int j = 0; j < 4; j++)
        {
            QTableWidgetItem *item;

            if (j == 0)  item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->get_name());
            if (j == 2) item = new QTableWidgetItem(obj->get_location());
            if (j == 3) item = new QTableWidgetItem(obj->get_size());
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

bool mobilization::checkFio(QString s)
{

    for (int i = 0; i < sol->mass.size()-1; i++)
    {
        if (sol->mass[i]->get_fio() == s)
            return true;
    }
    return false;
}

bool mobilization::checkPolk(QString s)
{

    for (int i = 0; i < sol->mass.size()-1; i++)
    {
        if (p->mass[i]->get_name() == s)
            return true;
    }
    return false;
}

soldersData* mobilization::getSolderByFio(QString fio)
{
    for (int i = 0; i < sol->mass.size()-1; i++)
    {
        if (sol->mass[i]->get_fio() == fio)
            return sol->mass[i];
    }
}

void mobilization::addMob()
{
    soldersData *temp;
    int price = 0;
    QString name = ui->lineFio->text();
    QString po = ui->linePolk->text();

    if (!checkFio(name))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!"," Введенного военнослужащего не существует!");
        messageBox.setFixedSize(500,200);
    }

    else if (!checkPolk(po))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!"," Введенного полка не существует!");
        messageBox.setFixedSize(500,200);
    }

    else
    {
        temp = getSolderByFio(name);
        if (!checkOnStatus(temp))
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Ошибка!","Введеный военнослужащий не может быть мобилизован, так как он не находится в запасе!");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            if (!checkOnSostoy(temp))
            {
                QMessageBox messageBox;
                messageBox.critical(0,"Ошибка!","Введеный военнослужащий не может быть мобилизован из за категории годности!");
                messageBox.setFixedSize(500,200);
            }
            else
            {

                price = calculationFacade::getCost(temp);
                mobData* newest = new mobData(po, name, QString::number(price));
                data.append(newest);
                newest = NULL;
                ui->lineFio->clear();
                ui->linePolk->clear();

                changeStatus(temp);



                increacePolk(name);
                fillTable_Polk();
                fillTable_mob();
                fillTable_Sold();



            }
        }
    }
}

void mobilization::decreacePolk(QString name)
{
    if (!data.isEmpty())
    {
    int size = 0;
    QString polkName = "";

        for (int i = 0; i < data.size(); i++)
        {
                if (data[i]->getFio() == name)
                {
                    polkName = data[i]->getName();
                }
        }

    for (int i = 0; i < p->mass.size(); i++)
    {
        if (p->mass[i]->get_name() == polkName)
        {
            size = p->mass[i]->get_size().toInt();
            size--;
            p->mass[i]->setSize(QString::number(size));
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]->getFio() == name)
            data.removeAt(i);
    }
    fillTable_mob();
    fillTable_Polk();
    }

}

bool mobilization::checkOnIncreacePolk(QString name)
{
    for (int i = 0; i < data.size(); i++)
   {
            if (data[i]->getFio() == name)
            {
                return true;
            }
    }
    return false;
}

void mobilization::increacePolk(QString name)
{
    QString polkName = "";
    int size = 0;

        for (int i = 0; i < data.size(); i++)
       {
                if (data[i]->getFio() == name)
                {
                    polkName = data[i]->getName();
                }
        }

        for (int i = 0; i < p->mass.size(); i++)
        {
            if (p->mass[i]->get_name() == polkName)
            {
                size = p->mass[i]->get_size().toInt();
                size++;
                p->mass[i]->setSize(QString::number(size));
            }
        }


}

bool mobilization::checkOnStatus(soldersData *temp)
{
    return (temp->get_sostoy() == "В запасе");
}

bool mobilization::checkOnSostoy(soldersData* temp)
{
    if (temp->get_categ() == "Г" || temp->get_categ() == "Д")
        return false;
    else return true;
}

void mobilization::changeStatus(soldersData* temp)
{
    for (int i = 0; i < sol->mass.size(); i++)
    {
        if (sol->mass[i]->get_fio() == temp->get_fio())
            sol->mass[i]->set_sostoy("Мобилизован");

    }
    fillTable_Sold();
}


void mobilization::fillTable_mob()
{

    ui->tableWidget_3->clearContents();
    int n = 0;
    for (int i = 0; i < data.size(); i++)
    {
        mobData * obj = data[i];
        n++;
        for (int j = 0; j < 4; j++)
        {
            QTableWidgetItem *item;
            if (j == 0)  item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->getName());
            if (j == 2) item = new QTableWidgetItem((obj->getFio()));
            if (j == 3) item = new QTableWidgetItem(obj->getPrice());
            ui->tableWidget_3->setItem(i, j, item);
        }
    }

    QString name = ui->lineFio->text();
    QString po = ui->linePolk->text();

//    if (!checkFio(name))
//    {
//        QMessageBox messageBox;
//        messageBox.critical(0,"Ошибка!"," Введенного военнослужащего не существует!");
//        messageBox.setFixedSize(500,200);
//    }

//    else if (!checkPolk(po))
//    {
//        QMessageBox messageBox;
//        messageBox.critical(0,"Ошибка!"," Введенного полка не существует!");
//        messageBox.setFixedSize(500,200);
//    }

//    else
//    {
//        ui->tableWidget_3->clearContents();
//        int n = 0;
//        for (int i = 0; i < sol->mass.size(); i++)
//        {
//            polksData* obj = sol->mass[i];
//            n++;
//            for (int j = 0; j < 4; j++)
//            {
//                QTableWidgetItem *item;

//                if (j == 0)  item = new QTableWidgetItem(QString::number(n));
//                if (j == 1) item = new QTableWidgetItem(obj->get_name());
//                if (j == 2) item = new QTableWidgetItem(obj->get_size());
//                if (j == 3) item = new QTableWidgetItem(obj->get_location());
//                ui->tableWidget_3->setItem(i, j, item);
//            }
//        }
//    }



}



void mobilization::back()
{
    this->close();
    emit closeMob();
}

void mobilization::on_pushButton_clicked()
{
    addMob();

}


void mobilization::on_linePolk_textChanged(const QString &arg1)
{
    check();
}


void mobilization::on_lineFio_textChanged(const QString &arg1)
{
    check();
}


void mobilization::on_pushButton_2_clicked()
{
    int i = ui->lineEdit->text().toInt()-1;
    if (i >= 0 && i < data.size())
        demobil(data.at(i));
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Вы ввели некорректный номер!");
        messageBox.setFixedSize(500,200);
    }
}


void mobilization::on_lineEdit_textChanged(const QString &arg1)
{
    checkDemobil();
}

