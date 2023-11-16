#pragma once
#include "User.h"

typedef struct Timestamp {
	int min, hours, day, month, year;
	bool operator>(const Timestamp& other)
	{
		if (year > other.year)
			return true;
		else if (year < other.year)
			return false;

		if (month > other.month)
			return true;
		else if (month < other.month)
			return false;

		if (day > other.day)
			return true;
		else if (day < other.day)
			return false;

		if (hours > other.hours)
			return true;
		else if (hours < other.hours)
			return false;

		if (min > other.min)
			return true;
		else if (min < other.min)
			return false;

		return false;
	}
}Timestamp;

class Post {
private:
	int id;
	std::string text;
	Timestamp time;
	User user;
public:
	Post(const int& id, const std::string& text, const Timestamp& ts, const User& user) :id(id), text(text), time(ts), user(user) {}
	int getId()const { return id; }
	std::string getText()const { return text; }
	Timestamp getTime()const { return time; }
	User getUser()const { return user; }
	void setText(const std::string& newText) { text = newText; }
};