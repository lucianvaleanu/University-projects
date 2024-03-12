#pragma once
#include "User.h"
#include "Topic.h"
#include "Post.h"
#include "Observer.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class Controller :public Subject
{
private:
	std::vector<User> users;
	std::vector<Topic> topics;
	std::vector<Post> posts;
	std::string usersFile, topicsFile, postsFile;
public:
	Controller(const std::string& users, const std::string& topics, const std::string& posts) :usersFile(users), topicsFile(topics), postsFile(posts)
	{
		readUsers();
		readTopics();
		readPosts();
	}

	std::vector<User> getUsers()const { return users; }
	std::vector<Topic> getTopics()const { return topics; }
	std::vector<Post> getPosts()const { return posts; }
	std::vector<Topic> getUnsubscribedTo(const User& user)const;
	std::vector<Topic> getSubscribedTo(const User& user)const;
	std::vector<Post> getPostsForUser(const User& user)const;
	std::vector<Post> getPostsByUser(const User& user)const;
	Topic& getTopic(const std::string& name);
	Post& getPost(const int& id);
	Post& getPostByText(const std::string& text);

	void addPost(const Post& post);


	void readUsers();
	void readTopics();
	void readPosts();
	void saveTopics();
	void savePosts();
};

