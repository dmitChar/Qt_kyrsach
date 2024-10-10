#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "polks.h"
#include "Solder.h"
#include "mobilization.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Polks *form;
    Solder *k;
    mobilization *mob;

signals:

private slots:
    void button_polks();
    void button_solders();
    void button_mob();
    void mobButtonCheck();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
