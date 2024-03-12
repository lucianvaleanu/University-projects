#include "SocialNetwork.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller controller{ "users.txt", "topics.txt", "posts.txt" };
    std::vector<User> users = controller.getUsers();
    SocialNetwork w{ controller, users[0] };
    w.show();
    SocialNetwork w1{ controller, users[1] };
    w1.show();
    SocialNetwork w2{ controller, users[2] };
    w2.show();
    SocialNetwork w3{ controller, users[3] };
    w3.show();
    SocialNetwork w4{ controller, users[4] };
    w4.show();

    return a.exec();
}
