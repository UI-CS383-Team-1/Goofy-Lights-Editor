#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

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
    struct rgb{
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
    rgb mainGrid[10][20];
    int currentAnimation = 0;
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
};

#endif // MAINWINDOW_H
