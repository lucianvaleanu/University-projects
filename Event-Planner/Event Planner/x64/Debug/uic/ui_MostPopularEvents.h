/********************************************************************************
** Form generated from reading UI file 'MostPopularEvents.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOSTPOPULAREVENTS_H
#define UI_MOSTPOPULAREVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MostPopularEventsClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listOfInvited;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MostPopularEventsClass)
    {
        if (MostPopularEventsClass->objectName().isEmpty())
            MostPopularEventsClass->setObjectName("MostPopularEventsClass");
        MostPopularEventsClass->resize(209, 400);
        centralWidget = new QWidget(MostPopularEventsClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        listOfInvited = new QListWidget(centralWidget);
        listOfInvited->setObjectName("listOfInvited");

        verticalLayout->addWidget(listOfInvited);

        MostPopularEventsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MostPopularEventsClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 209, 22));
        MostPopularEventsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MostPopularEventsClass);
        mainToolBar->setObjectName("mainToolBar");
        MostPopularEventsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MostPopularEventsClass);
        statusBar->setObjectName("statusBar");
        MostPopularEventsClass->setStatusBar(statusBar);

        retranslateUi(MostPopularEventsClass);

        QMetaObject::connectSlotsByName(MostPopularEventsClass);
    } // setupUi

    void retranslateUi(QMainWindow *MostPopularEventsClass)
    {
        MostPopularEventsClass->setWindowTitle(QCoreApplication::translate("MostPopularEventsClass", "MostPopularEvents", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MostPopularEventsClass: public Ui_MostPopularEventsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOSTPOPULAREVENTS_H
