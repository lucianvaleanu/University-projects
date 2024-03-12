#pragma once
#include <vector>

class Observer {
public:
	virtual void update() = 0;
	~Observer() {}
};

class Subject {
private:
	std::vector<Observer*> observers;

public:
	void registerObserver(Observer* o)
	{
		observers.push_back(o);
	}
	void unregisterObserver(Observer* o)
	{
		observers.erase(std::find(observers.begin(), observers.end(), o));
	}
	void notify()
	{
		for (auto* o : observers)
			o->update();
	}
};