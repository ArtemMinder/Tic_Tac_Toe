#include "congratultion.h"
#include "ui_congratultion.h"

Congratultion::Congratultion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Congratultion)
{
    ui->setupUi(this);
}

Congratultion::~Congratultion()
{
    delete ui;
}
void Congratultion::winner(const std::string& sign){
    if(sign =="X"){
   ui->winner->setText("Congratulation!\nX - Wins!");
    }
    else if(sign =="O"){
   ui->winner->setText("Congratulation!\nO - Wins!");
    }
    else {
         ui->winner->setText("Dead Heat!");
         ui->logo->setIcon(QIcon(":/resources/resources/Draw.png"));

    }
}

void Congratultion::on_toExit_clicked()
{
    this->close();
    exit(0);
}



void Congratultion::on_again_clicked()
{
   this->close();
}


std::string Congratultion::again(){
return "1";
}


