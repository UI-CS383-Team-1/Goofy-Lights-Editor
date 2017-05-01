#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QTime>
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

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:

    Ui::MainWindow *ui;

    std::vector<Grid> animation;

    QColorDialog *colorDialog;

    QColor currentColor;

    QGridLayout *mainFrame;

    Grid *grid;

    int currentAnimation = 0;

    int countDown;

    int lastTimeThrough = 0;

    int millisecondsToWait;

    int accum = 0;

    unsigned long int co = 0;

    float test;

    bool isPlaying = false;

    QHBoxLayout *animationLayout;

    QWidget *animationFrame;

    QTime time2;

    QTimer *timer;

private slots:
    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_triggered();

    void on_actionExport_triggered();

    void on_AddFrameButton_clicked();

    void on_DeleteFrameButton_clicked();

    void assignColor();

    void createGrid(QWidget *w, QGridLayout *frame, bool active);

    void on_QuitButton_clicked();

    void on_PrintButton_clicked();

    void setAnimation();

    void on_PlayButton_clicked();

    void updateFrame();

    void on_StopButton_clicked();

    void on_UpButton_clicked();

    void on_LeftButton_clicked();

    void on_RightButton_clicked();

    void on_DownButton_clicked();

    void on_DownLeft_clicked();

    void on_DownRight_clicked();

    void on_UpLeft_clicked();

    void on_UpRight_clicked();

    void delay(int millisecToWait);

    void on_SpeedDropdown_currentIndexChanged(int);

    void showTime();

};

#endif // MAINWINDOW_H
