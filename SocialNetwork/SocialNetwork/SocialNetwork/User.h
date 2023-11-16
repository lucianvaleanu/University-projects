#pragma once
#include <string>

class User {
private:
	std::string name;
public:
	User(const std::string& name) :name(name) {}
	std::string getName()const { return name; }
	bool operator==(const User& other) { return (this->name == other.getName()); }
};