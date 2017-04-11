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
#include <QScrollBar>
#include <QSpacerItem>
#include <QRect>

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

    //Build animation scroll area
    animationFrame = new QWidget;
    QScrollArea *scroll = ui->animationArea;
    animationLayout = new QHBoxLayout(animationFrame);
    scroll->setWidget(animationFrame);
    scroll->setWidgetResizable(true);

    QWidget *w = new QWidget;
    QGridLayout *frame = new QGridLayout;
    animationLayout->addWidget(w);
    createGrid(w, frame, false);

    animationLayout->addSpacing(425);

    mainFrame = new QGridLayout;
    createGrid(ui->GridWidget, mainFrame, true);

    ui->animationArea->horizontalScrollBar()->setValue(ui->animationArea->horizontalScrollBar()->value() + 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid(QWidget *w, QGridLayout *frame, bool active){
    //Creates grid in widget w

    //Set sizing for buttons in grid
    QSizePolicy *policy = new QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    policy->setHeightForWidth(true);


    //Remove spacing between buttons
    frame->setHorizontalSpacing(0);
    frame->setVerticalSpacing(0);
  
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

            if(active)
                connect(tmp, SIGNAL(clicked()), this, SLOT(assignColor()));
            else
                tmp->setMaximumSize(10,10);

            frame->addWidget(tmp,i,j,1,1);
        }
    }

    w->setStyleSheet("QPushButton {background-color: #bbbbbb;"
                     "border-style: outset;"
                     "border-width: 0.2px;"
                     "border-color: beige; }");

    w->setLayout(frame);
    w->show();
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


    QWidget *w = animationLayout->itemAt(currentAnimation)->widget();
    QLayout *layout = w->layout();

    QWidget *button = layout->itemAt(x * 20 + y)->widget();

    //Set color to current color
    if (pButton) // this is the type we expect
    {
         if(currentColor.isValid()){
             QString qss = QString("background-color: %1").arg(currentColor.name());
             pButton->setStyleSheet(qss);
             button->setStyleSheet(qss);

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
            for(unsigned int i = 0; i < animation.size(); i++){
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
    //Test button for animation saving
    QMessageBox::information(this, "Info", "Hello");
    for(unsigned int i = 0; i < animation.size(); i++){
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

    //Remove the spacer to allow for addition of frames
    if(animation.size() <= 2){
        QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
        animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());
        delete tmp;
    }

    //Create new state to add to the animation
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

    //Add the new state to the back of the animation
    //TO DO: Add at any point
    animation.push_back(temp);

    //Add grid to animation
    QWidget *w = new QWidget;
    QGridLayout *frame = new QGridLayout;
    animationLayout->addWidget(w);
    createGrid(w, frame, false);

    //Copy 2d array to frame in animationArea
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(temp.frame[r][c].r + temp.frame[r][c].g + temp.frame[r][c].b == 0){
                color->setRgb(187, 187, 187);
            }
            else{
                color->setRgb(temp.frame[r][c].r, temp.frame[r][c].g, temp.frame[r][c].b);
            }
            QString qss = QString("background-color: %1").arg(color->name());
            frame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
        }
    }

    currentAnimation++;

    //If the animation is still not enough to fill, add spacer
    if(animation.size() == 2){
        animationLayout->addSpacing(200);
    }

    //Update animation area and set scrollbar to end
    //TO DO: Not currently working. Looking into it.
    ui->animationArea->update();
    ui->animationArea->horizontalScrollBar()->setValue(ui->animationArea->horizontalScrollBar()->maximum());
}



void MainWindow::on_DeleteFrameButton_clicked()
{

    //Remove the spacer to allow for deletion of frames
    if(animation.size() == 2){
        QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
        animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());
        delete tmp;
    }

    //Delete frame if more than one. Else, clear current frame.
    if(animation.size() > 1){

        //Remove last state
        animation.pop_back();
        currentAnimation--;


        //Update mainGrid to current animation state
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                mainGrid[r][c] = animation[currentAnimation].frame[r][c];
                QColor *color = new QColor();
                state tmp = animation[currentAnimation];
                if(tmp.frame[r][c].r + tmp.frame[r][c].g + tmp.frame[r][c].b == 0){
                    color->setRgb(187, 187, 187);
                }
                else{
                    color->setRgb(tmp.frame[r][c].r, tmp.frame[r][c].g, tmp.frame[r][c].b);
                }
                QString qss = QString("background-color: %1").arg(color->name());
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }

        //Remove widget from layout and delete widget
        QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
        animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());
        delete tmp;

        //Added to handle the sizing of the animation
        if(animation.size() == 2){
            animationLayout->addSpacing(200);
        }
        if(animation.size() == 1){
            animationLayout->addSpacing(425);
        }
    }
    else{
        //Clear current frame
        state *initFrame = &animation[0];
        QWidget *w = animationLayout->itemAt(0)->widget();
        QLayout *layout = w->layout();

        rgb blank;
        blank.r = 0;
        blank.g = 0;
        blank.b = 0;

        //Clear 2d array and QGridLayout of color
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                mainGrid[r][c] = blank;

                QWidget *button = layout->itemAt(r * grid->getGridColumnCount() + c)->widget();

                initFrame->frame[r][c] = blank;
                QColor *color = new QColor(187, 187, 187);
                QString qss = QString("background-color: %1").arg(color->name());
              
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
                button->setStyleSheet(qss);
            }
        }

    }

    //Set scrollbar to the end of the animation area
    ui->animationArea->horizontalScrollBar()->setValue(ui->animationArea->horizontalScrollBar()->maximum());
}

void MainWindow::on_pushButton_8_clicked()
{
    //Change color in QColorDialog
    currentColor = QColorDialog::getColor(Qt::white, this);
}

void MainWindow::on_Scrollbar_clicked()
{
    //Test button for scrollbar movement
    ui->animationArea->horizontalScrollBar()->setValue(ui->animationArea->horizontalScrollBar()->maximum());
}
