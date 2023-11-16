/********************************************************************************
** Form generated from reading UI file 'SocialNetwork.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORK_H
#define UI_SOCIALNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_SocialNetworkClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *feedList;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *userPostsList;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *inputEdit;
    QPushButton *editPostButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *subscribedTopics;
    QVBoxLayout *verticalLayout;
    QListWidget *unsubscribedTopics;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *inputSearchUnsub;
    QPushButton *subscribeButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputPostText;
    QPushButton *postButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SocialNetworkClass)
    {
        if (SocialNetworkClass->objectName().isEmpty())
            SocialNetworkClass->setObjectName("SocialNetworkClass");
        SocialNetworkClass->resize(1084, 576);
        centralWidget = new QWidget(SocialNetworkClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(centralWidget);
        label->setObjectName("label");

        verticalLayout_4->addWidget(label);

        feedList = new QListWidget(centralWidget);
        feedList->setObjectName("feedList");

        verticalLayout_4->addWidget(feedList);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        userPostsList = new QListWidget(centralWidget);
        userPostsList->setObjectName("userPostsList");

        verticalLayout_3->addWidget(userPostsList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        inputEdit = new QLineEdit(centralWidget);
        inputEdit->setObjectName("inputEdit");

        horizontalLayout_3->addWidget(inputEdit);

        editPostButton = new QPushButton(centralWidget);
        editPostButton->setObjectName("editPostButton");

        horizontalLayout_3->addWidget(editPostButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        subscribedTopics = new QListWidget(centralWidget);
        subscribedTopics->setObjectName("subscribedTopics");
        subscribedTopics->setMinimumSize(QSize(71, 0));

        verticalLayout_2->addWidget(subscribedTopics);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        unsubscribedTopics = new QListWidget(centralWidget);
        unsubscribedTopics->setObjectName("unsubscribedTopics");
        unsubscribedTopics->setMinimumSize(QSize(71, 0));

        verticalLayout->addWidget(unsubscribedTopics);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        inputSearchUnsub = new QLineEdit(centralWidget);
        inputSearchUnsub->setObjectName("inputSearchUnsub");

        horizontalLayout_4->addWidget(inputSearchUnsub);

        subscribeButton = new QPushButton(centralWidget);
        subscribeButton->setObjectName("subscribeButton");

        horizontalLayout_4->addWidget(subscribeButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        inputPostText = new QLineEdit(centralWidget);
        inputPostText->setObjectName("inputPostText");

        horizontalLayout->addWidget(inputPostText);

        postButton = new QPushButton(centralWidget);
        postButton->setObjectName("postButton");

        horizontalLayout->addWidget(postButton);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        SocialNetworkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SocialNetworkClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1084, 22));
        SocialNetworkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SocialNetworkClass);
        mainToolBar->setObjectName("mainToolBar");
        SocialNetworkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SocialNetworkClass);
        statusBar->setObjectName("statusBar");
        SocialNetworkClass->setStatusBar(statusBar);

        retranslateUi(SocialNetworkClass);
        QObject::connect(inputSearchUnsub, SIGNAL(textChanged(QString)), SocialNetworkClass, SLOT(search()));
        QObject::connect(subscribeButton, SIGNAL(clicked()), SocialNetworkClass, SLOT(subscribe()));
        QObject::connect(postButton, SIGNAL(clicked()), SocialNetworkClass, SLOT(makePost()));
        QObject::connect(editPostButton, SIGNAL(clicked()), SocialNetworkClass, SLOT(editPost()));
        QObject::connect(userPostsList, SIGNAL(clicked(QModelIndex)), SocialNetworkClass, SLOT(showPost()));

        QMetaObject::connectSlotsByName(SocialNetworkClass);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkClass)
    {
        SocialNetworkClass->setWindowTitle(QCoreApplication::translate("SocialNetworkClass", "SocialNetwork", nullptr));
        label->setText(QCoreApplication::translate("SocialNetworkClass", "<html><head/><body><p align=\"center\">Your feed</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SocialNetworkClass", "<html><head/><body><p align=\"center\">Your posts</p></body></html>", nullptr));
        editPostButton->setText(QCoreApplication::translate("SocialNetworkClass", "Edit Post", nullptr));
        label_3->setText(QCoreApplication::translate("SocialNetworkClass", "<html><head/><body><p align=\"center\">Subscriptions</p></body></html>", nullptr));
        subscribeButton->setText(QCoreApplication::translate("SocialNetworkClass", "Subscribe", nullptr));
        label_4->setText(QCoreApplication::translate("SocialNetworkClass", "Make a new post", nullptr));
        postButton->setText(QCoreApplication::translate("SocialNetworkClass", "Post", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkClass: public Ui_SocialNetworkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORK_H
