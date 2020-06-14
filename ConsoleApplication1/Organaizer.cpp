#include "Fuctions.h"

int _stateMenu;
void Menu()
{
	cout <<"\t"<<"Welcome in your organaizer!!!: " << endl
		<< "1. Create to-do list" << endl
		<< "2. View list" << endl
		<< "3. Edit" << endl
		<< "4. Add event" << endl
		<< "5. Delete event" << endl
		<< "6. Save list in file" << endl
		<< "0. Exit" << endl
		<< "Your choise: "; cin >> _stateMenu;
}

int main()
{


	Menu();
	int _actions;
	string fileName;

	int _size = 0;
	Event* d = new Event[_size];

	while (_stateMenu != 0)
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			EventEntry(d, _size);
			
			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (_size != 0)
				Print(d, _size);
			else cout << "ERROR!!!"<<endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (_size != 0)
				EventChange(d, _size);
			else cout << "ERROR!!!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");

			if (_size != 0)
				AddEvent(d, _size);
			else cout << "ERROR!!!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (_size != 0)
				DeleteEvent(d, _size);
			else cout << "ERROR!!!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

			


		case 6:
			system("cls");

			if (_size != 0)
				SaveEvent(d, _size, "Out.txt");
			else cout << "ERROR!!!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;






		}


}

