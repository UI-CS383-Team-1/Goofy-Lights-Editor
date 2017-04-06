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
#include <QSpacerItem>
#include <QtCore>
#include <QRect>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(3);

    //Clear main grid
    state initFrame;
    rgb blank;
    blank.r = 0;
    blank.g = 0;
    blank.b = 0;
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            mainGrid[r][c] = blank;
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
    mainFrame->setHorizontalSpacing(0);
    mainFrame->setVerticalSpacing(0);

    //Build animation scroll area
    animationFrame = new QWidget;
    QScrollArea *scroll = ui->animationArea;
    animationLayout = new QHBoxLayout(animationFrame);
    scroll->setWidget(animationFrame);
    scroll->setWidgetResizable(true);

    int i = 0;
    while(i<1){
        //Code in here decides what widgit is added to the scroll.
        //This should be set to the animation vector.
        QPushButton *tmp = new QPushButton;
        animationLayout->addWidget(tmp);
        i++;
     }

    /* creating grid size as 10*20 */
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            QPushButton *tmp = new QPushButton;

            tmp->setSizePolicy(*policy);

            connect(tmp, SIGNAL(clicked()), this, SLOT(assignColor()));
            //connect(this, SIGNAL(clicked()), this, SLOT(assignColor(i, j)));

            mainFrame->addWidget(tmp,i,j,1,1);
        }
    }

    /*setting the color of the Buttons in the grid as gray*/
    w->setStyleSheet("QPushButton {background-color: #bbbbbb;"
                     "border-style: outset;"
                     "border-width: 1px;"
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
    mainGrid[x][y] = color;
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
                for(int r = 0; r < 10; r++){
                    for(int c = 0; c < 20; c++){
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
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 20; c++){
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
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            temp.frame[r][c] = mainGrid[r][c];
        }
    }

    animation.push_back(temp);
    QPushButton *button = new QPushButton(QString::number(currentAnimation));
    animationLayout->addWidget(button);
    currentAnimation++;
}



void MainWindow::on_DeleteFrameButton_clicked()
{
    if(animation.size() > 1){
        //Remove last state
        animation.pop_back();
        currentAnimation--;

        //Update mainGrid to current animation state
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 20; c++){
                mainGrid[r][c] = animation[currentAnimation].frame[r][c];
                QColor *color = new QColor(animation[currentAnimation].frame[r][c].r, animation[currentAnimation].frame[r][c].g, animation[currentAnimation].frame[r][c].b);
                QString qss = QString("background-color: %1").arg(color->name());
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }
        QWidget *tmp = animationLayout->itemAt(1)->widget();
        animationLayout->removeWidget(animationLayout->itemAt(1)->widget());
        delete tmp;
        animationFrame->update();
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    currentColor = QColorDialog::getColor(Qt::white, this);
}
