#include "polksadd.h"
#include "ui_polksadd.h"

polksAdd::polksAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::polksAdd)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->add->setEnabled(true);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
}


void polksAdd::add()
{
    emit cldata(ui->polkName->text(), ui->commanderName->text(), ui->locationOfPolk->text());
    this->close();
    ui->polkName->clear();
    ui->commanderName->clear();
    ui->locationOfPolk->clear();
}

void polksAdd::check()
{
    if (!ui->locationOfPolk->text().isEmpty() && !ui->commanderName->text().isEmpty() && !ui->polkName->text().isEmpty())
        ui->add->setEnabled(true);
}



polksAdd::~polksAdd()
{
    delete ui;
}


void polksAdd::on_polkName_textChanged(const QString &arg1)
{
    check();
}


void polksAdd::on_pushBack_clicked()
{
    emit polksAddClose();
    this->close();

}

