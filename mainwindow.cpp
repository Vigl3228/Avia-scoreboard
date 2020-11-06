#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include <auth.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_2_triggered()
{

}

void MainWindow::on_action_triggered()
{
    connect(ui->action,SIGNAL(triggered()),this,SLOT(About_Lab1()));

}

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index+1));
    QTextCharFormat format;
    for(int i=0;i<=6;i++)
    {
        format.setForeground(qvariant_cast<QColor>("black"));
        ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i+1), format);
        if(i == index){
            format.setForeground(qvariant_cast<QColor>("green"));
            ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index+1), format);
        }
        if(i == 5 || i == 6){
            format.setForeground(qvariant_cast<QColor>("red"));
            ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i+1), format);
        }

    }
}

