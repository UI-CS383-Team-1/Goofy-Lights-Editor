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
#include <QtWidgets/QDoubleSpinBox>
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
#include <QtWidgets/QToolButton>
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
    QAction *actionHotkeys;
    QWidget *centralWidget;
    QWidget *GridWidget;
    QLabel *label;
    QLabel *GridLabel;
    QScrollArea *animationArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QToolButton *DownButton;
    QToolButton *RightButton;
    QToolButton *LeftButton;
    QToolButton *UpButton;
    QToolButton *DownLeft;
    QToolButton *DownRight;
    QToolButton *UpLeft;
    QToolButton *UpRight;
    QLabel *label_2;
    QLabel *Time_label;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QVBoxLayout *ColorWidget;
    QWidget *layoutWidget2;
    QHBoxLayout *Buttons;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QLabel *label_4;
    QDoubleSpinBox *SpeedChangeSpinBox;
    QComboBox *SpeedDropdown;
    QPushButton *QuitButton;
    QPushButton *AddFrameButton;
    QPushButton *DeleteFrameButton;
    QPushButton *PrintButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1285, 759);
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
        actionHotkeys = new QAction(MainWindow);
        actionHotkeys->setObjectName(QStringLiteral("actionHotkeys"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        GridWidget = new QWidget(centralWidget);
        GridWidget->setObjectName(QStringLiteral("GridWidget"));
        GridWidget->setGeometry(QRect(610, 30, 661, 321));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GridWidget->sizePolicy().hasHeightForWidth());
        GridWidget->setSizePolicy(sizePolicy);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 40, 16));
        label->setAlignment(Qt::AlignCenter);
        GridLabel = new QLabel(centralWidget);
        GridLabel->setObjectName(QStringLiteral("GridLabel"));
        GridLabel->setGeometry(QRect(680, 10, 59, 16));
        GridLabel->setAlignment(Qt::AlignCenter);
        animationArea = new QScrollArea(centralWidget);
        animationArea->setObjectName(QStringLiteral("animationArea"));
        animationArea->setGeometry(QRect(10, 460, 1261, 171));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1259, 169));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        animationArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(860, 360, 211, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DownButton = new QToolButton(layoutWidget);
        DownButton->setObjectName(QStringLiteral("DownButton"));

        gridLayout->addWidget(DownButton, 2, 1, 1, 1);

        RightButton = new QToolButton(layoutWidget);
        RightButton->setObjectName(QStringLiteral("RightButton"));

        gridLayout->addWidget(RightButton, 1, 2, 1, 1);

        LeftButton = new QToolButton(layoutWidget);
        LeftButton->setObjectName(QStringLiteral("LeftButton"));

        gridLayout->addWidget(LeftButton, 1, 0, 1, 1);

        UpButton = new QToolButton(layoutWidget);
        UpButton->setObjectName(QStringLiteral("UpButton"));

        gridLayout->addWidget(UpButton, 0, 1, 1, 1);

        DownLeft = new QToolButton(layoutWidget);
        DownLeft->setObjectName(QStringLiteral("DownLeft"));

        gridLayout->addWidget(DownLeft, 2, 0, 1, 1);

        DownRight = new QToolButton(layoutWidget);
        DownRight->setObjectName(QStringLiteral("DownRight"));

        gridLayout->addWidget(DownRight, 2, 2, 1, 1);

        UpLeft = new QToolButton(layoutWidget);
        UpLeft->setObjectName(QStringLiteral("UpLeft"));

        gridLayout->addWidget(UpLeft, 0, 0, 1, 1);

        UpRight = new QToolButton(layoutWidget);
        UpRight->setObjectName(QStringLiteral("UpRight"));

        gridLayout->addWidget(UpRight, 0, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(780, 360, 71, 16));
        Time_label = new QLabel(centralWidget);
        Time_label->setObjectName(QStringLiteral("Time_label"));
        Time_label->setGeometry(QRect(760, 420, 81, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(710, 420, 41, 21));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 581, 421));
        ColorWidget = new QVBoxLayout(layoutWidget1);
        ColorWidget->setSpacing(6);
        ColorWidget->setContentsMargins(11, 11, 11, 11);
        ColorWidget->setObjectName(QStringLiteral("ColorWidget"));
        ColorWidget->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 650, 1261, 36));
        Buttons = new QHBoxLayout(layoutWidget2);
        Buttons->setSpacing(6);
        Buttons->setContentsMargins(11, 11, 11, 11);
        Buttons->setObjectName(QStringLiteral("Buttons"));
        Buttons->setContentsMargins(0, 0, 0, 0);
        PlayButton = new QPushButton(layoutWidget2);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));

        Buttons->addWidget(PlayButton);

        StopButton = new QPushButton(layoutWidget2);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        Buttons->addWidget(StopButton);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        Buttons->addWidget(label_4);

        SpeedChangeSpinBox = new QDoubleSpinBox(layoutWidget2);
        SpeedChangeSpinBox->setObjectName(QStringLiteral("SpeedChangeSpinBox"));
        SpeedChangeSpinBox->setMaximum(100);
        SpeedChangeSpinBox->setSingleStep(0.1);
        SpeedChangeSpinBox->setValue(1);

        Buttons->addWidget(SpeedChangeSpinBox);

        SpeedDropdown = new QComboBox(layoutWidget2);
        SpeedDropdown->setObjectName(QStringLiteral("SpeedDropdown"));

        Buttons->addWidget(SpeedDropdown);

        QuitButton = new QPushButton(layoutWidget2);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        Buttons->addWidget(QuitButton);

        AddFrameButton = new QPushButton(layoutWidget2);
        AddFrameButton->setObjectName(QStringLiteral("AddFrameButton"));

        Buttons->addWidget(AddFrameButton);

        DeleteFrameButton = new QPushButton(layoutWidget2);
        DeleteFrameButton->setObjectName(QStringLiteral("DeleteFrameButton"));

        Buttons->addWidget(DeleteFrameButton);

        PrintButton = new QPushButton(layoutWidget2);
        PrintButton->setObjectName(QStringLiteral("PrintButton"));

        Buttons->addWidget(PrintButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1285, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionHotkeys);
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
        actionHotkeys->setText(QApplication::translate("MainWindow", "Hotkeys", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Colors", Q_NULLPTR));
        GridLabel->setText(QApplication::translate("MainWindow", "Main Grid", Q_NULLPTR));
        DownButton->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        RightButton->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        LeftButton->setText(QApplication::translate("MainWindow", " Left ", Q_NULLPTR));
        UpButton->setText(QApplication::translate("MainWindow", "   Up   ", Q_NULLPTR));
        DownLeft->setText(QApplication::translate("MainWindow", "  LD  ", Q_NULLPTR));
        DownRight->setText(QApplication::translate("MainWindow", "  RD  ", Q_NULLPTR));
        UpLeft->setText(QApplication::translate("MainWindow", "  LU  ", Q_NULLPTR));
        UpRight->setText(QApplication::translate("MainWindow", "  RU  ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Move Tiles", Q_NULLPTR));
        Time_label->setText(QApplication::translate("MainWindow", "mm:ss:msms", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Time:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        PlayButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Start </span>or <span style=\" font-weight:600;\">Pause</span> the animation playback</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        PlayButton->setText(QApplication::translate("MainWindow", "Play/Pause", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        StopButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Stop</span> the animation playback</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        StopButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "      Speed times:", Q_NULLPTR));
        SpeedDropdown->clear();
        SpeedDropdown->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.25", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "0.75", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.25", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.75", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        SpeedDropdown->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Change the speed of the animation playback</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        SpeedDropdown->setCurrentText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        QuitButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Quit the Goofy-Lights-Editor (without saving)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        AddFrameButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Add a frame to the end of the animation</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        AddFrameButton->setText(QApplication::translate("MainWindow", "Add Frame", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        DeleteFrameButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Delete the selected frame</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        DeleteFrameButton->setText(QApplication::translate("MainWindow", "Delete Frame", Q_NULLPTR));
        PrintButton->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
