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
    Grid *initFrame = new Grid(QColor(187,187,187));

    grid->setAllCellColor(QColor(187,187,187));

    //Add initial state to animation
    initFrame->setTime(0);
    animation.push_back(*initFrame);

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

            connect(tmp, SIGNAL(clicked()), this, SLOT(assignColor()));
            //connect(this, SIGNAL(clicked()), this, SLOT(assignColor(i, j)));

            mainFrame->addWidget(tmp,i,j,1,1);
        }
    }

    /*setting the color of the Buttons in the grid as gray*/
    w->setStyleSheet("QPushButton {background-color: gray;"
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

    QColor *color = new QColor(currentColor.red(), currentColor.green(), currentColor.blue());
    grid->cellColors[x][y] = currentColor;
    //and current animation frame
    Grid temp = animation[currentAnimation];
    temp.setCellColor(*color, x, y);

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
            for(unsigned int i = 0; i < animation.size(); i++){
                file.write(std::to_string(animation[i].getTime()).c_str());
                file.write("\n");
                for(int r = 0; r < grid->getGridRowCount(); r++){
                    for(int c = 0; c < grid->getGridColumnCount(); c++){
                        //Write rgb into file
                        QColor color = animation[i].getCellColor(r,c);

                        file.write(std::to_string(color.red()).c_str());
                        file.write(" ");

                        file.write(std::to_string(color.green()).c_str());
                        file.write(" ");

                        file.write(std::to_string(color.blue()).c_str());
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
    for(unsigned int i = 0; i < animation.size(); i++){
        std::cout << "Time stamp: " << animation[i].getTime() << std::endl;
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                QColor color = animation[i].getCellColor(r,c);
                std::cout << color.red() << " " << color.green() << " " << color.blue() << " ";
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
    Grid temp;
    temp.setTime(animation.size() * 5);

    for(int r = 0; r < grid->getGridRowCount(); r++){
        for(int c = 0; c < grid->getGridColumnCount(); c++){
            QColor *color = new QColor(grid->getCellColor(r,c).red(),
                                       grid->getCellColor(r,c).green(),
                                       grid->getCellColor(r,c).blue());
            temp.setCellColor(*color, r, c);
        }
    }

    animation.push_back(temp);

            frame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
        }
    }
            QString qss = QString("background-color: %1").arg(color->name());
            }
            else{
                *color = temp.getCellColor(r, c);
    animationLayout->addWidget(w);
    createGrid(w, frame, false);

    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){

            //Displays black as gray.
            if(temp.getCellColor(r, c) == QColor(0,0,0)){
            }
                color->setRgb(187, 187, 187);
            QColor *color = new QColor();
    //Copy 2d array to frame in animationArea

    //Add grid to animation
    QWidget *w = new QWidget;
    QGridLayout *frame = new QGridLayout;
    currentAnimation++;
}



void MainWindow::on_DeleteFrameButton_clicked()
{
    if(animation.size() > 1){
        //Remove last state
        animation.pop_back();
        currentAnimation--;


        //Update grid->cellColors to current animation state
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                grid->cellColors[r][c] = animation[currentAnimation].getCellColor(r, c);

                QColor *color = new QColor();
                Grid tempGrid = animation[currentAnimation];

                //Displays black as gray.
                if(tempGrid.getCellColor(r, c) == QColor(0,0,0)){
                    color->setRgb(187, 187, 187);
                }
                else{
                    *color = tempGrid.getCellColor(r, c);
                }
                QString qss = QString("background-color: %1").arg(color->name());
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }
    }
    ui->animationArea->horizontalScrollBar()->setValue(ui->animationArea->horizontalScrollBar()->maximum());
    //Set scrollbar to the end of the animation area
    }


            }
        }
                button->setStyleSheet(qss);
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
              
                QString qss = QString("background-color: %1").arg(color->name());
                QColor *color = new QColor(187, 187, 187);

                QWidget *button = layout->itemAt(r * grid->getGridColumnCount() + c)->widget();

            for(int c = 0; c < grid->getGridColumnCount(); c++){
        for(int r = 0; r < grid->getGridRowCount(); r++){
        //Clear 2d array and QGridLayout of color

        grid->setAllCellColor(QColor(0, 0, 0));
        initFrame.setAllCellColor(QColor(0, 0, 0));

        QLayout *layout = w->layout();

        QWidget *w = animationLayout->itemAt(0)->widget();
        Grid initFrame = animation[0];
        //Clear current frame
    else{
}

void MainWindow::on_pushButton_8_clicked()
{
    currentColor = QColorDialog::getColor(Qt::white, this);
}
