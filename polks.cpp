#include "polks.h"
#include "ui_polks.h"

Polks::Polks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Polks)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->del->setEnabled(false);
    //ui->find->setEnabled(false);

    c = new polkAdd;

    connect(ui->back, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    connect(c, &polkAdd::cldata, this, &Polks::addlist);
    //connect(ui->find_input, SIGNAL(textChanged(QString)), this, SLOT(check_search_button()));
    connect(ui->delete_input, SIGNAL(textChanged(QString)), this, SLOT(check_del_button()));
    //connect(ui->find, SIGNAL(clcked()), this, SLOT(search_polk()));
    connect(ui->del, SIGNAL(clicked()), this, SLOT(delete_polk()));
    connect(c, &polkAdd::polksAddClose, this, &Polks::show);
    ui->delete_input->setValidator(new QDoubleValidator(0, 999999, 2, this));
}


void Polks::back()
{
    ui->add->setEnabled(true);
    this->close();
    emit cl();
}

void Polks::add()
{
    //ui->add->setEnabled(false);

    c->show();
}

void Polks::delete_polk()
{
    QString temp = "";
    if (ui->delete_input->text().toInt() - 1 < mass.size())
    {
        temp = mass[ui->delete_input->text().toInt() - 1]->get_name();
        emit sayDelPolk(temp);
        mass.removeAt(ui->delete_input->text().toInt() - 1);
        fill_table();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    ui->delete_input->clear();
    ui->del->setEnabled(true);
}

//void Polks::search_polk()
//{
//    for (int i = 0; i < mass.size(); i++)
//    {
//        polkData* obj = mass[i];
//        if (ui->find_input->text() == obj->get_sname())
//            ui->tableWidget->selectRow(i);
//    }

//    ui->find_input->clear();
//    ui->find->setEnabled(false);
//}

bool Polks::checkOnUnique(QString polkName)
{
    for (int i = 0; i < mass.size(); i ++)
    {
        if (polkName == mass[i]->get_name())
            return false;
    }
    return true;
}

void Polks::addlist(QString name, QString size, QString locat)
{
    if (checkOnUnique(name))
    {

    ui->add->setEnabled(true);
    polksData * obj = new polksData(name, size, locat);
    mass.append(obj);
    obj = NULL;
    fill_table();
    }

    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Введеный полк уже существует!");
        messageBox.setFixedSize(500,200);
    }
}

void Polks::fill_table()
{
    if (!mass.isEmpty())
    {
    ui->tableWidget_2->clearContents();
    int n = 0;
    for (int i = 0; i < mass.size(); i++)
    {
        polksData* obj = mass[i];
        n++;
        for (int j = 0; j < 4; j++)
        {
            QTableWidgetItem *item;

            if (j == 0)  item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->get_name());
            if (j == 2) item = new QTableWidgetItem(obj->get_location());
            if (j == 3) item = new QTableWidgetItem(obj->get_size());
            ui->tableWidget_2->setItem(i, j, item);
        }
    }
}
    else
    ui->tableWidget_2->clearContents();
}

void Polks::check_del_button()
{
    if (!mass.empty() && !ui->delete_input->text().isEmpty() && ui->delete_input->text() != " ")
        ui->del->setEnabled(true);
    else ui->del->setEnabled(false);
}

//void Polks::check_search_button()
//{
//    if (ui->find_input->text() != "")
//        ui->find->setEnabled(true);
//}

Polks::~Polks()
{
    delete ui;
}

void Polks::on_delete_input_textChanged(const QString &arg1)
{
    check_del_button();
}

