#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>
#include <vector>
#include <QGridLayout>
#include <QFrame>
#include <QColor>
#include <QRgb>
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

    void on_pushButton_clicked();

    void createGrid(QWidget *w, QGridLayout *frame, bool active);

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void updateFrame();

    void playBack();

private:
    struct rgb{
        int r, g, b;
        QColor color2 = QColor(187,187,187);
    };

    struct state{

        rgb frame[10][20];
        unsigned long time;

    };
    bool isPlaying = false;
    Ui::MainWindow *ui;
    std::vector<state> animation;
    std::vector<state> playB;
    QColor currentColor;
    QGridLayout *mainFrame;
    rgb mainGrid[10][20];
    int currentAnimation = 0;
    int count = 0;
   // int track = 0;
    QHBoxLayout *animationLayout;
    QWidget *animationFrame;
    Grid *grid;

};


#endif // MAINWINDOW_H
