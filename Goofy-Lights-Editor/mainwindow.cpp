#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include <string>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(3);

    /* creating grid size with default 10*20 */
    grid = new Grid();

    //Clear main grid
    state initFrame;
    rgb blank;
    blank.r = 128;
    blank.g = 128;
    blank.b = 128;
    grid->setAllCellColor(QColor(128,128,128));
    for(int r = 0; r < grid->getGridRowCount(); r++){
        for(int c = 0; c < grid->getGridColumnCount(); c++){
            initFrame.frame[r][c] = blank;
        }
    }

    //Add initial state to animation
    initFrame.time = 0;
    animation.push_back(initFrame);

    //Set current color to red
    currentColor.setRgb(255, 0, 0);

    //Build grid
    QWidget *w = ui->GridWidget;
    mainFrame = new QGridLayout;
    QSizePolicy *policy = new QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    policy->setHeightForWidth(true);

    for(int i = 0; i < grid->getGridRowCount(); i++)
    {
        for(int j = 0; j < grid->getGridColumnCount(); j++)
        {
            //Creating a push button
            QPushButton *tmp = new QPushButton;

            //Assigning the color to grid cell and size
            QColor cellColor = grid->getCellColor(i,j);
            QString qss = QString("background-color: %1").arg(cellColor.name());
            tmp->setStyleSheet(qss);
            tmp->setSizePolicy(*policy);

            //Adding cell click event
            connect(tmp, SIGNAL(clicked()), this, SLOT(assignColor()));

            //Add the cell to Main Frame or main grid
            mainFrame->addWidget(tmp,i,j,1,1);
        }
    }

    /*setting the color of the Buttons in the grid as gray*/
    w->setStyleSheet("QPushButton {"
                     "border-style: outset;"
                     "border-width: 0.2px;"
                     "border-color: beige; }");

    w->setLayout(mainFrame);

    w->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::assignColor(){
    //Get button pressed
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());

    //Find X,Y location of button in mainFrame
    int x, y, xs, xy;
    int index = mainFrame->indexOf(pButton);
    mainFrame->getItemPosition(index, &x, &y, &xs, &xy);
    qDebug() << QString::number(x) << " " << QString::number(y);

    //Update rgb value at X,Y in mainGrid
    rgb color;
    color.r = currentColor.red();
    color.g = currentColor.green();
    color.b = currentColor.blue();
    grid->cellColors[x][y] = currentColor;
    //and current animation frame
    animation[currentAnimation].frame[x][y] = color;

    //Set color to current color
    if (pButton) // this is the type we expect
    {
         if(currentColor.isValid()){
             QString qss = QString("background-color: %1").arg(currentColor.name());
             pButton->setStyleSheet(qss);
         }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,
                        tr("Open File"),
                        QDir::homePath(),
                        "Goof Light Editor(*.gle)");

    if(filename.isEmpty()) return;
    else{
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::information(this, tr("Error"), file.errorString());
            return;
        }
        else{
            //Write file *phew*
            for(int i = 0; i < animation.size(); i++){
                file.write(std::to_string(animation[i].time).c_str());
                file.write("\n");
                for(int r = 0; r < grid->getGridRowCount(); r++){
                    for(int c = 0; c < grid->getGridColumnCount(); c++){
                        //Write rgb into file
                        file.write(std::to_string(animation[i].frame[r][c].r).c_str());
                        file.write(" ");
                        file.write(std::to_string(animation[i].frame[r][c].g).c_str());
                        file.write(" ");
                        file.write(std::to_string(animation[i].frame[r][c].b).c_str());
                        file.write(" ");
                    }
                    file.write("\n");
                }
            }
        }
    }

    QMessageBox::information(this,tr("File Name"),filename);

}

void MainWindow::on_actionLoad_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,
                        tr("Load Project"),
                        QDir::homePath(),
                        "All Files (*.*);;Goof Light Editor(*.gle)");
    QMessageBox::information(this,tr("File Name"),filename);

}

void MainWindow::on_actionExport_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,
                        tr("Export Project"),
                        QDir::homePath(),
                        "TAN file (*.tan)");
    QMessageBox::information(this,tr("File Name"),filename);


}

void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox::information(this, "Info", "Hello");
    for(int i = 0; i < animation.size(); i++){
        std::cout << "Time stamp: " << animation[i].time << std::endl;
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                std::cout << animation[i].frame[r][c].r << " " << animation[i].frame[r][c].g << " " << animation[i].frame[r][c].b << " ";
            }
            std::cout << std::endl;
        }
    }
}

void MainWindow::on_AddFrameButton_clicked()
{
    state temp;
    temp.time = animation.size() * 5;
    for(int r = 0; r < grid->getGridRowCount(); r++){
        for(int c = 0; c < grid->getGridColumnCount(); c++){
            rgb tempColor;
            tempColor.r = grid->getCellColor(r,c).red();
            tempColor.g = grid->getCellColor(r,c).green();
            tempColor.b = grid->getCellColor(r,c).blue();
            temp.frame[r][c] = tempColor;
        }
    }

    animation.push_back(temp);
    currentAnimation++;
}



void MainWindow::on_DeleteFrameButton_clicked()
{
    if(animation.size() > 1){
        //Remove last state
        animation.pop_back();
        currentAnimation--;

        //Update mainGrid to current animation state
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){

                QColor color = QColor(animation[currentAnimation].frame[r][c].r,
                                           animation[currentAnimation].frame[r][c].g,
                                           animation[currentAnimation].frame[r][c].b);
                grid->setCellColor(color,r,c);
                QString qss = QString("background-color: %1").arg(color.name());
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    currentColor = QColorDialog::getColor(Qt::white, this);
}
