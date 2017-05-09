#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include <string>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QRegularExpression>
#include <QSpacerItem>
#include <QtCore>
#include <QRect>
#include <QScrollArea>
#include <QSpacerItem>
#include <QDoubleSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SpeedDropdown->setCurrentIndex(3);


    timer = new QTimer(this);

    /* creating grid size with default 10*20 */
    grid = new Grid();

    //Clear main grid
    Grid *initFrame = new Grid(QColor(0,0,0));//(187,187,187));

    //Add initial state to animation
    initFrame->setTime(0);
    animation.push_back(*initFrame);

    //Set current color to grey
   // currentColor.setRgb(187, 187, 187);
     currentColor.setRgb(0,0,0);

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

    QWidget *button = layout->itemAt(x * grid->getGridColumnCount() + y)->widget();

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
      exit(EXIT_SUCCESS);//EXIT_FAILURE);
    //QCoreApplication::quit();
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
            file.write(std::to_string(animation.size()).c_str());
            file.write("\n");
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


//Currently CRASHES after trying to edit the animation AFTER LOADING.
//Need to make the window update after the load so this doesn't happen.
void MainWindow::on_actionLoad_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,
                        tr("Load Project"),
                        QDir::homePath(),
                        "Goof Light Editor(*.gle);;Tan file(*.tan,*.tan2);;All Files (*.*)");
    QMessageBox::information(this,tr("File Name"),filename);
 
    if(filename.isEmpty()) return;
     else{
         QFile data(filename);
         QTextStream fout(&data);
         if(!data.open(QIODevice::ReadOnly)){
             QMessageBox::information(this, tr("Error"), data.errorString());
             return;
         }
         else{

            if (filename.endsWith("gle"))
            {
                clear_animation();
                animation.clear();
                std::cout << "red" << std::endl;
                QMessageBox::information(this, tr("Extension"), ".gle");
                QString wholeFile(data.readAll());
                //qDebug() << wholeFile;
                QStringList splitFile = wholeFile.split(QRegularExpression("\\s+"));
                int numFrames = splitFile.first().toInt();
                splitFile.removeFirst();
                //Grid tmpGrid(10,20);
                QColor tmpColor;
                for (int i = 0; i < numFrames; i++)
                {
                    Grid tmpGrid(10,20);
                    tmpGrid.setTime(splitFile.first().toInt());
                    splitFile.removeFirst();
                    for(int r = 0; r < tmpGrid.getGridRowCount(); r++)
                    {
                        for(int c = 0; c < tmpGrid.getGridColumnCount(); c++)
                        {
                            std::cout << splitFile.first().toInt() << " ";
                            tmpColor.setRed(splitFile.first().toInt());
                            splitFile.removeFirst();
                            std::cout << splitFile.first().toInt() << " ";
                            tmpColor.setGreen(splitFile.first().toInt());
                            splitFile.removeFirst();
                            std::cout << splitFile.first().toInt() << " ";
                            tmpColor.setBlue(splitFile.first().toInt());
                            splitFile.removeFirst();
                            tmpGrid.setCellColor(tmpColor,r,c);
                        }
                        std::cout << std::endl;
                    }
                    std::cout << animation.size() << std::endl;
                    animation.push_back(tmpGrid);
                }
                update_screen();
            }
            else if (filename.endsWith("tan") || filename.endsWith("tan2"))
            {
                QString tmp;
                tmp = data.readLine();
                if (QString::compare(tmp,"0.4") != 0)
                {
                    QMessageBox::information(this, tr("Extension"), ".tan or .tan2");
                    //data.close();
                    //return;
                }
                QMessageBox::information(this, tr("Success"), "File get!");
                tmp = data.readLine(); //wmv storage
                QString preparse(fout.readAll());
                QStringList splitFile;
                qDebug() << preparse;
                splitFile = preparse.split(QRegularExpression("\\s+"));
                int showFrames = splitFile.first().toInt();
                splitFile.removeFirst();
                int showHeight = splitFile.first().toInt();
                if (showHeight > grid->getGridColumnCount())
                {
                    QMessageBox::information(this, tr("Error"), "File height too large!");
                    data.close();
                    return;
                }
                splitFile.removeFirst();
                //int drawColUpper = (showHeight/2) + ((grid->getGridColumnCount())/2);
                //int drawColLower = ((grid->getGridColumnCount())/2) - (showHeight/2);
                int showWidth = splitFile.first().toInt();
                if (showWidth > grid->getGridRowCount())
                {
                    QMessageBox::information(this, tr("Error"), "File width too large!");
                    data.close();
                    return;
                }
                //int drawRowUpper = (showWidth/2) + ((grid->getGridRowCount())/2);
                //int drawRowLower = ((grid->getGridRowCount())/2) - (showWidth/2);
                splitFile.removeFirst();
                QColor tmpColor;
                for (int framepos = 0; framepos < showFrames; framepos++)
                {
                    Grid tmpGrid(10,20);
                    tmpGrid.setTime(splitFile.first().toInt());
                    splitFile.removeFirst();
                    for(int r = 0; r < tmpGrid.getGridRowCount(); r++)
                    {
                        for(int c = 0; c < tmpGrid.getGridColumnCount(); c++)
                        {
                            if((c < showHeight) && (r < showWidth))
                            {
                                tmpColor.setRed(splitFile.first().toInt());
                                splitFile.removeFirst();
                                tmpColor.setGreen(splitFile.first().toInt());
                                splitFile.removeFirst();
                                tmpColor.setBlue(splitFile.first().toInt());
                                splitFile.removeFirst();
                                tmpGrid.setCellColor(tmpColor,r,c);
                            }
                            else
                            {
                                tmpColor.setRgb(0,0,0);
                                tmpGrid.setCellColor(tmpColor,r,c);
                            }
                        }
                    }
                    animation.push_back(tmpGrid);
                }
                update_screen();
            }

         }
          data.close();
    }
}

