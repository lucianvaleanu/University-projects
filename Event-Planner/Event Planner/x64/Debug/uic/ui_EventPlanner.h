/********************************************************************************
** Form generated from reading UI file 'EventPlanner.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTPLANNER_H
#define UI_EVENTPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventPlannerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *personLocation;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QListWidget *eventsList;
    QPushButton *goingButton;
    QLabel *partyDescriptionLabel;
    QListWidget *listOfInvited;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *nameLabel;
    QLineEdit *inputName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *descLabe;
    QLineEdit *inputDescription;
    QHBoxLayout *horizontalLayout_5;
    QLabel *latLabel;
    QLineEdit *inputLatitude;
    QHBoxLayout *horizontalLayout_4;
    QLabel *longLabel;
    QLineEdit *inputLongitude;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dLabel;
    QLineEdit *inputDay;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mLabel;
    QLineEdit *inputMonth;
    QHBoxLayout *horizontalLayout;
    QLabel *yLabel;
    QLineEdit *inputYear;
    QPushButton *addEventButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EventPlannerClass)
    {
        if (EventPlannerClass->objectName().isEmpty())
            EventPlannerClass->setObjectName("EventPlannerClass");
        EventPlannerClass->resize(599, 577);
        centralWidget = new QWidget(EventPlannerClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        personLocation = new QLabel(centralWidget);
        personLocation->setObjectName("personLocation");
        personLocation->setMinimumSize(QSize(161, 16));
        personLocation->setMaximumSize(QSize(161, 16));

        verticalLayout_4->addWidget(personLocation);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName("checkBox");

        verticalLayout_2->addWidget(checkBox);

        eventsList = new QListWidget(centralWidget);
        eventsList->setObjectName("eventsList");

        verticalLayout_2->addWidget(eventsList);

        goingButton = new QPushButton(centralWidget);
        goingButton->setObjectName("goingButton");

        verticalLayout_2->addWidget(goingButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        partyDescriptionLabel = new QLabel(centralWidget);
        partyDescriptionLabel->setObjectName("partyDescriptionLabel");

        verticalLayout_3->addWidget(partyDescriptionLabel);


        horizontalLayout_8->addLayout(verticalLayout_3);

        listOfInvited = new QListWidget(centralWidget);
        listOfInvited->setObjectName("listOfInvited");

        horizontalLayout_8->addWidget(listOfInvited);


        verticalLayout_4->addLayout(horizontalLayout_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout_7->addWidget(nameLabel);

        inputName = new QLineEdit(centralWidget);
        inputName->setObjectName("inputName");

        horizontalLayout_7->addWidget(inputName);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        descLabe = new QLabel(centralWidget);
        descLabe->setObjectName("descLabe");

        horizontalLayout_6->addWidget(descLabe);

        inputDescription = new QLineEdit(centralWidget);
        inputDescription->setObjectName("inputDescription");

        horizontalLayout_6->addWidget(inputDescription);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        latLabel = new QLabel(centralWidget);
        latLabel->setObjectName("latLabel");

        horizontalLayout_5->addWidget(latLabel);

        inputLatitude = new QLineEdit(centralWidget);
        inputLatitude->setObjectName("inputLatitude");

        horizontalLayout_5->addWidget(inputLatitude);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        longLabel = new QLabel(centralWidget);
        longLabel->setObjectName("longLabel");

        horizontalLayout_4->addWidget(longLabel);

        inputLongitude = new QLineEdit(centralWidget);
        inputLongitude->setObjectName("inputLongitude");

        horizontalLayout_4->addWidget(inputLongitude);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        dLabel = new QLabel(centralWidget);
        dLabel->setObjectName("dLabel");

        horizontalLayout_3->addWidget(dLabel);

        inputDay = new QLineEdit(centralWidget);
        inputDay->setObjectName("inputDay");

        horizontalLayout_3->addWidget(inputDay);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        mLabel = new QLabel(centralWidget);
        mLabel->setObjectName("mLabel");

        horizontalLayout_2->addWidget(mLabel);

        inputMonth = new QLineEdit(centralWidget);
        inputMonth->setObjectName("inputMonth");

        horizontalLayout_2->addWidget(inputMonth);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        yLabel = new QLabel(centralWidget);
        yLabel->setObjectName("yLabel");

        horizontalLayout->addWidget(yLabel);

        inputYear = new QLineEdit(centralWidget);
        inputYear->setObjectName("inputYear");

        horizontalLayout->addWidget(inputYear);


        verticalLayout->addLayout(horizontalLayout);

        addEventButton = new QPushButton(centralWidget);
        addEventButton->setObjectName("addEventButton");

        verticalLayout->addWidget(addEventButton);


        verticalLayout_4->addLayout(verticalLayout);

        EventPlannerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EventPlannerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 599, 22));
        EventPlannerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EventPlannerClass);
        mainToolBar->setObjectName("mainToolBar");
        EventPlannerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EventPlannerClass);
        statusBar->setObjectName("statusBar");
        EventPlannerClass->setStatusBar(statusBar);

        retranslateUi(EventPlannerClass);
        QObject::connect(goingButton, SIGNAL(clicked()), EventPlannerClass, SLOT(goingEvent()));
        QObject::connect(eventsList, SIGNAL(clicked(QModelIndex)), EventPlannerClass, SLOT(listClickEvent()));
        QObject::connect(checkBox, SIGNAL(stateChanged(int)), EventPlannerClass, SLOT(checkBoxList()));
        QObject::connect(addEventButton, SIGNAL(clicked()), EventPlannerClass, SLOT(addEvent()));

        QMetaObject::connectSlotsByName(EventPlannerClass);
    } // setupUi

    void retranslateUi(QMainWindow *EventPlannerClass)
    {
        EventPlannerClass->setWindowTitle(QCoreApplication::translate("EventPlannerClass", "EventPlanner", nullptr));
        personLocation->setText(QCoreApplication::translate("EventPlannerClass", "Location", nullptr));
        checkBox->setText(QCoreApplication::translate("EventPlannerClass", "Show near events", nullptr));
        goingButton->setText(QCoreApplication::translate("EventPlannerClass", "Going", nullptr));
        partyDescriptionLabel->setText(QCoreApplication::translate("EventPlannerClass", "PartyDescription", nullptr));
        nameLabel->setText(QCoreApplication::translate("EventPlannerClass", "Name", nullptr));
        descLabe->setText(QCoreApplication::translate("EventPlannerClass", "Description", nullptr));
        latLabel->setText(QCoreApplication::translate("EventPlannerClass", "Latitude", nullptr));
        longLabel->setText(QCoreApplication::translate("EventPlannerClass", "Longitude", nullptr));
        dLabel->setText(QCoreApplication::translate("EventPlannerClass", "Day", nullptr));
        mLabel->setText(QCoreApplication::translate("EventPlannerClass", "Month", nullptr));
        yLabel->setText(QCoreApplication::translate("EventPlannerClass", "Year", nullptr));
        addEventButton->setText(QCoreApplication::translate("EventPlannerClass", "Add Event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventPlannerClass: public Ui_EventPlannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTPLANNER_H
