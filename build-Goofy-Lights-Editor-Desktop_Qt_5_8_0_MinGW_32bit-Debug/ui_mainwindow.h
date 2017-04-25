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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *GridLabel;
    QLabel *MovementLabel;
    QGridLayout *gridLayout_8;
    QPushButton *LeftButton;
    QPushButton *RightButton;
    QPushButton *UpButton;
    QPushButton *DownButton;
    QHBoxLayout *Buttons;
    QPushButton *ColorChangeButton;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QComboBox *SpeedDropdown;
    QPushButton *QuitButton;
    QPushButton *AddFrameButton;
    QPushButton *DeleteFrameButton;
    QPushButton *PrintButton;
    QWidget *GridWidget;
    QScrollArea *animationArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *ColorWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(989, 659);
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
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        GridLabel = new QLabel(centralWidget);
        GridLabel->setObjectName(QStringLiteral("GridLabel"));
        GridLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(GridLabel, 0, 1, 1, 1);

        MovementLabel = new QLabel(centralWidget);
        MovementLabel->setObjectName(QStringLiteral("MovementLabel"));
        MovementLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(MovementLabel, 0, 2, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_8->setContentsMargins(-1, 100, -1, 100);
        LeftButton = new QPushButton(centralWidget);
        LeftButton->setObjectName(QStringLiteral("LeftButton"));

        gridLayout_8->addWidget(LeftButton, 5, 0, 1, 1);

        RightButton = new QPushButton(centralWidget);
        RightButton->setObjectName(QStringLiteral("RightButton"));

        gridLayout_8->addWidget(RightButton, 5, 2, 1, 1);

        UpButton = new QPushButton(centralWidget);
        UpButton->setObjectName(QStringLiteral("UpButton"));

        gridLayout_8->addWidget(UpButton, 4, 1, 1, 1);

        DownButton = new QPushButton(centralWidget);
        DownButton->setObjectName(QStringLiteral("DownButton"));

        gridLayout_8->addWidget(DownButton, 6, 1, 1, 1);


        gridLayout->addLayout(gridLayout_8, 1, 2, 1, 1);

        Buttons = new QHBoxLayout();
        Buttons->setSpacing(6);
        Buttons->setObjectName(QStringLiteral("Buttons"));
        ColorChangeButton = new QPushButton(centralWidget);
        ColorChangeButton->setObjectName(QStringLiteral("ColorChangeButton"));

        Buttons->addWidget(ColorChangeButton);

        PlayButton = new QPushButton(centralWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));

        Buttons->addWidget(PlayButton);

        StopButton = new QPushButton(centralWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        Buttons->addWidget(StopButton);

        SpeedDropdown = new QComboBox(centralWidget);
        SpeedDropdown->setObjectName(QStringLiteral("SpeedDropdown"));

        Buttons->addWidget(SpeedDropdown);

        QuitButton = new QPushButton(centralWidget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        Buttons->addWidget(QuitButton);

        AddFrameButton = new QPushButton(centralWidget);
        AddFrameButton->setObjectName(QStringLiteral("AddFrameButton"));

        Buttons->addWidget(AddFrameButton);

        DeleteFrameButton = new QPushButton(centralWidget);
        DeleteFrameButton->setObjectName(QStringLiteral("DeleteFrameButton"));

        Buttons->addWidget(DeleteFrameButton);

        PrintButton = new QPushButton(centralWidget);
        PrintButton->setObjectName(QStringLiteral("PrintButton"));

        Buttons->addWidget(PrintButton);


        gridLayout->addLayout(Buttons, 3, 0, 1, 3);

        GridWidget = new QWidget(centralWidget);
        GridWidget->setObjectName(QStringLiteral("GridWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GridWidget->sizePolicy().hasHeightForWidth());
        GridWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(GridWidget, 1, 1, 1, 1);

        animationArea = new QScrollArea(centralWidget);
        animationArea->setObjectName(QStringLiteral("animationArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(animationArea->sizePolicy().hasHeightForWidth());
        animationArea->setSizePolicy(sizePolicy1);
        animationArea->setMinimumSize(QSize(0, 71));
        animationArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        animationArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        animationArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 969, 173));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        animationArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(animationArea, 2, 0, 1, 3);

        ColorWidget = new QVBoxLayout();
        ColorWidget->setSpacing(6);
        ColorWidget->setObjectName(QStringLiteral("ColorWidget"));

        gridLayout->addLayout(ColorWidget, 1, 0, 1, 1);

        gridLayout->setRowMinimumHeight(2, 175);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 989, 21));
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
        label->setText(QApplication::translate("MainWindow", "Colors", Q_NULLPTR));
        GridLabel->setText(QApplication::translate("MainWindow", "Main Grid", Q_NULLPTR));
        MovementLabel->setText(QApplication::translate("MainWindow", "Move Tiles", Q_NULLPTR));
        LeftButton->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        RightButton->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        UpButton->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        DownButton->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        ColorChangeButton->setText(QApplication::translate("MainWindow", "Change Color", Q_NULLPTR));
        PlayButton->setText(QApplication::translate("MainWindow", "Play/Pause", Q_NULLPTR));
        StopButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        SpeedDropdown->clear();
        SpeedDropdown->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.25x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.5x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.75x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.25x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.5x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.75", Q_NULLPTR)
        );
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        AddFrameButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Add a frame to the end of the animation</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        AddFrameButton->setText(QApplication::translate("MainWindow", "Add Frame", Q_NULLPTR));
        DeleteFrameButton->setText(QApplication::translate("MainWindow", "Delete Frame", Q_NULLPTR));
        PrintButton->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
