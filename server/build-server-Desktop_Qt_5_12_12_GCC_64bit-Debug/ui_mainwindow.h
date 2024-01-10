/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *grpChats;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tbChats;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lstClients;
    QPushButton *btnDisconnectAll;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(637, 384);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        grpChats = new QGroupBox(centralwidget);
        grpChats->setObjectName(QString::fromUtf8("grpChats"));
        verticalLayout_3 = new QVBoxLayout(grpChats);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tbChats = new QTabWidget(grpChats);
        tbChats->setObjectName(QString::fromUtf8("tbChats"));

        verticalLayout_3->addWidget(tbChats);


        horizontalLayout->addWidget(grpChats);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstClients = new QListWidget(groupBox);
        lstClients->setObjectName(QString::fromUtf8("lstClients"));

        verticalLayout->addWidget(lstClients);

        btnDisconnectAll = new QPushButton(groupBox);
        btnDisconnectAll->setObjectName(QString::fromUtf8("btnDisconnectAll"));

        verticalLayout->addWidget(btnDisconnectAll);


        horizontalLayout->addWidget(groupBox);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 637, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tbChats->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Server", nullptr));
        grpChats->setTitle(QApplication::translate("MainWindow", "Chats", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "clients", nullptr));
        btnDisconnectAll->setText(QApplication::translate("MainWindow", "Disconnect All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
