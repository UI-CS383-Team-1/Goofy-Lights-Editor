#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include <string>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QSpacerItem>
#include <QtCore>
#include <QRect>
#include <QScrollArea>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SpeedDropdown->setCurrentIndex(3);

    /* creating grid size with default 10*20 */
    grid = new Grid();

    //Clear main grid
    Grid *initFrame = new Grid(QColor(187,187,187));

    //Add initial state to animation
    initFrame->setTime(0);
    animation.push_back(*initFrame);

    //Set current color to grey
    currentColor.setRgb(187, 187, 187);

    //Build animation scroll area
    animationFrame = new QWidget;
    QScrollArea *scroll = ui->animationArea;
    animationLayout = new QHBoxLayout(animationFrame);
    scroll->setWidget(animationFrame);
    scroll->setWidgetResizable(true);

    QWidget *w = new QWidget;
    QGridLayout *frame = new QGridLayout;
    w->setObjectName(QString::number(0));
    animationLayout->addWidget(w);
    createGrid(w, frame, false);

    //I added a ridculously high number in here to get the small version of the grid looking properly.
    animationLayout->addSpacing(10000);

    mainFrame = new QGridLayout;
    createGrid(ui->GridWidget, mainFrame, true);

    //Set up the color widget here.
    colorDialog = new QColorDialog();
    colorDialog->setWindowFlags(Qt::Widget);
    colorDialog->setOptions( QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons );
    ui->ColorWidget->addWidget(colorDialog);
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
            else{
                tmp->setMaximumSize(10,10);
                connect(tmp, SIGNAL(clicked()), this, SLOT(setAnimation()));
            }

            frame->addWidget(tmp,i,j,1,1);
        }
    }

    w->setStyleSheet("QPushButton {background-color: #bbbbbb;"
                     "border-style: outset;"
                     "border-width: 1px;"
                     "border-color: beige; }");

    w->setLayout(frame);
    w->show();
}

void MainWindow::assignColor(){

    currentColor = colorDialog->currentColor();
    //Get button pressed
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());

    //Find X,Y location of button in mainFrame
    int x, y, xs, xy;
    int index = mainFrame->indexOf(pButton);
    mainFrame->getItemPosition(index, &x, &y, &xs, &xy);
    qDebug() << QString::number(x) << " " << QString::number(y);

    //Update rgb value at X,Y in grid->cellColors
    QColor *color = new QColor(currentColor.red(), currentColor.green(), currentColor.blue());

    grid->cellColors[x][y] = currentColor;

    //and current animation frame
    Grid temp = animation[currentAnimation];
    temp.setCellColor(*color, x, y);


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

void MainWindow::on_AddFrameButton_clicked()
{

    //Remove the spacer to allow for addition of frames
    if(animation.size() < 15){
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

    //Add the new state to the back of the animation
    //TO DO: Add at any point
    animation.insert(animation.begin() + currentAnimation + 1, temp);



    //Add grid to animation
    QWidget *w = new QWidget;
    QGridLayout *frame = new QGridLayout;
    w->setObjectName(QString::number(currentAnimation+1));
    qDebug() << QString("Adding widget at: ") << QString::number(currentAnimation+1);
    animationLayout->insertWidget(currentAnimation + 1, w);
    //animationLayout->addWidget(w);
    createGrid(w, frame, false);

    //Copy 2d array to frame in animationArea
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(temp.getCellColor(r, c) == QColor(0,0,0)){
                color->setRgb(187, 187, 187);
            }
            else{
                *color = temp.getCellColor(r, c);
            }
            QString qss = QString("background-color: %1").arg(color->name());
            frame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
        }
    }
    currentAnimation++;

    //If the animation is still not enough to fill, add spacer
    if(animation.size() >= 2 && animation.size() < 15){
        animationLayout->addSpacing(10000);
    }

    unsigned int i = 0;
    for(; i < animation.size(); i++){
        QWidget *clicked = animationLayout->itemAt(i)->widget();
        clicked->setObjectName(QString::number(i));
    }

    //Update animation area
    ui->animationArea->update();
}



