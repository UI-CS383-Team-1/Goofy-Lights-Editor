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

    QHBoxLayout *animationLayout;

    QWidget *animationFrame;

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

    void on_ColorChangeButton_clicked();

    void on_PrintButton_clicked();

    void setAnimation();
};

#endif // MAINWINDOW_H
