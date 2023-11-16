#include "Controller.h"

std::vector<Topic> Controller::getUnsubscribedTo(const User& user) const
{
    std::vector<Topic> outTopics;
    for (const auto& t : topics)
    {
        bool found = false;
        auto subs = t.getSubscribers();
        for (auto s : subs)
        {
            if (s == user)
            {
                found = true;
                break;
            }
        }
        if (!found)
            outTopics.push_back(t);
    }
    return outTopics;
}

std::vector<Topic> Controller::getSubscribedTo(const User& user) const
{
    std::vector<Topic> outTopics;
    for (const auto& t : topics)
    {
        bool found = false;
        auto subs = t.getSubscribers();
        for (auto s : subs)
        {
            if (s.getName() == user.getName())
            {
                found = true;
                break;
            }
        }
        if (found)
            outTopics.push_back(t);
    }
    return outTopics;
}

std::vector<Post> Controller::getPostsForUser(const User& user) const
{
    std::vector<Post> outPosts;
    std::vector<Topic> subscriptions = getSubscribedTo(user);
    for (const auto& p : posts)
    {
        bool add = false;
        if (!(p.getUser() == user))
        {
            if (p.getText().find(user.getName()) != std::string::npos)
                add = true;
            if (!add) {
                for (const auto& t : subscriptions)
                {
                    std::string topic = t.getName();
                    std::transform(topic.begin(), topic.end(), topic.begin(), [](unsigned char c) {
                        return std::tolower(c);
                        });
                    if (p.getText().find(topic) != std::string::npos)
                        add = true;
                }
            }
        }
        if (add)
            outPosts.push_back(p);
    }
    return outPosts;
}

std::vector<Post> Controller::getPostsByUser(const User& user) const
{
    std::vector<Post> outPosts;
    for (const auto& p : posts)
        if (p.getUser() == user)
            outPosts.push_back(p);
    return outPosts;
}

Topic& Controller::getTopic(const std::string& name)
{
    for (auto& topic : topics)
        if (topic.getName() == name)
            return topic;
}

Post& Controller::getPost(const int& id)
{
    for (auto& post : posts)
        if (post.getId() == id)
            return post;
}

Post& Controller::getPostByText(const std::string& text)
{
    for (auto& post : posts)
        if (text.find(post.getText()) != std::string::npos || post.getText().find(text) != std::string::npos)
            return post;
}

void Controller::addPost(const Post& post)
{
    posts.push_back(post);
    notify();
    savePosts();
}

void Controller::readUsers()
{
    std::ifstream file(usersFile);
    std::string name;
    while (std::getline(file, name))
    {
        User user{ name };
        users.push_back(user);
    }
    file.close();
}

void Controller::readTopics()
{
    std::ifstream file(topicsFile);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name, usersStream, userName;
        std::vector<User> subscribers;
        std::getline(iss, name,':');
        std::getline(iss, usersStream);
        std::istringstream issUsers(usersStream);
        while (std::getline(issUsers, userName, ','))
        {
            User user{ userName };
            subscribers.push_back(user);
        }
        Topic topic{ name,subscribers };
        topics.push_back(topic);
    }
    file.close();
}

void Controller::readPosts()
{
    std::ifstream file(postsFile);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string id, text, year, month, day, hours, min, userName;
        std::getline(iss, id, '|');
        std::getline(iss, text, '|');
        std::getline(iss, year, '-');
        std::getline(iss, month, '-');
        std::getline(iss, day, '|');
        std::getline(iss, hours, ':');
        std::getline(iss, min, '|');
        std::getline(iss, userName);
        Timestamp time{ std::stoi(min),std::stoi(hours) ,std::stoi(day) ,std::stoi(month) ,std::stoi(year) };
        Post post{ std::stoi(id), text, time, {userName} };
        posts.push_back(post);
    }
    file.close();
}

void Controller::saveTopics()
{
    std::ofstream file(topicsFile);
    for (const auto& t : topics)
    {
        file << t.getName()<<":";
        const auto subs = t.getSubscribers();
        for (int i = 0; i < subs.size() - 1; ++i)
            file << subs[i].getName() << ",";
        file << subs[subs.size() - 1].getName();
        file << "\n";
    }
    file.close();
}

void Controller::savePosts()
{
    std::ofstream file(postsFile);
    for (const auto& p : posts)
    {
        file << p.getId() << "|" << p.getText() << "|" << p.getTime().year << "-" << p.getTime().month << "-"
            << p.getTime().day << "|" << p.getTime().hours << ":" << p.getTime().min << "|" << p.getUser().getName();
        file << "\n";
    }
    file.close();
}