void MainWindow::on_DeleteFrameButton_clicked()
{

    //Remove the spacer to allow for deletion of frames
    if(animation.size() >= 2 && animation.size() < 15){
        QWidget *tmp = animationLayout->itemAt(animation.size())->widget();
        animationLayout->removeWidget(animationLayout->itemAt(animation.size())->widget());
        delete tmp;
    }

    //Delete frame if more than one. Else, clear current frame.
    if(animation.size() > 1){

        //Remove last state
        //animation.pop_back();
        animation.erase(animation.begin() + currentAnimation);
        currentAnimation--;
        if(currentAnimation < 0) currentAnimation = 0;

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

        //Remove widget from layout and delete widget
        QWidget *tmp = animationLayout->itemAt(currentAnimation+1)->widget();
        animationLayout->removeWidget(animationLayout->itemAt(currentAnimation+1)->widget());
        delete tmp;

        //Added to handle the sizing of the animation
        if(animation.size() < 15){
            animationLayout->addSpacing(10000);
        }
    }
    else{
        //Clear current frame
        Grid initFrame = animation[0];
        QWidget *w = animationLayout->itemAt(0)->widget();
        QLayout *layout = w->layout();


        initFrame.setAllCellColor(QColor(0, 0, 0));
        grid->setAllCellColor(QColor(0, 0, 0));

        //Clear 2d array and QGridLayout of color
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){

                QWidget *button = layout->itemAt(r * grid->getGridColumnCount() + c)->widget();

                QColor *color = new QColor(187, 187, 187);
                QString qss = QString("background-color: %1").arg(color->name());
              
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
                button->setStyleSheet(qss);
            }
        }

    }


    //Reset numbers for animation selection
    unsigned int i = 0;
    for(; i < animation.size(); i++){
        QWidget *clicked = animationLayout->itemAt(i)->widget();
        clicked->setObjectName(QString::number(i));
    }
}

void MainWindow::on_QuitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_ColorChangeButton_clicked()
{
    currentColor = QColorDialog::getColor(Qt::white, this);
}

void MainWindow::on_PrintButton_clicked()
{
    //Test button for animation saving
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

void MainWindow::mousePressEvent(QMouseEvent *event){

    if(!ui->animationArea->underMouse() || event->button() != Qt::LeftButton) return;

    //Locate which widget is being pressed
    QWidget *clicked;
    unsigned int i = 0;
    for(; i < animation.size(); i++){
        clicked = animationLayout->itemAt(i)->widget();
        if(clicked->underMouse()){
            qDebug() << QString::number(i) << QString(" was clicked");
            break;
        }
    }

    //Set grid and animation to selected frame
    currentAnimation = i;
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(animation[i].getCellColor(r, c) == QColor(0,0,0)){
                color->setRgb(187, 187, 187);
            }
            else{
                *color = animation[i].getCellColor(r, c);
            }
            grid->cellColors[r][c] = *color;
            QString qss = QString("background-color: %1").arg(color->name());
            mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
        }
    }
}

void MainWindow::setAnimation(){
    //get object name that has animation number
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    qDebug() << QString("SET ANIMATION: ");
    QObject *tmp = pButton->parent();
    qDebug() << tmp->objectName();

    //Set mainframe to animation frame
    int clicked = tmp->objectName().toInt();
    currentAnimation = clicked;
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(animation[clicked].getCellColor(r, c) == QColor(0,0,0)){
                color->setRgb(187, 187, 187);
            }
            else{
                *color = animation[clicked].getCellColor(r, c);
            }
            grid->cellColors[r][c] = *color;
            QString qss = QString("background-color: %1").arg(color->name());
            mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
        }
    }
}

void MainWindow::on_PlayButton_clicked()
{
   //Start the timer
   time2.start();
   timer = new QTimer(this);
   showTime();
   connect(timer, SIGNAL(timeout ()), this, SLOT(showTime()));
   timer->start(100 * test);

   unsigned long int co ;
      int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    if (isPlaying)                              // Switch between Play and Pause
    {
        isPlaying = false;
        co = animation.size();
        //timer->stop();
        updateFrame();
        return;
    }
    else
    {
        isPlaying = true;

//Play through all frames
        for ( co = 0; co < animation.size(); co++){       //prop. probably here-ish

            for(int r = 0; r < height; r++){
                for(int c = 0; c < width; c++){
                   grid->cellColors[r][c] = animation[co].getCellColor(r, c);

                    QColor *color = new QColor();
                    Grid tempGrid = animation[co];

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

            countDown = test * 100; // The speed of the count down is equal to the playback speed times 1/10 of a second
            delay(countDown);

        }
    }
    timer->stop();
    isPlaying = false;
}

//Delay the playback
void MainWindow::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

//Update frames. Used in the shift dirction functions
void MainWindow::updateFrame()
{
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

void MainWindow::on_StopButton_clicked()
{
    isPlaying = false;
    updateFrame();
}

void MainWindow::on_UpButton_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
               if (r+1 < height)
                    grid->cellColors[r][c] = grid->cellColors[r+1][c];
               else
                    grid->cellColors[r][c].setRgb(187,187,187);
           }
       }
       on_AddFrameButton_clicked();

       updateFrame();
}

