#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QtGui>
#include <QTCore>
#include <QGridLayout>
#include <QPushButton>
#include <QSize>
#include <QSizePolicy>
#include <QBoxLayout>
#include <QStyle>

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        QWidget *w = new QWidget;

        QGridLayout *layout = new QGridLayout;

        QSizePolicy *policy = new QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        policy->setHeightForWidth(true);

        /* creating grid size as 10*20 */
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                QPushButton *tmp = new QPushButton;

                tmp->setSizePolicy(*policy);

                layout->addWidget(tmp,i,j,1,1);
            }
        }

        /*setting the color of the Buttons in the grid as gray*/
        w->setStyleSheet("QPushButton {background-color: gray;"
                         "border-style: outset;"
                         "border-width: 1px;"
                         "border-color: beige; }");

        w->setLayout(layout);

        w->show();

        return a.exec();
    }
