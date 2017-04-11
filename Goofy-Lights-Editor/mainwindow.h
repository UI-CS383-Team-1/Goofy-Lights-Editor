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

private:

    Ui::MainWindow *ui;

    std::vector<Grid> animation;

    std::vector<Grid> playB;

    QColor currentColor;

    QGridLayout *mainFrame;

    Grid *grid;

    int currentAnimation = 0;

    int count = 0;

    bool isPlaying = false;

    QHBoxLayout *animationLayout;

    QWidget *animationFrame;

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

    void createGrid(QWidget *w, QGridLayout *frame, bool active);

    void on_pushButton_8_clicked();

    void on_Scrollbar_clicked();

    void on_pushButton_clicked();

    void updateFrame();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
