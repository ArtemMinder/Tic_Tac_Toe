#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"
#include <QMessageBox>
#include <QIcon>

GameplayWindow::GameplayWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameplayWindow)
{
    ui->setupUi(this);
    ui->pushButton_1->blockSignals(false);
    ui->pushButton_2->blockSignals(false);
    ui->pushButton_3->blockSignals(false);
    ui->pushButton_4->blockSignals(false);
    ui->pushButton_5->blockSignals(false);
    ui->pushButton_6->blockSignals(false);
    ui->pushButton_7->blockSignals(false);
    ui->pushButton_8->blockSignals(false);
    ui->pushButton_9->blockSignals(false);
}

GameplayWindow::~GameplayWindow()
{
    delete ui;
}

void GameplayWindow::getSelector(const std::string& name){
    selector = QString::fromStdString(name);
    ui->playConsole->setText(selector+", you are lucky\n     to pick a sign first.");
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->toMenu->setEnabled(false);

}
void GameplayWindow::getFirst(const std::string& name){
    firstName = QString::fromStdString(name);
}
void GameplayWindow::getSecond(const std::string& name){
    secondName = QString::fromStdString(name);
}

std::string GameplayWindow::getSign(){
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->toMenu->setEnabled(true);
 return sign;
}

void GameplayWindow::on_crossSign_clicked()
{
    sign = "1";
    ui->crossSign->setVisible(false);
    ui->zerosSign->setVisible(false);
    ui->playConsole->setText(selector+", your turn.");
    this->close();
}

void GameplayWindow::on_zerosSign_clicked()
{
    sign = "0";
    ui->zerosSign->setVisible(false);
    ui->crossSign->setVisible(false);
    ui->playConsole->setText(selector+", your turn.");
    this->close();
}

void GameplayWindow::on_pushButton_1_clicked()
{

   move="0";
   if(sign =="1"){
       ui->pushButton_1->setIcon(QIcon(":/resources/resources/cross.ico"));
       ui->pushButton_1->blockSignals(true);
       sign = "0";
   }
   else if(sign=="0"){
       ui->pushButton_1->setIcon(QIcon(":/resources/resources/zero.ico"));
       ui->pushButton_1->blockSignals(true);
       sign = "1";
   }
   if(selector == firstName){
       selector = secondName;
       ui->playConsole->setText(selector+", your turn.");
   }
   else {selector = firstName;
   ui->playConsole->setText(selector+", your turn.");
   }
  // ui->pushButton_1->setEnabled(false);
   pressed = true;
   this->close();
}


void GameplayWindow::on_pushButton_2_clicked()
{
    move="1";
    if(sign =="1"){
        ui->pushButton_2->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_2->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_2->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_2->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
    //ui->pushButton_2->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_3_clicked()
{
    move="2";
    if(sign =="1"){
        ui->pushButton_3->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_3->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_3->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_3->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
  //  ui->pushButton_3->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_4_clicked()
{
    move="3";
    if(sign =="1"){
        ui->pushButton_4->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_4->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_4->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_4->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
    //ui->pushButton_4->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_5_clicked()
{
    move="4";
    if(sign =="1"){
        ui->pushButton_5->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_5->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_5->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_5->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
   // ui->pushButton_5->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_6_clicked()
{
    move="5";
    if(sign =="1"){
        ui->pushButton_6->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_6->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_6->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_6->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
   // ui->pushButton_6->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_7_clicked()
{
    move="6";
    if(sign =="1"){
        ui->pushButton_7->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_7->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_7->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_7->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
  //  ui->pushButton_7->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_8_clicked()
{
    move="7";
    if(sign =="1"){
        ui->pushButton_8->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_8->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_8->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_8->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
   // ui->pushButton_8->setEnabled(false);
    this->close();
}

void GameplayWindow::on_pushButton_9_clicked()
{
    move="8";
    if(sign =="1"){
        ui->pushButton_9->setIcon(QIcon(":/resources/resources/cross.ico"));
         ui->pushButton_9->blockSignals(true);
        sign = "0";
    }
    else if(sign=="0"){
        ui->pushButton_9->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_9->blockSignals(true);
        sign = "1";
    }
    if(selector == firstName){
        selector = secondName;
        ui->playConsole->setText(selector+", your turn.");
    }
    else {selector = firstName;
    ui->playConsole->setText(selector+", your turn.");
    }
   // ui->pushButton_9->setEnabled(false);
    this->close();
}
std::string GameplayWindow::getMove(){
    return move;
};

void GameplayWindow::on_exit_clicked()
{
    this->close();
    exit(0);
}
void GameplayWindow::botPresrt(){
    ui->crossSign->setVisible(false);
    ui->zerosSign->setVisible(false);
    sign = "1";
    selector = firstName;
    secondName = firstName;
    ui->playConsole->setText(selector+", your turn.");
}

    void GameplayWindow::botMove(const int& turn){
    move = std::to_string(turn);
    switch (turn) {
    case 0: {
        ui->pushButton_1->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_1->blockSignals(true);
        sign = "1";
        break;
    }
    case 1: {
        ui->pushButton_2->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_2->blockSignals(true);
         sign = "1";
        break;
    }
    case 2: {
        ui->pushButton_3->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_3->blockSignals(true);
         sign = "1";
        break;
    }
    case 3: {
        ui->pushButton_4->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_4->blockSignals(true);
         sign = "1";
        break;
    }
    case 4: {
        ui->pushButton_5->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_5->blockSignals(true);
         sign = "1";
        break;
    }
    case 5: {
        ui->pushButton_6->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_6->blockSignals(true);
         sign = "1";
        break;
    }
    case 6: {
        ui->pushButton_7->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_7->blockSignals(true);
         sign = "1";
        break;
    }
    case 7: {
        ui->pushButton_8->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_8->blockSignals(true);
         sign = "1";
        break;
    }
    case 8: {
        ui->pushButton_9->setIcon(QIcon(":/resources/resources/zero.ico"));
         ui->pushButton_9->blockSignals(true);
         sign = "1";
        break;
    }
    default:break;
} }
    void GameplayWindow::isRepaint(){
            QMessageBox::warning(this, tr("My Application"),
                                          tr("Enter the name of player(s)"),
                                          QMessageBox::Ok|
                                          QMessageBox::Cancel
                                           );
        }






void GameplayWindow::on_toMenu_clicked()
{
    move ="9";
    this->close();
}
void GameplayWindow::clearField(){
    ui->pushButton_1->setIcon(QIcon());
    ui->pushButton_2->setIcon(QIcon());
    ui->pushButton_3->setIcon(QIcon());
    ui->pushButton_4->setIcon(QIcon());
    ui->pushButton_5->setIcon(QIcon());
    ui->pushButton_6->setIcon(QIcon());
    ui->pushButton_7->setIcon(QIcon());
    ui->pushButton_8->setIcon(QIcon());
    ui->pushButton_9->setIcon(QIcon());
    ui->pushButton_1->blockSignals(false);
    ui->pushButton_2->blockSignals(false);
    ui->pushButton_3->blockSignals(false);
    ui->pushButton_4->blockSignals(false);
    ui->pushButton_5->blockSignals(false);
    ui->pushButton_6->blockSignals(false);
    ui->pushButton_7->blockSignals(false);
    ui->pushButton_8->blockSignals(false);
    ui->pushButton_9->blockSignals(false);
    ui->crossSign->setVisible(true);
    ui->zerosSign->setVisible(true);
}
