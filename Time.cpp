#include "Time.h"
Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void Time::changePlusPlus() {
	char c; unsigned int user_value;
	do
	{
		system("cls");
		cout << *this << endl;
		cout << "Что хотите увеличить, босс?" << endl;
		cout << "[1] Часы" << endl;
		cout << "[2] Минуты" << endl;
		cout << "[3] Секунды" << endl;
		cout << "[4] Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> c;
		switch (c)
		{
		case '1':
			system("cls");
			cout << *this << endl;
			cout << "На сколько увеличить, босс?" << endl << "=> ";
			cin >> user_value;
			hours = (hours + user_value) % 12;
			cout << "Готово, босс! Текущий час теперь: " << hours << endl;
			system("pause");
			break;
		case '2':
			system("cls");
			cout << *this << endl;
			cout << "На сколько увеличить, босс?" << endl << "=> ";
			cin >> user_value;
			minutes = (minutes + user_value) % 60;
			cout << "Готово, босс! Текущее значение минут теперь: " << minutes << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			cout << *this << endl;
			cout << "На сколько увеличить, босс?" << endl << "=> ";
			cin >> user_value;
			seconds = (seconds + user_value) % 60;
			cout << "Готово, босс! Текущее значение секунд теперь: " << seconds << endl;
			system("pause");
			break;
		case '4':
			c = '4';
		default:
			break;
		}
	} while (c != '4');
}

void Time::changeMinusMinus() {
	char c; unsigned int user_value;
	do
	{
		system("cls");
		cout << *this << endl;
		cout << "Что хотите уменьшить, босс?" << endl;
		cout << "[1] Часы" << endl;
		cout << "[2] Минуты" << endl;
		cout << "[3] Секунды" << endl;
		cout << "[4] Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> c;
		switch (c)
		{
		case '1':
			system("cls");
			cout << *this << endl;
			cout << "На сколько уменьшить, босс?" << endl << "=> ";
			cin >> user_value;
			if ((!hours) || (hours < user_value)) {
				cout << "Часы не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				hours = (hours - user_value) % 12;
			}
			cout << "Готово, босс! Текущий час теперь: " << hours << endl;
			system("pause");
			break;
		case '2':
			system("cls");
			cout << *this << endl;
			cout << "На сколько уменьшить, босс?" << endl << "=> ";
			cin >> user_value;
			if ((!minutes) || (minutes < user_value)) {
				cout << "Минуты не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				minutes = (minutes - user_value) % 60;
			}
			cout << "Готово, босс! Текущее значение минут теперь: " << minutes << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			cout << *this << endl;
			cout << "На сколько уменьшить, босс?" << endl << "=> ";
			cin >> user_value;
			if ((!seconds) || (seconds < user_value)) {
				cout << "Секунды не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				seconds = (seconds - user_value) % 60;
			}
			cout << "Готово, босс! Текущее значение секунд теперь: " << seconds << endl;
			system("pause");
			break;
		case '4':
			c = '4';
		default:
			break;
		}
	} while (c != '4');
}

Time Time::operator++(int) {
	changePlusPlus();
	return *this;
}

Time Time::operator--(int) {
	changeMinusMinus();
	return *this;
}

Time& operator++(Time& time) {
	char c; int user_value;
	do
	{
		system("cls");
		cout << time << endl;
		cout << "Что хотите увеличить, босс?" << endl;
		cout << "[1] Часы" << endl;
		cout << "[2] Минуты" << endl;
		cout << "[3] Секунды" << endl;
		cout << "[4] Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> c;
		switch (c)
		{
		case '1':
			system("cls");
			cout << time << endl;
			time.hours = (time.hours + 1) % 12;
			cout << "Готово, босс! Текущий час теперь: " << time.hours << endl;
			system("pause");
			break;
		case '2':
			system("cls");
			cout << time << endl;
			time.minutes = (time.minutes + 1) % 60;
			cout << "Готово, босс! Текущее значение минут теперь: " << time.minutes << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			cout << time << endl;
			time.seconds = (time.seconds + 1) % 60;
			cout << "Готово, босс! Текущее значение секунд теперь: " << time.seconds << endl;
			system("pause");
			break;
		case '4':
			c = '4';
		default:
			break;
		}
	} while (c != '4');
	return time;
}

Time& operator--(Time& time) {
	char c; int user_value;
	do
	{
		system("cls");
		cout << time << endl;
		cout << "Что хотите уменьшить, босс?" << endl;
		cout << "[1] Часы" << endl;
		cout << "[2] Минуты" << endl;
		cout << "[3] Секунды" << endl;
		cout << "[4] Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> c;
		switch (c)
		{
		case '1':
			system("cls");
			cout << time << endl;
			if (!time.hours) {
				cout << "Часы не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				time.hours = (time.hours - 1) % 12;
			}
			cout << "Готово, босс! Текущий час теперь: " << time.hours << endl;
			system("pause");
			break;
		case '2':
			system("cls");
			cout << time << endl;
			if (!time.minutes) {
				cout << "Минуты не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				time.minutes = (time.minutes - 1) % 60;
			}
			cout << "Готово, босс! Текущее значение минут теперь: " << time.minutes << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			cout << time << endl;
			if (!time.seconds) {
				cout << "Секунды не могут быть отрицательными." << endl;
				system("pause");
				break;
			}
			else
			{
				time.seconds = (time.seconds - 1) % 60;
			}
			cout << "Готово, босс! Текущее значение секунд теперь: " << time.seconds << endl;
			system("pause");
			break;
		case '4':
			c = '4';
		default:
			break;
		}
	} while (c != '4');
	return time;
}

ostream& operator << (ostream& s, Time& time)
{
	return cout << "Часы: " << time.hours << " Минуты: " << time.minutes << " Секунды: " << time.seconds;
}