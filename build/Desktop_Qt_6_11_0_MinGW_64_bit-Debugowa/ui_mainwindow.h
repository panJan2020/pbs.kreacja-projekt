/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Otw_rz;
    QAction *actionZapi_sz;
    QAction *action_Koniec;
    QAction *actionO_Prog_ramie;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_Otw_rz = new QAction(MainWindow);
        action_Otw_rz->setObjectName("action_Otw_rz");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ikony/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_Otw_rz->setIcon(icon);
        actionZapi_sz = new QAction(MainWindow);
        actionZapi_sz->setObjectName("actionZapi_sz");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ikony/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionZapi_sz->setIcon(icon1);
        action_Koniec = new QAction(MainWindow);
        action_Koniec->setObjectName("action_Koniec");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ikony/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_Koniec->setIcon(icon2);
        actionO_Prog_ramie = new QAction(MainWindow);
        actionO_Prog_ramie->setObjectName("actionO_Prog_ramie");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ikony/about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionO_Prog_ramie->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 530));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(35);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuPlik = new QMenu(menubar);
        menuPlik->setObjectName("menuPlik");
        menuPomoc = new QMenu(menubar);
        menuPomoc->setObjectName("menuPomoc");
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuPlik->menuAction());
        menubar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(action_Otw_rz);
        menuPlik->addAction(actionZapi_sz);
        menuPlik->addSeparator();
        menuPlik->addAction(action_Koniec);
        menuPomoc->addAction(actionO_Prog_ramie);
        toolBar->addAction(action_Otw_rz);
        toolBar->addAction(actionZapi_sz);
        toolBar->addSeparator();
        toolBar->addAction(action_Koniec);
        toolBar->addSeparator();
        toolBar->addAction(actionO_Prog_ramie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Technologie Przetwarzania i Kreacji Wizualnej wer. 1.0", nullptr));
        action_Otw_rz->setText(QCoreApplication::translate("MainWindow", "&Otw\303\263rz", nullptr));
#if QT_CONFIG(shortcut)
        action_Otw_rz->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZapi_sz->setText(QCoreApplication::translate("MainWindow", "Zapi&sz", nullptr));
#if QT_CONFIG(shortcut)
        actionZapi_sz->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Koniec->setText(QCoreApplication::translate("MainWindow", "&Koniec", nullptr));
#if QT_CONFIG(shortcut)
        action_Koniec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+K", nullptr));
#endif // QT_CONFIG(shortcut)
        actionO_Prog_ramie->setText(QCoreApplication::translate("MainWindow", "O Prog&ramie...", nullptr));
#if QT_CONFIG(shortcut)
        actionO_Prog_ramie->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuPlik->setTitle(QCoreApplication::translate("MainWindow", "Plik", nullptr));
        menuPomoc->setTitle(QCoreApplication::translate("MainWindow", "Pomoc", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
