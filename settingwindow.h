#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>
#include "ui_settingwindow.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();
   std::string getMode();
   std::string getFirstName();
   std::string getSecondName();
   std::string restart();

private slots:
    void on_singlePlayerButton_clicked();

    void on_multiPlayerButton_clicked();

    void on_okButton_clicked();  
    void on_exit_clicked();
private:
    Ui::SettingWindow *ui;
    std::string firstName{};
    std::string secondName{};
};

#endif // SETTINGWINDOW_H
