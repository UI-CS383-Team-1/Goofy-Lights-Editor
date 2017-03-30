/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLoad;
    QAction *actionNew;
    QAction *actionQuit;
    QAction *actionExport;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_2;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 457);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(122, 20, 401, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QTextBrowser(gridLayoutWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout->addWidget(textBrowser_2, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 250, 621, 61));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 350, 100, 30));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 350, 100, 30));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(310, 351, 100, 28));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 0, 91, 17));
        label_3->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_7 = new QWidget(centralWidget);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(10, 20, 111, 211));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget_7);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_7->addWidget(textBrowser, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 0, 59, 17));
        label_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_8 = new QWidget(centralWidget);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(530, 20, 101, 211));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(gridLayoutWidget_8);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_8->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_8);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_8->addWidget(pushButton_6, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget_8);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_8->addWidget(pushButton_5, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_8);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_8->addWidget(pushButton_7, 5, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(520, 0, 111, 17));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 350, 100, 30));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(10, 320, 621, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionQuit);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New Show", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Future location of main grid.</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Play/Pause", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.25x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.5x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.75x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.25x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.5x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.75", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "Main Grid", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Future location of color wheel.</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Colors", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Move Tiles", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