void MainWindow::clear_animation(){
    //Clear animation
    while(animation.size() > 1){
        on_DeleteFrameButton_clicked();
    }
    on_DeleteFrameButton_clicked();
}

void MainWindow::update_screen(){

    std::cout << "Red top corner: " << animation[0].getCellColor(0, 0).red() << std::endl;

    //Remove spacer
    qDebug() << animationLayout->count() << " " << animation.size();
    QWidget *tmp = animationLayout->itemAt(1)->widget();
    animationLayout->removeWidget(animationLayout->itemAt(1)->widget());
    delete tmp;

    Grid initFrame = animation[0];
    QWidget *w = animationLayout->itemAt(0)->widget();
    QLayout *layout = w->layout();

    //Clear 2d array and QGridLayout of color
    for(int r = 0; r < grid->getGridRowCount(); r++){
        for(int c = 0; c < grid->getGridColumnCount(); c++){

            QWidget *button = layout->itemAt(r * grid->getGridColumnCount() + c)->widget();

            QColor *color = new QColor(animation[0].getCellColor(r,c).red(),
                                       animation[0].getCellColor(r,c).green(),
                                       animation[0].getCellColor(r,c).blue());
            QString qss = QString("background-color: %1").arg(color->name());

            mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            button->setStyleSheet(qss);
        }
    }

    for(unsigned long int i = 1; i < animation.size(); i++){
        //Remove the spacer to allow for addition of frames
        //Create new state to add to the animation
        Grid temp;
        temp.setTime(animation.size() * 5);

        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                QColor *color = new QColor(animation[i].getCellColor(r,c).red(),
                                           animation[i].getCellColor(r,c).green(),
                                           animation[i].getCellColor(r,c).blue());
                temp.setCellColor(*color, r, c);
            }
        }

        //Add the new state to the back of the animation
        //TO DO: Add at any point
        //animation.insert(animation.begin() + currentAnimation + 1, temp);

        //Add grid to animation
        QWidget *w = new QWidget;
        QGridLayout *frame = new QGridLayout;
        w->setObjectName(QString::number(currentAnimation+1));
        qDebug() << QString("Adding widget at: ") << QString::number(currentAnimation+1);
        animationLayout->insertWidget(currentAnimation + 1, w);
        //animationLayout->addWidget(w);
        createGrid(w, frame, false);

        //Copy 2d array to frame in animationArea
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                QColor *color = new QColor();

                //Displays black as gray.
                if(temp.getCellColor(r, c) == QColor(0,0,0)){
                    //color->setRgb(187, 187, 187);
                    color->setRgb(0,0,0);
                }
                else{
                    *color = temp.getCellColor(r, c);
                }
                QString qss = QString("background-color: %1").arg(color->name());
                frame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }
        currentAnimation++;


    }

    //If the animation is still not enough to fill, add spacer
    animationLayout->addSpacing(10000);

    //Update animation area
    ui->animationArea->update();
    unsigned int j = 0;
    for(; j < animation.size() - 1; j++){
        qDebug() << j << " " << animationLayout->count() << " " << animation.size();
        QWidget *clicked = animationLayout->itemAt(j)->widget();
        clicked->setObjectName(QString::number(j));
    }
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
    for(int r = 0; r < grid->getGridRowCount(); r++){
        for(int c = 0; c < grid->getGridColumnCount(); c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(temp.getCellColor(r, c) == QColor(0,0,0)){
                //color->setRgb(187, 187, 187);
                color->setRgb(0,0,0);
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
                    //color->setRgb(187, 187, 187);
                    color->setRgb(0,0,0);
                }
                else{
                    *color = tempGrid.getCellColor(r, c);
                }
                QString qss = QString("background-color: %1").arg(color->name());
                mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
            }
        }

        //Remove widget from layout and delete widget
        int frame_to_remove = currentAnimation + 1;
        if(currentAnimation == 0) frame_to_remove--;
        QWidget *tmp = animationLayout->itemAt(frame_to_remove)->widget();
        animationLayout->removeWidget(animationLayout->itemAt(frame_to_remove)->widget());
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

                QColor *color = new QColor(0,0,0);//187, 187, 187);
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
      exit(EXIT_SUCCESS);//EXIT_FAILURE);
}

