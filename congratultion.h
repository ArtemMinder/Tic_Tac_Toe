#ifndef CONGRATULTION_H
#define CONGRATULTION_H

#include <QDialog>
#include "gameplaywindow.h"
#include "settingwindow.h"

namespace Ui {
class Congratultion;
}

class Congratultion : public QDialog
{
    Q_OBJECT

public:
    explicit Congratultion(QWidget *parent = nullptr);
    ~Congratultion();
    void winner(const std::string& sign);
    std::string again();

private slots:
    void on_toExit_clicked();

    void on_again_clicked();


private:
    SettingWindow *setting;
    GameplayWindow *newGame;
    Ui::Congratultion *ui;
};

#endif // CONGRATULTION_H
