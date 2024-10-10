#include "solder.h"
#include "ui_solder.h"

Solder::Solder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Solder)
{

    ui->setupUi(this);
    ui->del->setEnabled(false);
    connect(ui->back, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->addd, SIGNAL(clicked()), this, SLOT(add()));
    connect(&ka, &solderAdd::cll, this, &Solder::addlist);
    connect(ui->delete_input, SIGNAL(textChanged(QString)), this, SLOT(check_del_button()));
    connect(ui->del, SIGNAL(clicked()), this, SLOT(del_el()));
    ui->delete_input->setValidator(new QDoubleValidator(0, 999999, 2, this));

}

Solder::~Solder()
{
    delete ui;
}

void Solder::back()
{
    this->close();
    ui->addd->setEnabled(true);
    emit c();
}

void Solder::add()
{
    //ui->addd->setEnabled(false);
    ka.show();

}

bool Solder::checkOnUnique(QString soldName)
{
    for (int i = 0; i < mass.size(); i ++)
    {
        if (soldName == mass[i]->get_fio())
            return false;
    }
    return true;
}

void Solder::addlist(QString fio, QString date, QString spec, QString zvan, QString cat, QString sost)
{
    if (checkOnUnique(fio))
    {
        ui->addd->setEnabled(true);
        soldersData* newest = new soldersData(fio, date, spec, zvan, cat, sost);
        mass.append(newest);
        newest = NULL;
        fill_table();
        check_del_button();
    }

    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Введеный военнослужащий уже существует!");
        messageBox.setFixedSize(500,200);
    }
}

void Solder::fill_table()
{
    if (!mass.isEmpty())
    {
    ui->tableWidget->clearContents();
    int n = 0;
    for (int i = 0; i < mass.size(); i++)
    {
        soldersData * obj = mass[i];
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
            ui->tableWidget->setItem(i, j, item);
        }
    }
}
    else ui->tableWidget->clearContents();
}

void Solder::check_del_button()
{
    if (!mass.empty() && !ui->delete_input->text().isEmpty() && ui->delete_input->text() != " ")
        ui->del->setEnabled(true);
    else ui->del->setEnabled(false);
}

//void Solder::check_search_button()
//{
//    if (ui->find_input->text() != "")
//        ui->find->setEnabled(true);
//}

//void solders::search_el()
//{
//    for (int i = 0; i < mass.size(); i++)
//    {
//        soldersData* obj = mass[i];
//        if (ui->find_input->text() == obj->get_name())
//        {
//            ui->tableWidget->selectRow(i);
//        }
//    }
//    ui->find_input->setText("");
//}

void Solder::del_el()
{
    QString temp = "";
    if (ui->delete_input->text().toInt() - 1 < mass.size())
    {
        temp = mass[ui->delete_input->text().toInt() - 1]->get_fio();
        mass.removeAt(ui->delete_input->text().toInt() - 1);
        fill_table();
        emit delSolder(temp);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    ui->delete_input->setText("");
    check_del_button();
}


void Solder::on_delete_input_textChanged(const QString &arg1)
{
    check_del_button();
}