void MainWindow::on_PrintButton_clicked()
{
    for(unsigned long int i = 0; i < animation.size(); i++){
        for(int r = 0; r < grid->getGridRowCount(); r++){
            for(int c = 0; c < grid->getGridColumnCount(); c++){
                QColor color = animation[i].getCellColor(r, c);
                std::cout << color.red() << " " << color.green() << " " << color.blue() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
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

    if(i == animation.size()) return;

    //Set grid and animation to selected frame
    currentAnimation = i;
    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 20; c++){
            QColor *color = new QColor();

            //Displays black as gray.
            if(animation[i].getCellColor(r, c) == QColor(0,0,0)){
                //color->setRgb(187, 187, 187);
                color->setRgb(0,0,0);
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
                //color->setRgb(187, 187, 187);
                color->setRgb(0,0,0);
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

//Play back through the slides
void MainWindow::on_PlayButton_clicked()
{
    countDown = 100 / test;

    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    // Switch between Play and Pause
    if (isPlaying)
    {
        isPlaying = false;
        ui->PlayButton->setText("Resume");
        timer->stop();
        totalTime = totalTime.addMSecs(sinceStart.restart());
    }
    else
    {

        //Start the timer
        totalTime.start();

        isPlaying = true;
        ui->PlayButton->setText("Pause");

        if ( co == animation.size() || co == 0){
            lastTimeThrough = 0;
        }
        else
            sinceStart.restart();

        showTime();
        connect(timer, SIGNAL(timeout ()), this, SLOT(showTime()));

        timer->start(10);

        //Play through all frames
        for (co = lastTimeThrough; co < animation.size(); co++){

            lastTimeThrough++;
            for(int r = 0; r < height; r++){
                for(int c = 0; c < width; c++){
                   grid->cellColors[r][c] = animation[co].getCellColor(r, c);

                    QColor *color = new QColor();
                    Grid tempGrid = animation[co];

                    //Displays black as gray.
                    if(tempGrid.getCellColor(r, c) == QColor(0,0,0)){
                       // color->setRgb(187, 187, 187);
                        color->setRgb(0,0,0);
                    }
                    else{
                        *color = tempGrid.getCellColor(r, c);
                    }
                    QString qss = QString("background-color: %1").arg(color->name());
                     mainFrame->itemAtPosition(r, c)->widget()->setStyleSheet(qss);
                }
            }
             delay(countDown);
        }
        timer->stop();
    }

    if(isPlaying)
        ui->PlayButton->setText("Play/Pause");

    isPlaying = false;
}

//Delay the playback
void MainWindow::delay(int millisecToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecToWait );
    while(QTime::currentTime() < dieTime || isPlaying == false )
    {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
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
               // color->setRgb(187, 187, 187);
                color->setRgb(0,0,0);

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
    lastTimeThrough = 0;
    ui->PlayButton->setText("Play/Pause");

    totalTime.restart();
    timer->stop();
    showTime();
    connect(timer, SIGNAL(timeout ()), this, SLOT(showTime()));

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
                   // grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
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
                   grid->cellColors[r][c].setRgb(0,0,0);
                   // grid->cellColors[r][c].setRgb(187,187,187);
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
                   grid->cellColors[r][c].setRgb(0,0,0);
                   //grid->cellColors[r][c].setRgb(187,187,187);
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
                  // grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
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
                  // grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
               else
                   grid->cellColors[r][c] = grid->cellColors[r-1][c];
           }
       }

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (c+1 < width)
                 grid->cellColors[r][c] = grid->cellColors[r][c+1];
            else
                // grid->cellColors[r][c].setRgb(187,187,187);
                grid->cellColors[r][c].setRgb(0,0,0);
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
                    //grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
           }
       }

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (c+1 < width)
                 grid->cellColors[r][c] = grid->cellColors[r][c+1];
            else
                 //grid->cellColors[r][c].setRgb(187,187,187);
                grid->cellColors[r][c].setRgb(0,0,0);
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
                   // grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
           }
       }

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
            if (c-1 < 0)
               // grid->cellColors[r][c].setRgb(187,187,187);
                grid->cellColors[r][c].setRgb(0,0,0);
            else
                grid->cellColors[r][c] = grid->cellColors[r][c-1];
        }
    }
     on_AddFrameButton_clicked();
     updateFrame();
}

void MainWindow::on_DownRight_clicked()
{
    int width = grid->getGridColumnCount();
    int height = grid->getGridRowCount();

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
               if (r-1 < 0)
                   //grid->cellColors[r][c].setRgb(187,187,187);
                   grid->cellColors[r][c].setRgb(0,0,0);
               else
                   grid->cellColors[r][c] = grid->cellColors[r-1][c];
           }
       }

    for (int r = height - 1; r >= 0; r--) {
        for (int c = width - 1; c >= 0; c--) {
            if (c-1 < 0)
               // grid->cellColors[r][c].setRgb(187,187,187);
                grid->cellColors[r][c].setRgb(0,0,0);
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

void MainWindow::showTime(){

            int milsecs = (totalTime.elapsed()) / 10;
            int secs = (milsecs / 100);
            int mins = (secs / 60) % 60;
            milsecs = milsecs % 100;
            ui->Time_label->setText(QString("%1:%2:%3")
            .arg(mins, 2, 10, QLatin1Char('0'))
            .arg(secs, 2, 10, QLatin1Char('0'))
            .arg(milsecs, 2, 10, QLatin1Char('0')) );

}

void MainWindow::on_SpeedChangeSpinBox_valueChanged(double arg1)
{
    test = arg1;
}
