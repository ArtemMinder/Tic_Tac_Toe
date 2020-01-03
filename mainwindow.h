#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "ui_mainwindow.h"
#include "settingwindow.h"
#include "Tic_Tac_Toe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_start_clicked();

    void on_exit_clicked();

private:
    SettingWindow setWindow;
    Ui::MainWindow *ui;
    Game game;
};

#endif // MAINWINDOW_H
