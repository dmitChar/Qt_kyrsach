#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Polks();
    k = new Solder();
    mob = new mobilization();
    ui->mobButton->setEnabled(false);
    connect(ui->polkButton, SIGNAL(clicked()), this, SLOT(button_polks()));
    connect(form, &Polks::cl, this, &MainWindow::show);
    connect(ui->solderButton, SIGNAL(clicked()), this, SLOT(button_solders()));
    connect(k, &Solder::c, this, &MainWindow::show);
    connect(ui->mobButton, SIGNAL(clicked()), this, SLOT(button_mob()));
    connect(form, &Polks::cl, this, &MainWindow::mobButtonCheck);
    connect(k, &Solder::c, this, &MainWindow::mobButtonCheck);
    connect(mob, &mobilization::closeMob, this, &MainWindow::show);
    connect(k, SIGNAL(delSolder(QString)), mob, SLOT(getDelSolName(QString)));
    connect(form, SIGNAL(sayDelPolk(QString)), mob, SLOT(changeStatusByDel(QString)));
}

void MainWindow::button_polks()
{
    form->fill_table();
    form->show();
    this->close();
}

void MainWindow::button_solders()
{
    k->fill_table();
    k->show();
    this->close();
}

void MainWindow::button_mob()
{

    mob->show();
    mob->setSolder(k);
    mob->setPolk(form);
    this->close();
}

void MainWindow::mobButtonCheck()
{
    if (!k->mass.isEmpty() && !form->mass.isEmpty())
        ui->mobButton->setEnabled(true);
    else ui->mobButton->setEnabled(false);
}



MainWindow::~MainWindow()
{
    delete ui;
}

