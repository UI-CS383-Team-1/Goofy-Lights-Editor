#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytimer.h"
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
#include <QPainter>
#include <QVector>
#include <QColor>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*

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

    // creating grid size as 10*20
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

    //setting the color of the Buttons in the grid as gray
    w->setStyleSheet("QPushButton {background-color: #bbbbbb;"
                     "border-style: outset;"
                     "border-width: 1px;"
                     "border-color: beige; }");

    w->setLayout(mainFrame);

    w->show();

    */
///*

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

      //Build animation scroll area
      animationFrame = new QWidget;
      QScrollArea *scroll = ui->animationArea;
      animationLayout = new QHBoxLayout(animationFrame);
      scroll->setWidget(animationFrame);
      scroll->setWidgetResizable(true);




      int i = 0;
      while(i<0){
          //Code in here decides what widgit is added to the scroll.
          //This should be set to the animation vector.
          QPushButton *tmp = new QPushButton;
          animationLayout->addWidget(tmp);
          i++;
       }


      QWidget *w = new QWidget;
      QGridLayout *frame = new QGridLayout;
      animationLayout->addWidget(w);
      createGrid(w, frame, false);

      animationLayout->addSpacing(460);

      mainFrame = new QGridLayout;
      createGrid(ui->GridWidget, mainFrame, true);

//*/

      /*

    ui->setupUi(this);
       ui->comboBox->setCurrentIndex(3);

       // creating grid size with default 10*20
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

       //setting the color of the Buttons in the grid as gray
       w->setStyleSheet("QPushButton {"
                        "border-style: outset;"
                        "border-width: 0.2px;"
                        "border-color: beige; }");

       w->setLayout(mainFrame);

       w->show();
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid(QWidget *w, QGridLayout *frame, bool active){
    //Creates grid in widget w

    //Build grid
    //if(frame == NULL)


    QSizePolicy *policy = new QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    policy->setHeightForWidth(true);

    frame->setHorizontalSpacing(0);
    frame->setVerticalSpacing(0);

    /* creating grid size as 10*20 */
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            QPushButton *tmp = new QPushButton;

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
                     "border-width: 1px;"
                     "border-color: beige; }");

    /*if(colors != NULL){
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 20; c++){
                QColor *color = new QColor(colors[r][c].r, colors[r][c].g, colors[r][c].b);
                QString qss = QString("background-color: %1").arg(color->name());
                frame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }
    }*/

    w->setLayout(frame);
    w->show();
}