void MainWindow::on_LeftButton_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

       for (int r = 0; r < height; r++) {
           for (int c = 0; c < width; c++) {
               if (c+1 < width)
                    grid->cellColors[r][c] = grid->cellColors[r][c+1];
               else
                    grid->cellColors[r][c].setRgb(187,187,187);
           }
       }
     on_AddFrameButton_clicked();
     updateFrame();
}

void MainWindow::on_RightButton_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

       for (int r = height - 1; r >= 0; r--) {
           for (int c = width - 1; c >= 0; c--) {
               if (c-1 < 0)
                   grid->cellColors[r][c].setRgb(187,187,187);
               else
                   grid->cellColors[r][c] = grid->cellColors[r][c-1];
           }
       }
        on_AddFrameButton_clicked();
        updateFrame();
}

void MainWindow::on_DownButton_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
               if (r-1 < 0)
                   grid->cellColors[r][c].setRgb(187,187,187);
               else
                   grid->cellColors[r][c] = grid->cellColors[r-1][c];
           }
       }
        on_AddFrameButton_clicked();
        updateFrame();
}

void MainWindow::on_DownLeft_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
               if (r-1 < 0)
                   grid->cellColors[r][c].setRgb(187,187,187);
               else
                   grid->cellColors[r][c] = grid->cellColors[r-1][c];
           }
       }

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (c+1 < width)
                 grid->cellColors[r][c] = grid->cellColors[r][c+1];
            else
                 grid->cellColors[r][c].setRgb(187,187,187);
        }
    }
       on_AddFrameButton_clicked();

       updateFrame();
}

void MainWindow::on_UpLeft_clicked()
{

    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();


    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
               if (r+1 < height)
                    grid->cellColors[r][c] = grid->cellColors[r+1][c];
               else
                    grid->cellColors[r][c].setRgb(187,187,187);
           }
       }

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (c+1 < width)
                 grid->cellColors[r][c] = grid->cellColors[r][c+1];
            else
                 grid->cellColors[r][c].setRgb(187,187,187);
        }
    }
       on_AddFrameButton_clicked();

       updateFrame();
}

void MainWindow::on_UpRight_clicked()
{
 int width = grid->getGridColumnCount();
 int height = grid->getGridRowCount();

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
               if (r+1 < height)
                    grid->cellColors[r][c] = grid->cellColors[r+1][c];
               else
                    grid->cellColors[r][c].setRgb(187,187,187);
           }
       }

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
            if (c-1 < 0)
                grid->cellColors[r][c].setRgb(187,187,187);
            else
                grid->cellColors[r][c] = grid->cellColors[r][c-1];
        }
    }
     on_AddFrameButton_clicked();
     updateFrame();
}

//Read and set the speed of playback
void MainWindow::on_SpeedDropdown_currentIndexChanged(int)
{
    bool ok;
    QString aString = ui->SpeedDropdown->currentText();
    float num = aString.toFloat(&ok);
    test = num ;
}

void MainWindow::on_DownRight_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
               if (r-1 < 0)
                   grid->cellColors[r][c].setRgb(187,187,187);
               else
                   grid->cellColors[r][c] = grid->cellColors[r-1][c];
           }
       }

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
            if (c-1 < 0)
                grid->cellColors[r][c].setRgb(187,187,187);
            else
                grid->cellColors[r][c] = grid->cellColors[r][c-1];
        }
    }
     on_AddFrameButton_clicked();
     updateFrame();
}

void MainWindow::showTime(){

            int secs = time2.elapsed() / 1000;
            int mins = (secs / 60) % 60;
            int hours = (secs / 3600);
            secs = secs % 60;
            ui->Time_label->setText(QString("%1:%2:%3")
            .arg(hours, 2, 10, QLatin1Char('0'))
            .arg(mins, 2, 10, QLatin1Char('0'))
            .arg(secs, 2, 10, QLatin1Char('0')) );

}

