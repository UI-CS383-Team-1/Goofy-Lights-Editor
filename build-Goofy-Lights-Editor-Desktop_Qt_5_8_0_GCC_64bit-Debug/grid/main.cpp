#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QTCore>
#include <QGridLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = new QWidget;

    QGridLayout *layout = new QGridLayout;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            QPushButton *tmp = new QPushButton;
            layout->addWidget(tmp,i,j);
        }
    }


    w->setLayout(layout);

    w->show();

    return a.exec();
}
