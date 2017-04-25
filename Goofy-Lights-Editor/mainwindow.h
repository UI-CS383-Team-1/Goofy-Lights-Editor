#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QColorDialog>
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

    QColorDialog *colorDialog;
    QColor currentColor;

    QGridLayout *mainFrame;

    Grid *grid;

    int currentAnimation = 0;

    QHBoxLayout *animationLayout;

    QWidget *animationFrame;
    bool shiftKeyPress = false;

protected:
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);

private:
    void assignColor(); //Method to assign color to the grid cell
    void assignBorder();//Method to assign border to the grid cell

private slots:
    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_triggered();

    void on_actionExport_triggered();

    void on_AddFrameButton_clicked();

    void on_DeleteFrameButton_clicked();

    void createGrid(QWidget *w, QGridLayout *frame, bool active);

    void on_QuitButton_clicked();

    void on_ColorChangeButton_clicked();

    void on_PrintButton_clicked();

};

#endif // MAINWINDOW_H