void MainWindow::assignColor(){
  ///*  //Get button pressed
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


//}
//*/
/*
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
      */
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
   // /*
    if(animation.size() <= 2){
           QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
           animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());

           delete tmp;
       }
 //connect(ui->AddFrameButton,SIGNAL(clicked()),ui->animationArea, SLOT(update()));

       state temp;
       temp.time = animation.size() * 5;
       for(int r = 0; r < 10; r++){
           for(int c = 0; c < 20; c++){
               temp.frame[r][c] = mainGrid[r][c];
           }
       }

       animation.push_back(temp);

       //Add grid to animation
       QWidget *w = new QWidget;
       QGridLayout *frame = new QGridLayout;
       animationLayout->addWidget(w);
       createGrid(w, frame, false);

       for(int r = 0; r < 10; r++){
           for(int c = 0; c < 20; c++){
               QColor *color = new QColor();
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

       //QPushButton *button = new QPushButton(QString::number(currentAnimation));

       currentAnimation++;

       if(animation.size() == 2){
           animationLayout->addSpacing(230);
       }
//*/

/*
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
      //  */
}

void MainWindow::on_DeleteFrameButton_clicked()
{
///*
    std::cout << "Animation size before deletion: " << animation.size() << " " << currentAnimation << std::endl;
        if(animation.size() > 1){
            //Remove last state

            animation.pop_back();
            currentAnimation--;


            //Update mainGrid to current animation state
            for(int r = 0; r < 10; r++){
                for(int c = 0; c < 20; c++){
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

            QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
            animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());
            delete tmp;
            if(animation.size() == 2){
                animationLayout->addSpacing(230);
            }
            if(animation.size() == 1){
                animationLayout->addSpacing(460);
            }
        }
        else{
            state *initFrame = &animation[0];
            QWidget *w = animationLayout->itemAt(0)->widget();
            QLayout *layout = w->layout();
            rgb blank;
            blank.r = 0;
            blank.g = 0;
            blank.b = 0;
            for(int r = 0; r < 10; r++){
                for(int c = 0; c < 20; c++){
                    mainGrid[r][c] = blank;

                    QWidget *button = layout->itemAt(r * 20 + c)->widget();

                    initFrame->frame[r][c] = blank;
                    QColor *color = new QColor(187, 187, 187);
                    QString qss = QString("background-color: %1").arg(color->name());
                    mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
                    button->setStyleSheet(qss);
                }
            }
        }
        std::cout << "Animation size after deletion: " << animation.size() << " " << currentAnimation << std::endl;
//*/
/*
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
       */
}

void MainWindow::on_pushButton_8_clicked()
{
    currentColor = QColorDialog::getColor(Qt::white, this);
}

void MainWindow::on_pushButton_clicked()
{

        state temp;
        temp.time = animation.size() * 5;

        for (int i = animation.size(); i >= 0; i--){
         for(int r = 0; r < 10; r++){
             for(int c = 0; c < 20; c++){
                 temp.frame[r][c] = animation[i].frame[r][c];
             }
         }
           playB.push_back(temp);
         }

    int track = 0;
    for ( ; track <= currentAnimation; track++)
        playBack();
  isPlaying = true;
}

void MainWindow::playBack(){

 QColor *color = new QColor();
    /*

    QColor *color = new QColor();

        state temp;
        temp.time = animation.size() * 5;

        for (int i = animation.size(); i >= 0; i--){
         for(int r = 0; r < 10; r++){
             for(int c = 0; c < 20; c++){
                 temp.frame[r][c] = animation[i].frame[r][c];
             }
         }
           playB.push_back(temp);
         }

*/


        if (isPlaying)                              // Switch between Play and Pause
           {
               isPlaying = false;
            }
        else
           {
           // isPlaying = true;

          //  for (int cou = 0; cou < (currentAnimation + 1); cou++){

                for(int r = 0; r < 10; r++){
                    for(int c = 0; c < 20; c++){
                        mainGrid[r][c] = playB[count].frame[r][c];
                        state tmp = playB[count];
                        //QColor *color = new QColor();

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

                if(playB.size() == 2){
                   animationLayout->addSpacing(230);
               }
               if(playB.size() == 1){
                   animationLayout->addSpacing(460);
               }
                       playB.pop_back();
                       count++;

                    //   on_pushButton_clicked();
              //     }
        }

        /*
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 20; c++){
                mainGrid[r][c] = playB[count].frame[r][c];
                state tmp = playB[count];
               // QColor *color = new QColor();
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
//*/

}

void MainWindow::on_pushButton_7_clicked()
{

     int width = 20;
     int height = 10;

        for (int r = height - 1; r >= 0; r--) {
            for (int c = width - 1; c >= 0; c--) {
                if (c-1 < 0)
                    mainGrid[r][c].color2;
                else
                    mainGrid[r][c] = mainGrid[r][c-1];
            }
        }
         on_AddFrameButton_clicked();
         updateFrame();
}

void MainWindow::on_pushButton_6_clicked()
{
    int width = 20;
    int height = 10;


       for (int r = 0; r < height; r++) {
           for (int c = 0; c < width; c++) {
               if (c+1 < width)
                    mainGrid[r][c] = mainGrid[r][c+1];
               else
                    mainGrid[r][c].color2;
           }
       }
     on_AddFrameButton_clicked();
     updateFrame();

}

void MainWindow::on_pushButton_5_clicked()
{
    int width = 20;
    int height = 10;

       for (int r = height - 1; r >= 0; r--) {
           for (int c = width - 1; c >= 0; c--) {
               if (r-1 < 0)
                   mainGrid[r][c].color2;
               else
                   mainGrid[r][c] = mainGrid[r-1][c];
           }
       }
        on_AddFrameButton_clicked();
        updateFrame();

}

void MainWindow::on_pushButton_4_clicked()
{
    int width = 20;
    int height = 10;

       for (int r = 0; r < height; r++) {
           for (int c = 0; c < width; c++) {
               if (r+1 < height)
                    mainGrid[r][c] = mainGrid[r+1][c];
               else
                    mainGrid[r][c].color2;

           }
       }
       on_AddFrameButton_clicked();

       updateFrame();
}

void MainWindow::on_pushButton_2_clicked()
{
isPlaying = false;
updateFrame();
}

void MainWindow::updateFrame()
{

    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
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
}
