#include "Fuctions.h"

//Создание листа событий
void EventEntry(Event* (&d), int& n)
{
	Event_name initials;
	Date date;

	cout << "Enter num of events: ";
	cin >> n;

	d = new Event[n];

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Enter event name: ";
		cin >> initials.name;

		cout << "Enter event date (YYYY/MM/DD HH/MM)..." << endl;
		cout << "Year: "; cin >> date.year;
		cout << "Month: "; cin >> date.month;
		cout << "Day: "; cin >> date.day;
		cout << "Hour: "; cin >> date.hour;
		cout << "Min: "; cin >> date.min;

		d[i].EventEntry(initials, date);

		cout << "_____________________________\n";
	}
	

}


//Вывод данных на экран
void Print(Event* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Event #:"<<i+1<< endl;
		d[i].Print();
		cout << "_____________________________\n";
	}
}

//Изменение события
void EventChange(Event* d, int n)
{
	Event_name intials;
	Date date;

	int _n;

	cout << "Enter number of events (1-" << n << "): "; cin >> _n; _n--;

	if (_n >= 0 && _n < n)
	{
		cout << endl;
		cout << "Enter new event name: ";
		cin >> intials.name;

		cout << "Enter new event date (YYYY/MM/DD HH/MM)..." << endl;
		cout << "Year: "; cin >> date.year;
		cout << "Month: "; cin >> date.month;
		cout << "Day: "; cin >> date.day;
		cout << "Hour: "; cin >> date.hour;
		cout << "Min: "; cin >> date.min;

		d[_n].EventEntry(intials, date);
	}
	else
		cout << "ERROR!!!" << endl;
}

//Копирование события
void Copy(Event* d_n, Event* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

//Добавить событие
void AddEvent(Event* (&d), int& n)
{
	Event_name initials;
	Date date;
	Event* buf = new Event[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Event[new_size];

	Copy(d, buf, size);

	cout << endl;

	cout << "Enter new event name: ";
	cin >> initials.name;

	cout << "Enter new  event date(YYYY/MM/DD HH/MM)..."<<endl;
	cout << "Year: "; cin >> date.year;
	cout << "Month: "; cin >> date.month;
	cout << "Day: "; cin >> date.day;
	cout << "Hour: "; cin >> date.hour;
	cout << "Min: "; cin >> date.min;

	d[size].EventEntry(initials, date);
	cout << "Successfully!!!"<<endl;

	delete[] buf;

}

//Удалить событие
void DeleteEvent(Event* (&d), int& n)
{
	int _n;
	Event* buf = new Event[n];

	cout << "Enter num of event (1-" << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Event[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != n)
			{
				d[q] = buf[i];
				q++;
			}
		}
		cout << "Successfully!!!" << endl;
		delete[] buf;
	}
	else
		cout << "ERROR!!!" << endl;
}

//Сохранить событие в файл
void SaveEvent(Event* d, int n, string filename)
{
	ofstream record(filename);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << " " << d[i].GetInitials().name << endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << d[i].GetDate().year << d[i].GetDate().hour << d[i].GetDate().min << endl;

			if (i < n - 1)
				record << endl;
		}

	}
	else
	{
		cout << "ERROR!!!" << endl;
	}

		cout << "Successfully!!!" << endl;
		record.close();
}
