#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include "grid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_triggered();

    void on_actionExport_triggered();

    void on_pushButton_9_clicked();

    void on_AddFrameButton_clicked();

    void on_DeleteFrameButton_clicked();

    void assignColor();

    void on_pushButton_8_clicked();

private:   
    struct rgb {
        int r, g, b;
    };

    struct state{
        rgb frame[10][20];
        unsigned long time;
    };

    Ui::MainWindow *ui;
    std::vector<state> animation;
    QColor currentColor;
    QGridLayout *mainFrame;

    int currentAnimation = 0;
    Grid *grid;
};

#endif // MAINWINDOW_H
