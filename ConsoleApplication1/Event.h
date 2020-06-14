#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Event_name
{
	string name;
};

struct Date {
	int day, month, year, hour, min;
};

class Event
{
private:
	Event_name initials;
	Date date;

public:
	Event();
	Event(Event_name initials_, Date date_);
	~Event();

	void Print();
	void EventEntry(Event_name initials_, Date date_);
	
	//Вывод данных класса
	Event_name GetInitials()
	{
		return initials;
	};
	Date GetDate()
	{
		return date;
	};

	Event& operator = (Event d_o);
};