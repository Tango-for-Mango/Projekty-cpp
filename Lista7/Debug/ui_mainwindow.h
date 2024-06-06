/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/



#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "my_widget.h"




QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Koniec;
    QAction *action_O_programie;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *przycisk;
    QSpacerItem *horizontalSpacer_2;
    MyWidget *widget;
    QMenuBar *menubar;
    QMenu *menu_Plik;
    QMenu *menuPo_moc;
    QStatusBar *statusbar;
    QToolBar *toolBar;


    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_Koniec = new QAction(MainWindow);
        action_Koniec->setObjectName("action_Koniec");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        action_Koniec->setIcon(icon);
        action_O_programie = new QAction(MainWindow);
        action_O_programie->setObjectName("action_O_programie");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("help-about")));
        action_O_programie->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);


        horizontalLayout->addItem(horizontalSpacer);


        przycisk = new QPushButton(centralwidget);
        przycisk->setObjectName("przycisk");

        horizontalLayout->addWidget(przycisk);


        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);



        verticalLayout->addLayout(horizontalLayout);

        widget = new MyWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_Plik = new QMenu(menubar);
        menu_Plik->setObjectName("menu_Plik");
        menuPo_moc = new QMenu(menubar);
        menuPo_moc->setObjectName("menuPo_moc");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu_Plik->menuAction());
        menubar->addAction(menuPo_moc->menuAction());
        menu_Plik->addAction(action_Koniec);
        menuPo_moc->addAction(action_O_programie);
        toolBar->addAction(action_Koniec);
        toolBar->addAction(action_O_programie);

        retranslateUi(MainWindow);
        QObject::connect(przycisk, &QPushButton::clicked, widget, qOverload<>(&MyWidget::toggle_animation));

        QMetaObject::connectSlotsByName(MainWindow);
    }  


    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Koniec->setText(QCoreApplication::translate("MainWindow", "&Koniec", nullptr));
#if QT_CONFIG(shortcut)
        action_Koniec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif  
        action_O_programie->setText(QCoreApplication::translate("MainWindow", "&O programie", nullptr));
#if QT_CONFIG(tooltip)
        przycisk->setToolTip(QCoreApplication::translate("MainWindow", "W\305\202\304\205cz lub wy\305\202\304\205cz animacj\304\231", nullptr));
#endif  
        przycisk->setText(QString());
        menu_Plik->setTitle(QCoreApplication::translate("MainWindow", "&Plik", nullptr));
        menuPo_moc->setTitle(QCoreApplication::translate("MainWindow", "Po&moc", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    }  

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif  
