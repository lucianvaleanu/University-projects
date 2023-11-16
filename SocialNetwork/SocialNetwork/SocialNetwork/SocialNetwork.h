#pragma once

#include <ctime>
#include <chrono>
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_SocialNetwork.h"
#include "Controller.h"

class SocialNetwork : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    SocialNetwork(Controller& controller, User user, QWidget *parent = nullptr);
    ~SocialNetwork();

    void update();

    void populateFeed();
    void populatePosts();
    void populateTopics();
    void populateUnsubscribed();

public slots:
    void subscribe();
    void makePost();
    void editPost();
    void search();
    void showPost();


private:
    Ui::SocialNetworkClass ui;
    Controller& controller;
    User user;
    int lastId = 5;
};
