#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QDialog>
#include "settingwindow.h"


namespace Ui {
class GameplayWindow;
}

class GameplayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameplayWindow(QWidget *parent = nullptr);
    ~GameplayWindow();
     std::string getSign();
     std::string getMove();
     void getSelector(const std::string& name);
     void getFirst(const std::string& name);
     void getSecond(const std::string& name);
     void botPresrt();
     void botMove(const int& turn);
     void isRepaint();
     void clearField();
private slots:
     void on_crossSign_clicked();

     void on_zerosSign_clicked();

     void on_pushButton_1_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_9_clicked();

     void on_exit_clicked();


     void on_toMenu_clicked();

private:
     bool pressed = false;
     SettingWindow names;
     QString selector{};
     std::string sign{};
     std::string move{};
     Ui::GameplayWindow *ui;
     QString firstName{};
     QString secondName{};
};

#endif // GAMEPLAYWINDOW_H
