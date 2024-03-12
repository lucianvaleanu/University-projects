#pragma once
#include "User.h"
#include <vector>

class Topic {
private:
	std::string name;
	std::vector<User> subscribers;
public:
	Topic(const std::string& name, const std::vector<User>& subscribers) : name(name), subscribers(subscribers) {}
	std::string getName()const { return name; }
	std::vector<User> getSubscribers()const { return subscribers; }
	void addSubscriber(const User& user) { subscribers.push_back(user); }
};