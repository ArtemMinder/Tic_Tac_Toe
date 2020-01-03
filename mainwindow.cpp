#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked(){
    this->close();
    game.start();
}

 void MainWindow::on_exit_clicked()
{
    this->close();
    exit(0);
}
