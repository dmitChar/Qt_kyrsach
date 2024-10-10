#include "polkAdd.h"
#include "ui_polkAdd.h"

polkAdd::polkAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::polkAdd)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->setupUi(this);
    ui->add->setEnabled(true);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->pushBack, SIGNAL(clicked()), this, SLOT(clos()));
    //connect(ui->commanderName, SIGNAL(textChanged(QString s)), this, SLOT(check()));
    //connect(ui->locationOfPolk, SIGNAL(textChanged(QString s)), this, SLOT(check()));
    //connect(ui->polkName, SIGNAL(textChanged(QString s)), this, SLOT(check()));
    ui->locationOfPolk->setValidator(new QDoubleValidator(0, 999999, 2, this));



}

polkAdd::~polkAdd()
{
    delete ui;
}


void polkAdd::add()
{
    emit cldata(ui->polkName->text(), ui->commanderName->text(), ui->locationOfPolk->text());
    this->close();
    ui->polkName->clear();
    ui->commanderName->clear();
    ui->locationOfPolk->clear();
}

void polkAdd::check()
{
    if (!ui->locationOfPolk->text().isEmpty() && !ui->commanderName->text().isEmpty() && !ui->polkName->text().isEmpty())
        ui->add->setEnabled(true);
}

void polkAdd::clos(){
    emit polksAddClose();
    this->close();
    ui->polkName->clear();
    ui->commanderName->clear();
    ui->locationOfPolk->clear();
}


void polkAdd::on_polkName_textChanged()
{
    check();
}


void polkAdd::on_commanderName_textChanged()
{
    check();
}


void polkAdd::on_locationOfPolk_textChanged()
{
    check();
}

