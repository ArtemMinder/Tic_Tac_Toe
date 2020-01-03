#include "settingwindow.h"
#include "ui_settingwindow.h"
#include <QMessageBox>

SettingWindow::SettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_singlePlayerButton_clicked()
{
  ui->firstNameInfo->setPlainText("");
  ui->secondNameInfo->setPlainText("Computer");
}

void SettingWindow::on_multiPlayerButton_clicked()
{
     ui->firstNameInfo->setPlainText("");
     ui->secondNameInfo->setPlainText("");
}




void SettingWindow::on_okButton_clicked()
{
    if( ui->secondNameInfo->toPlainText()=="" || ui->firstNameInfo->toPlainText()==""){
        QMessageBox::warning(this, tr("My Application"),
                                      tr("Enter the name of player(s)"),
                                      QMessageBox::Ok|
                                      QMessageBox::Cancel
                                       );

    }

    else if(ui->singlePlayerButton->isChecked()==false && ui->multiPlayerButton->isChecked()==false){
        QMessageBox::warning(this, tr("My Application"),
                                      tr("Select game mode"),
                                      QMessageBox::Ok|
                                      QMessageBox::Cancel
                                       );
}
    else{
        this->close();
    }
}
std::string SettingWindow::getMode(){
    if(ui->singlePlayerButton->isChecked()==true){
        return "0";
    }
    else if(ui->multiPlayerButton->isChecked()==true){
        return "1";
    }
    else {return "0";}
}
std::string SettingWindow::getFirstName(){
    firstName =  ui->firstNameInfo->toPlainText().toStdString();
    return firstName;

}
std::string SettingWindow::getSecondName(){
    secondName = ui->secondNameInfo->toPlainText().toStdString();
    return secondName;
}

void SettingWindow::on_exit_clicked()
{
    this->close();
    exit(0);
}

std::string SettingWindow::restart(){
    this->show();
   QMessageBox::StandardButton answer = QMessageBox::warning(this, tr("You have an unfinished game,"),
                                  tr(" do You want to continue?"),
                                  QMessageBox::Yes|
                                  QMessageBox::No
                                   );
   if(answer ==QMessageBox::Yes){
       return "1";
   }
   else {
       ui->firstNameInfo->setPlainText("");
       ui->secondNameInfo->setPlainText("");
       ui->multiPlayerButton->setChecked(false);
       ui->singlePlayerButton->setChecked(false);
       return "0";}
}
