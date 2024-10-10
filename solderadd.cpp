#include "solderadd.h"
#include "ui_solderadd.h"

solderAdd::solderAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::solderAdd)
{
    ui->setupUi(this);
    ui->add->setEnabled(false);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    ui->sost->setCurrentIndex(0);
    ui->spec->setCurrentIndex(0);
    ui->categ->setCurrentIndex(0);

}

solderAdd::~solderAdd()
{
    delete ui;
}

void solderAdd::add()
{
    emit cll(ui->fio->text(), ui->dateEdit->date().toString("dd.MM.yyyy"), ui->spec->currentText(), ui->zvan->currentText(), ui->categ->currentText(), ui->sost->currentText());
    this->close();
    ui->fio->clear();
    ui->dateEdit->clear();
    ui->spec->setCurrentIndex(0);
    ui->zvan->setCurrentIndex(0);
    ui->categ->setCurrentIndex(0);
    ui->sost->setCurrentIndex(0);
}

void solderAdd::check()
{
    if (!ui->fio->text().isEmpty() && !ui->zvan->currentText().isEmpty() && ui->fio->text() != " ")
    {
        ui->add->setEnabled(true);
    }
    else ui->add->setEnabled(false);
}




void solderAdd::on_fio_textChanged(const QString &arg1)
{
    check();
}



