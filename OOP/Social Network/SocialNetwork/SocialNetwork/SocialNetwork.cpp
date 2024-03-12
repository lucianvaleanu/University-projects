#include "SocialNetwork.h"

SocialNetwork::SocialNetwork(Controller& controller, User user, QWidget* parent)
    : QMainWindow(parent), controller(controller), user(user)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user.getName()));
    this->controller.registerObserver(this);

    populateFeed();
    populatePosts();
    populateTopics();
    populateUnsubscribed();
}

SocialNetwork::~SocialNetwork()
{
    this->controller.unregisterObserver(this);
}

void SocialNetwork::update()
{
    populateFeed();
    populatePosts();
    populateTopics();
    populateUnsubscribed();
}

void SocialNetwork::populateFeed()
{
    this->ui.feedList->clear();
    std::vector<Post> posts = controller.getPostsForUser(user);
    std::sort(posts.begin(), posts.end(), [](const Post& p1, const Post& p2) {
        return (p1.getTime() > p2.getTime());
        });
    for (const auto& p : posts)
    {
        Timestamp ts = p.getTime();
        std::string tsStr = std::to_string(ts.day) + "-" + std::to_string(ts.month) + "-" + std::to_string(ts.year) + " " + std::to_string(ts.hours) + ":" + std::to_string(ts.min);
        std::string text = p.getUser().getName() + ": " + p.getText() + " | " + tsStr;
        QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(text) };
        std::string atText = "@" + user.getName();
        if (text.find(atText) != std::string::npos)
        {
            QBrush color{ Qt::blue };
            item->setForeground(color);
        }
        this->ui.feedList->addItem(item);
    }

}

void SocialNetwork::populatePosts()
{
    this->ui.userPostsList->clear();
    std::vector<Post> posts = controller.getPostsByUser(user);
    std::sort(posts.begin(), posts.end(), [](const Post& p1, const Post& p2) {
        return (p1.getTime() > p2.getTime());
        });
    for (const auto& p : posts)
    {
        Timestamp ts = p.getTime();
        std::string tsStr = std::to_string(ts.day) + "-" + std::to_string(ts.month) + "-" + std::to_string(ts.year) + " " + std::to_string(ts.hours) + ":" + std::to_string(ts.min);
        std::string text = p.getText() + " | " + tsStr;
        this->ui.userPostsList->addItem(QString::fromStdString(text));
    }
}

void SocialNetwork::populateTopics()
{
    this->ui.subscribedTopics->clear();
    std::vector<Topic> topics = controller.getSubscribedTo(user);
    for (const auto& t : topics)
        this->ui.subscribedTopics->addItem(QString::fromStdString(t.getName()));
}

void SocialNetwork::populateUnsubscribed()
{
    this->ui.unsubscribedTopics->clear();
    std::vector<Topic> topics = controller.getUnsubscribedTo(user);
    for (const auto& t : topics)
        this->ui.unsubscribedTopics->addItem(QString::fromStdString(t.getName()));
}

void SocialNetwork::subscribe()
{
    QListWidgetItem* item = this->ui.unsubscribedTopics->currentItem();
    if (item)
    {
        std::string topicName = item->text().toStdString();
        Topic& topic = controller.getTopic(topicName);
        topic.addSubscriber(user);
        controller.saveTopics();
        update();
        this->ui.inputSearchUnsub->clear();
    }
    else
    {
        this->ui.inputSearchUnsub->clear();
        QMessageBox::critical(this, "Error!", "Must select a topic to subscribe to it!");
        return;
    }
}

void SocialNetwork::makePost()
{
    if (this->ui.inputPostText->text().size() < 3)
    {
        this->ui.inputPostText->clear();
        QMessageBox::critical(this, "Error!", "New post can't be less than 3 characters!");
        return;
    }
    else
    {
        std::string text = this->ui.inputPostText->text().toStdString();
        this->ui.inputPostText->clear();
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);
        Timestamp currentTimestamp;
        currentTimestamp.min = localTime->tm_min;
        currentTimestamp.hours = localTime->tm_hour;
        currentTimestamp.day = localTime->tm_mday;
        currentTimestamp.month = localTime->tm_mon + 1;
        currentTimestamp.year = localTime->tm_year + 1900;
        Post newPost{ (lastId + 1),text,currentTimestamp,user };
        controller.addPost(newPost);
    }
}

void SocialNetwork::editPost()
{
    QListWidgetItem* item = this->ui.userPostsList->currentItem();
    if (item)
    {
        std::stringstream ss(item->text().toStdString());
        std::string text;
        std::getline(ss, text, '|');
        Post& post = controller.getPostByText(text);
        std::string newText = this->ui.inputEdit->text().toStdString();
        if (newText.size() < 3)
        {
            this->ui.inputEdit->clear();
            QMessageBox::critical(this, "Error!", "The new edit can't be less than 3 characters!");
            return;
        }
        post.setText(newText);
        this->ui.inputEdit->clear();
        controller.savePosts();
        controller.notify();
    }
    else
    {
        this->ui.inputEdit->clear();
        QMessageBox::critical(this, "Error!", "Must select a post first in order to edit it!");
        return;
    }
}

void SocialNetwork::search()
{
    this->ui.unsubscribedTopics->clear();
    std::string inputSearch = this->ui.inputSearchUnsub->text().toStdString();
    std::transform(inputSearch.begin(), inputSearch.end(), inputSearch.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    if (inputSearch.size() > 0)
        inputSearch[0] = std::toupper(inputSearch[0]);

    std::vector<Topic> topics = controller.getUnsubscribedTo(user);
    for (const auto& t : topics)
        if (t.getName().find(inputSearch) != std::string::npos)
            this->ui.unsubscribedTopics->addItem(QString::fromStdString(t.getName()));
}

void SocialNetwork::showPost()
{
    this->ui.inputEdit->clear();
    QListWidgetItem* item = this->ui.userPostsList->currentItem();
    if (item)
    {
        std::stringstream ss(item->text().toStdString());
        std::string text;
        std::getline(ss, text, '|');
        this->ui.inputEdit->setText(QString::fromStdString(text));
    }
}
